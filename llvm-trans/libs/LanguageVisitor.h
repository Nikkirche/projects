
// Generated from Language.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "LanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LanguageParser.
 */
class  LanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LanguageParser.
   */
    virtual std::any visitProgram(LanguageParser::ProgramContext *context) = 0;

    virtual std::any visitSimple_dec(LanguageParser::Simple_decContext *context) = 0;

    virtual std::any visitRoutine_dec(LanguageParser::Routine_decContext *context) = 0;

    virtual std::any visitVar_dec(LanguageParser::Var_decContext *context) = 0;

    virtual std::any visitType(LanguageParser::TypeContext *context) = 0;

    virtual std::any visitArr_type(LanguageParser::Arr_typeContext *context) = 0;

    virtual std::any visitParameters(LanguageParser::ParametersContext *context) = 0;

    virtual std::any visitParam_dec(LanguageParser::Param_decContext *context) = 0;

    virtual std::any visitBody(LanguageParser::BodyContext *context) = 0;

    virtual std::any visitStatement(LanguageParser::StatementContext *context) = 0;

    virtual std::any visitReturn_statement(LanguageParser::Return_statementContext *context) = 0;

    virtual std::any visitIf_statement(LanguageParser::If_statementContext *context) = 0;

    virtual std::any visitFor_loop(LanguageParser::For_loopContext *context) = 0;

    virtual std::any visitRout_call(LanguageParser::Rout_callContext *context) = 0;

    virtual std::any visitArg(LanguageParser::ArgContext *context) = 0;

    virtual std::any visitRange(LanguageParser::RangeContext *context) = 0;

    virtual std::any visitExpr(LanguageParser::ExprContext *context) = 0;

    virtual std::any visitRel(LanguageParser::RelContext *context) = 0;

    virtual std::any visitSim(LanguageParser::SimContext *context) = 0;

    virtual std::any visitFac(LanguageParser::FacContext *context) = 0;

    virtual std::any visitSum(LanguageParser::SumContext *context) = 0;

    virtual std::any visitPrim(LanguageParser::PrimContext *context) = 0;

    virtual std::any visitMod(LanguageParser::ModContext *context) = 0;

    virtual std::any visitAssign(LanguageParser::AssignContext *context) = 0;

    virtual std::any visitPrim_type(LanguageParser::Prim_typeContext *context) = 0;


};

