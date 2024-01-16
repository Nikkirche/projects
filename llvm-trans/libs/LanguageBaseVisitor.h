
// Generated from Language.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LanguageVisitor.h"


/**
 * This class provides an empty implementation of LanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LanguageBaseVisitor : public LanguageVisitor {
public:

  virtual std::any visitProgram(LanguageParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_dec(LanguageParser::Simple_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutine_dec(LanguageParser::Routine_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_dec(LanguageParser::Var_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(LanguageParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArr_type(LanguageParser::Arr_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(LanguageParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_dec(LanguageParser::Param_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(LanguageParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(LanguageParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_statement(LanguageParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_statement(LanguageParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_loop(LanguageParser::For_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRout_call(LanguageParser::Rout_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(LanguageParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRange(LanguageParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(LanguageParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel(LanguageParser::RelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSim(LanguageParser::SimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFac(LanguageParser::FacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSum(LanguageParser::SumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrim(LanguageParser::PrimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMod(LanguageParser::ModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(LanguageParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrim_type(LanguageParser::Prim_typeContext *ctx) override {
    return visitChildren(ctx);
  }


};

