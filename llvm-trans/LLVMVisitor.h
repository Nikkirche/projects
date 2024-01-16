#include <string>
#include "antlr4-runtime.h"
#include "libs/LanguageBaseVisitor.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/TargetSelect.h"
#include "sim.h"
#include "llvm/IR/Module.h"
#include <vector>
using namespace std;
using namespace llvm;
class LLVMVisitor : LanguageBaseVisitor {
  LLVMContext context;
  bool returns = false;
  Module *module = new Module("main.prog", context);
  IRBuilder<> builder = IRBuilder(context);
  Function *currFun = nullptr;
  bool assigning = false;
  std::map<std::string, FunctionCallee> functions = std::map<std::string, FunctionCallee>();
  std::map<std::string, Value *> vars = std::map<std::string, Value *>();
  std::map<std::string, Value *> loc_vars = std::map<std::string, Value *>();
  std::vector<std::string> args_names;
  Function *mainFunc = nullptr;
  bool isAlloc = false;
  bool isGEP = false;
 public:
  Type *getType(LanguageParser::TypeContext *ctx) {
    if (ctx == nullptr) {
      return Type::getVoidTy(context);
    }
    auto s = ctx->getText();
    if (s == "integer") {
      return Type::getInt64Ty(context);
    }
    if (s.substr(0, 5) == "array") {
      auto rest = s.substr(5, s.size());
      if (rest == "integer") {
        return Type::getInt64PtrTy(context);
      }
    }
    std::cout << "error - got " << s;
    return nullptr;
  }
  Value *getValue(any a) {
    if (a.type() == typeid(Value *)) {
      return any_cast<Value *>(a);
    } else if (a.type() == typeid(long long int)) {
      return builder.getInt64(any_cast<long long int>(a));
    } else if (a.type() == typeid(CallInst *)) {
      //we call external c code so we need convert
      auto v = any_cast<CallInst *>(a);
      /* if(v->getType()->isIntegerTy()) {
         return v;
         return builder.CreateZExt(v, builder.getInt64Ty());
       }*/
      return v;
    } else if (a.type() == typeid(AllocaInst *)) {
      auto k = any_cast<AllocaInst *>(a);
      /*if(retrive) {
        return builder.CreateLoad(k->getType(),k);
      }*/
      return k;
    } else if (a.type() == typeid(LoadInst *)) {
      auto k = any_cast<LoadInst *>(a);

      return k;
    } else {
      std::cout << 1;
    }

  }

  virtual std::any visitProgram(LanguageParser::ProgramContext *ctx) override {
    Type *voidType = Type::getVoidTy(context);
    Type *int64_type = Type::getInt64Ty(context);
    ArrayRef<Type *> simSetPixelParamTypes = {int64_type,
                                              int64_type,
                                              int64_type};
    FunctionType *simSetPixelType = FunctionType::get(voidType, simSetPixelParamTypes, false);
    functions.emplace(pair("simSetPixel", module->getOrInsertFunction("simSetPixel", simSetPixelType)));
    FunctionType *simFlushType = FunctionType::get(voidType, {voidType}, false);
    functions.emplace(pair("simFlush", module->getOrInsertFunction("simFlush", simFlushType)));
    FunctionType *simRandType = FunctionType::get(int64_type, {voidType}, false);
    functions.emplace(pair("simRand", module->getOrInsertFunction("simRand", simRandType)));
    FunctionType *simAbsType = FunctionType::get(int64_type, {int64_type}, false);
    functions.emplace(pair("simAbs", module->getOrInsertFunction("simAbs", simAbsType)));
    FunctionType *initType = FunctionType::get(voidType, {voidType}, false);
    functions.emplace(pair("init", module->getOrInsertFunction("init", initType)));
    visitChildren(ctx);
    module->print(outs(), nullptr);

    outs() << "Running code"
              "...\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([&](const std::string &fnName) -> void * {
      if (fnName == "simSetPixel") {
        return reinterpret_cast<void *>(simSetPixel);
      }
      if (fnName == "simFlush") {
        return reinterpret_cast<void *>(simFlush);
      }
      if (fnName == "simAbs") {
        return reinterpret_cast<void *>(simAbs);
      }
      if (fnName == "simRand") {
        return reinterpret_cast<void *>(simRand);
      }
      if (fnName == "init") {
        return reinterpret_cast<void *>(init);
      }

      return nullptr;
    });
    outs() << ee->getErrorMessage();
    ee->finalizeObject();
    ArrayRef<GenericValue> noargs;
    GenericValue v = ee->runFunction(mainFunc, noargs);
    outs() << "Code was run.\n";
    return nullptr;
  }

  virtual std::any visitSimple_dec(LanguageParser::Simple_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutine_dec(LanguageParser::Routine_decContext *ctx) {
    returns = false;
    args_names = vector<string>();
    string name = ctx->IDENT()->getText();
    auto pars = any_cast<vector<Type *>>(visitParameters(ctx->parameters()));
    Type *ret = getType(ctx->type());
    ArrayRef<Type *> par(pars);
    auto funType = FunctionType::get(ret, {pars}, false);
    Function *func;
    if (name != "main") {
      func = Function::Create(funType, Function::PrivateLinkage, name, module);
    } else {
      func = Function::Create(funType, Function::ExternalLinkage, name, module);
      mainFunc = func;
    }
    this->functions.emplace(std::pair(name, func));
    this->functions.emplace(std::pair(name, func));
    this->functions.emplace(std::pair(name, func));
    BasicBlock *bb = BasicBlock::Create(context, "", func);
    builder.SetInsertPoint(bb);
    loc_vars.clear();
    for (int counter = 0; counter < func->arg_size(); counter++) {
      loc_vars.emplace(pair(args_names[counter], dyn_cast<Value>(func->getArg(counter))));
    }
    currFun = func;
    auto body = visitBody(ctx->body());
    if (ret == builder.getVoidTy()) {
      builder.CreateRetVoid();
    }
    return nullptr;
  }
  virtual std::any visitParam_dec(LanguageParser::Param_decContext *ctx) {
    args_names.push_back(ctx->IDENT()->getText());
    return getType(ctx->type());
  }
  virtual std::any visitParameters(LanguageParser::ParametersContext *ctx) {
    std::vector<Type *> args = std::vector<Type *>();

    for (auto i : ctx->param_dec()) {
      args.push_back(any_cast<Type *>(visitParam_dec(i)));
    }
    return args;
  }
  virtual std::any visitIf_statement(LanguageParser::If_statementContext *ctx) override {
    auto e = any_cast<Value *>(visitExpr(ctx->expr()));

    BasicBlock *bb = BasicBlock::Create(context, "", currFun);
    BasicBlock *bb1 = BasicBlock::Create(context, "", currFun);
    builder.CreateCondBr(e, bb, bb1);
    builder.SetInsertPoint(bb);
    auto t = returns;
    returns = false;
    visitBody(ctx->body(0));
    BasicBlock *bb2 = nullptr;
    if (!returns) {
      bb2 = BasicBlock::Create(context, "", currFun);
      builder.CreateBr(bb2);
    }
    builder.SetInsertPoint(bb1);
    returns = false;
    if (ctx->body().size() > 1) {
      visitBody(ctx->body(1));

      if (!returns) {
        if (bb2 == nullptr) {
          bb2 = BasicBlock::Create(context, "", currFun);
        }
        builder.CreateBr(bb2);
        builder.SetInsertPoint(bb2);
      }
    } else {
      if (bb2 == nullptr) {
        bb2 = BasicBlock::Create(context, "", currFun);
      }
      builder.CreateBr(bb2);
      builder.SetInsertPoint(bb2);
    }
    returns = t;
    return nullptr;
  }
  virtual std::any visitReturn_statement(LanguageParser::Return_statementContext *ctx) override {
    returns = true;
    return builder.CreateRet(getValue(visitExpr(ctx->expr())));
  }

  virtual std::any visitExpr(LanguageParser::ExprContext *ctx) override {
    if (ctx->children.size() == 1) {
      return visitRel(ctx->rel(0));
    }
    if (ctx->children[0]->getText() == "not" && ctx->children.size() == 2) {
      return builder.CreateNot(builder.CreateTrunc(getValue(visitRel(ctx->rel(0))),
                                 Type::getInt1Ty(context)));
    }
    auto op = ctx->children[1]->getText();
    auto left = getValue(visitRel(ctx->rel(0)));
    auto right = getValue(visitRel(ctx->rel(1)));
    if (left->getType()->isPointerTy()) {
      left = builder.CreateLoad(left->getType()->getPointerElementType(), left);
    }
    if (right->getType()->isPointerTy()) {
      right = builder.CreateLoad(right->getType()->getPointerElementType(), right);
    }
    left = builder.CreateTrunc(left, Type::getInt1Ty(context));
    right = builder.CreateTrunc(right, Type::getInt1Ty(context));
    if (op == "and") {
      return builder.CreateAnd(left, right);
    }
    if (op == "or") {
      return builder.CreateOr(left, right);
    }
    throw runtime_error("Unexpected operator " + op);
  }
  virtual std::any visitRel(LanguageParser::RelContext *ctx) override {
    if (ctx->children.size() == 1) {
      return visitSim(ctx->sim(0));
    }

    auto op = ctx->children[1]->getText();
    auto left = getValue(visitSim(ctx->sim(0)));
    auto right = getValue(visitSim(ctx->sim(1)));
    if (left->getType()->isPointerTy()) {
      left = builder.CreateLoad(left->getType()->getPointerElementType(), left);
    }
    if (right->getType()->isPointerTy()) {
      right = builder.CreateLoad(right->getType()->getPointerElementType(), right);
    }
    if (op == "<=") {
      return builder.CreateICmpSLE(left, right);
    }
    if (op == "<") {
      return builder.CreateICmpSLT(left, right);
    }
    if (op == "==") {
      return builder.CreateICmpEQ(left, right);
    }
    if (op == "!=") {
      return builder.CreateICmpNE(left, right);
    }
    if (op == ">=") {
      return builder.CreateICmpSGE(left, right);
    }
    if (op == ">") {
      return builder.CreateICmpSGT(left, right);
    }
    throw runtime_error("Unexpected operator " + op);
  }

  virtual std::any visitSim(LanguageParser::SimContext *ctx) override {
    if (ctx->children.size() == 1) {
      return visitFac(ctx->fac(0));
    }
    auto op = ctx->children[1]->getText();
    auto left = getValue(visitFac(ctx->fac(0)));
    auto right = getValue(visitFac(ctx->fac(1)));
    if (left->getType()->isPointerTy()) {
      left = builder.CreateLoad(left->getType()->getPointerElementType(), left);
    }
    if (right->getType()->isPointerTy()) {
      right = builder.CreateLoad(right->getType()->getPointerElementType(), right);
    }
    if (op == "+") {
      return builder.CreateAdd(left, right);
    }
    if (op == "-") {
      return builder.CreateSub(left, right);
    }
    throw runtime_error("Unexpected operator " + op);
  }

  virtual std::any visitFac(LanguageParser::FacContext *ctx) override {
    if (ctx->children.size() == 1) {
      return visitSum(ctx->sum(0));
    }
    auto op = ctx->children[1]->getText();
    if (op == "*") {
      return builder.CreateMul(getValue(visitSum(ctx->sum(0))), getValue(visitSum(ctx->sum(1))));
    }
    if (op == "/") {
      return builder.CreateSDiv(getValue(visitSum(ctx->sum(0))), getValue(visitSum(ctx->sum(1))));
    }
    if (op == "%") {
      return builder.CreateSRem(getValue(visitSum(ctx->sum(0))), getValue(visitSum(ctx->sum(1))));
    }
    throw runtime_error("Unexpected operator " + op);
  }

  virtual std::any visitSum(LanguageParser::SumContext *ctx) override {
    if (ctx->prim() != nullptr) {
      return visitPrim(ctx->prim());
    }
    return visitExpr(ctx->expr());
  }

  virtual std::any visitPrim(LanguageParser::PrimContext *ctx) override {
    auto integ = ctx->INT();
    if (integ != nullptr) {
      return std::stoll(integ->getText());
    }
    auto val = ctx->mod();
    if (val != nullptr) {
      return visitMod(val);
    }
    if (ctx->rout_call() != nullptr) {
      return visitRout_call(ctx->rout_call());
    }
    return visitChildren(ctx);
  }

  virtual std::any visitMod(LanguageParser::ModContext *ctx) override {
    if (ctx->IDENT() != nullptr) {
      auto key = ctx->IDENT()->getText();
      if (ctx->expr() != nullptr) {
        auto v = getValue(visitExpr(ctx->expr()));
        auto t = loc_vars.at(ctx->IDENT()->getText());
        Value *k = t;
        if (v->getType()->isPointerTy()) {
          v = builder.CreateLoad(v->getType()->getPointerElementType(), v);
        }
        if (t->getType()->isPointerTy() && t->getType()->getPointerElementType()->isPointerTy()) {
          k = builder.CreateLoad(t->getType()->getPointerElementType(), t);
        }
        auto r = builder.CreateInBoundsGEP(builder.getInt64Ty(), k, v);

        isGEP = true;
        if (!assigning) {
          return builder.CreateLoad(Type::getInt64Ty(context), r);
        }
        return r;
      }
      if (loc_vars.find(key) != loc_vars.end()) {
        auto k = loc_vars.at(key);
        if (assigning) {
          //k = builder.CreateLoad(k->getType()->getPointerElementType(),k);
          //module->print(outs(), nullptr);
        }
        return k;
      } else {
        return vars.at(key);
      }
    }
    if (ctx->expr() != nullptr) {
      auto v = getValue(visitExpr(ctx->expr()));
      auto r = builder.CreateAlloca(builder.getInt64Ty(), v);
      isAlloc = true;
      return r;
    }

    return visitChildren(ctx);
  }
  virtual std::any visitVar_dec(LanguageParser::Var_decContext *ctx) override {
    auto currType = getType(ctx->type());
    auto v = getValue(visitExpr(ctx->expr()));
    if (builder.GetInsertBlock() != nullptr && !isAlloc) {
      auto t = v->getType();
      if (t->isPointerTy() && t->getPointerElementType()->isPointerTy()) {
        v = builder.CreateLoad(t->getPointerElementType(), v);
      }
      auto a = builder.CreateAlloca(currType);
      builder.CreateStore(v, a);
      //auto r = builder.CreateLoad(currType,a);
      loc_vars.emplace(ctx->IDENT()->getText(), a);
    } else {
      isAlloc = false;
      if (builder.GetInsertBlock() == nullptr) {
        vars.emplace(ctx->IDENT()->getText(), v);
      } else {
        loc_vars.emplace(ctx->IDENT()->getText(), v);
      }
    }
    return nullptr;
  }
  virtual std::any visitFor_loop(LanguageParser::For_loopContext *ctx) override {
    auto st = getValue(visitExpr(ctx->range()->expr(0)));
    auto end = getValue(visitExpr(ctx->range()->expr(1)));
    auto ind = builder.CreateAlloca(Type::getInt64Ty(context));
    builder.CreateStore(st, ind);
    auto var_name = ctx->IDENT()->getText();
    BasicBlock *cond = BasicBlock::Create(context, "", currFun);
    BasicBlock *iter = BasicBlock::Create(context, "", currFun);
    BasicBlock *body = BasicBlock::Create(context, "", currFun);
    BasicBlock *res = BasicBlock::Create(context, "", currFun);
    builder.CreateBr(cond);
    builder.SetInsertPoint(cond);
    auto tmp = builder.CreateLoad(Type::getInt64Ty(context), ind);
    auto cmp = builder.CreateICmpSLT(tmp, end);
    builder.CreateCondBr(cmp, body, res);
    builder.SetInsertPoint(iter);
    auto tind = builder.CreateAdd(tmp, builder.getInt64(1));
    builder.CreateStore(tind, ind);
    loc_vars[var_name] = tmp;
    builder.CreateBr(cond);
    builder.SetInsertPoint(body);
    visitBody(ctx->body());
    builder.CreateBr(iter);
    builder.SetInsertPoint(res);
    loc_vars.erase(var_name);
    return nullptr;
  }
  virtual std::any visitRout_call(LanguageParser::Rout_callContext *ctx) override {
    auto name = ctx->IDENT()->getText();
    auto v = vector<Value *>();
    for (auto a : ctx->arg()) {
      auto x = getValue(visitArg(a));
      auto t = x->getType();
      if (t->isPointerTy() && t->getPointerElementType()->isPointerTy()) {
        v.push_back(builder.CreateLoad(t->getPointerElementType(), x));
      } else {
        v.push_back(x);
      }
    }
    auto c = builder.CreateCall(functions.at(name), ArrayRef(v));
    return c;
  }
  virtual std::any visitArg(LanguageParser::ArgContext *ctx) override {
    if (ctx->expr() != nullptr) {
      return visitExpr(ctx->expr());
    } else {
      return visitRout_call(ctx->rout_call());
    }
  }
  virtual std::any visitAssign(LanguageParser::AssignContext *ctx) override {
    auto e = getValue(visitExpr(ctx->expr()));
    assigning = true;
    isGEP = false;
    auto m = ctx->mod();
    auto v = getValue(visitMod(m));
    assigning = false;
    if (isGEP) {
      isGEP = false;
      builder.CreateStore(e, v);
      //throw nullptr;
      return nullptr;
    }
    auto t = e->getType();

    auto a = loc_vars[m->getText()];
    if (t->isPointerTy() && t->getPointerElementType()->isPointerTy()) {
      e = builder.CreateLoad(v->getType()->getPointerElementType(), e);
    }
    builder.CreateStore(e, a);
    //auto r =  builder.CreateLoad(v->getType(),a);
    // return r ;
    return nullptr;

  }
};

