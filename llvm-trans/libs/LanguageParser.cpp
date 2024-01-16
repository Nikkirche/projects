
// Generated from Language.g4 by ANTLR 4.13.0


#include "LanguageVisitor.h"

#include "LanguageParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LanguageParserStaticData final {
  LanguageParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LanguageParserStaticData(const LanguageParserStaticData&) = delete;
  LanguageParserStaticData(LanguageParserStaticData&&) = delete;
  LanguageParserStaticData& operator=(const LanguageParserStaticData&) = delete;
  LanguageParserStaticData& operator=(LanguageParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag languageParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LanguageParserStaticData *languageParserStaticData = nullptr;

void languageParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (languageParserStaticData != nullptr) {
    return;
  }
#else
  assert(languageParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LanguageParserStaticData>(
    std::vector<std::string>{
      "program", "simple_dec", "routine_dec", "var_dec", "type", "arr_type", 
      "parameters", "param_dec", "body", "statement", "return_statement", 
      "if_statement", "for_loop", "rout_call", "arg", "range", "expr", "rel", 
      "sim", "fac", "sum", "prim", "mod", "assign", "prim_type"
    },
    std::vector<std::string>{
      "", "'routine'", "':'", "'is'", "'end'", "'var'", "'array'", "'('", 
      "','", "')'", "'return'", "'if'", "'then'", "'else'", "'for'", "'loop'", 
      "'in'", "'..'", "'and'", "'or'", "'not'", "'<'", "'<='", "'=='", "'!='", 
      "'>='", "'>'", "'+'", "'-'", "'*'", "'%'", "'/'", "'true'", "'false'", 
      "'['", "']'", "':='", "'integer'", "'boolean'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "WS", "IDENT", "INT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,236,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,5,0,53,8,0,10,0,12,0,56,9,0,
  	1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,3,4,87,8,4,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,3,6,96,8,6,1,6,1,6,1,6,1,6,3,6,102,8,6,1,7,1,7,1,7,
  	1,7,1,8,1,8,1,8,5,8,111,8,8,10,8,12,8,114,9,8,1,9,1,9,1,9,1,9,3,9,120,
  	8,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,3,11,139,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,156,8,13,10,13,12,13,159,
  	9,13,1,13,1,13,3,13,163,8,13,1,14,1,14,3,14,167,8,14,1,15,1,15,1,15,1,
  	15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,181,8,16,1,17,1,17,1,
  	17,1,17,1,17,3,17,188,8,17,1,18,1,18,1,18,1,18,1,18,3,18,195,8,18,1,19,
  	1,19,1,19,1,19,1,19,3,19,202,8,19,1,20,1,20,1,20,1,20,1,20,3,20,209,8,
  	20,1,21,1,21,1,21,1,21,1,21,3,21,216,8,21,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,3,22,228,8,22,1,23,1,23,1,23,1,23,1,24,1,24,1,
  	24,0,0,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
  	44,46,48,0,5,1,0,18,19,1,0,21,26,1,0,27,28,1,0,29,31,1,0,37,38,238,0,
  	54,1,0,0,0,2,57,1,0,0,0,4,75,1,0,0,0,6,77,1,0,0,0,8,86,1,0,0,0,10,88,
  	1,0,0,0,12,101,1,0,0,0,14,103,1,0,0,0,16,112,1,0,0,0,18,119,1,0,0,0,20,
  	121,1,0,0,0,22,138,1,0,0,0,24,140,1,0,0,0,26,162,1,0,0,0,28,166,1,0,0,
  	0,30,168,1,0,0,0,32,180,1,0,0,0,34,187,1,0,0,0,36,194,1,0,0,0,38,201,
  	1,0,0,0,40,208,1,0,0,0,42,215,1,0,0,0,44,227,1,0,0,0,46,229,1,0,0,0,48,
  	233,1,0,0,0,50,53,3,2,1,0,51,53,3,4,2,0,52,50,1,0,0,0,52,51,1,0,0,0,53,
  	56,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,1,1,0,0,0,56,54,1,0,0,0,57,
  	58,3,6,3,0,58,3,1,0,0,0,59,60,5,1,0,0,60,61,5,40,0,0,61,62,3,12,6,0,62,
  	63,5,2,0,0,63,64,3,8,4,0,64,65,5,3,0,0,65,66,3,16,8,0,66,67,5,4,0,0,67,
  	76,1,0,0,0,68,69,5,1,0,0,69,70,5,40,0,0,70,71,3,12,6,0,71,72,5,3,0,0,
  	72,73,3,16,8,0,73,74,5,4,0,0,74,76,1,0,0,0,75,59,1,0,0,0,75,68,1,0,0,
  	0,76,5,1,0,0,0,77,78,5,5,0,0,78,79,5,40,0,0,79,80,5,2,0,0,80,81,3,8,4,
  	0,81,82,5,3,0,0,82,83,3,32,16,0,83,7,1,0,0,0,84,87,3,48,24,0,85,87,3,
  	10,5,0,86,84,1,0,0,0,86,85,1,0,0,0,87,9,1,0,0,0,88,89,5,6,0,0,89,90,3,
  	8,4,0,90,11,1,0,0,0,91,92,5,7,0,0,92,95,3,14,7,0,93,94,5,8,0,0,94,96,
  	3,14,7,0,95,93,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,98,5,9,0,0,98,102,
  	1,0,0,0,99,100,5,7,0,0,100,102,5,9,0,0,101,91,1,0,0,0,101,99,1,0,0,0,
  	102,13,1,0,0,0,103,104,5,40,0,0,104,105,5,2,0,0,105,106,3,8,4,0,106,15,
  	1,0,0,0,107,111,3,2,1,0,108,111,3,18,9,0,109,111,3,20,10,0,110,107,1,
  	0,0,0,110,108,1,0,0,0,110,109,1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,
  	112,113,1,0,0,0,113,17,1,0,0,0,114,112,1,0,0,0,115,120,3,46,23,0,116,
  	120,3,22,11,0,117,120,3,24,12,0,118,120,3,26,13,0,119,115,1,0,0,0,119,
  	116,1,0,0,0,119,117,1,0,0,0,119,118,1,0,0,0,120,19,1,0,0,0,121,122,5,
  	10,0,0,122,123,3,32,16,0,123,21,1,0,0,0,124,125,5,11,0,0,125,126,3,32,
  	16,0,126,127,5,12,0,0,127,128,3,16,8,0,128,129,5,13,0,0,129,130,3,16,
  	8,0,130,131,5,4,0,0,131,139,1,0,0,0,132,133,5,11,0,0,133,134,3,32,16,
  	0,134,135,5,12,0,0,135,136,3,16,8,0,136,137,5,4,0,0,137,139,1,0,0,0,138,
  	124,1,0,0,0,138,132,1,0,0,0,139,23,1,0,0,0,140,141,5,14,0,0,141,142,5,
  	40,0,0,142,143,3,30,15,0,143,144,5,15,0,0,144,145,3,16,8,0,145,146,5,
  	4,0,0,146,25,1,0,0,0,147,148,5,40,0,0,148,149,5,7,0,0,149,163,5,9,0,0,
  	150,151,5,40,0,0,151,152,5,7,0,0,152,157,3,28,14,0,153,154,5,8,0,0,154,
  	156,3,28,14,0,155,153,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,
  	1,0,0,0,158,160,1,0,0,0,159,157,1,0,0,0,160,161,5,9,0,0,161,163,1,0,0,
  	0,162,147,1,0,0,0,162,150,1,0,0,0,163,27,1,0,0,0,164,167,3,26,13,0,165,
  	167,3,32,16,0,166,164,1,0,0,0,166,165,1,0,0,0,167,29,1,0,0,0,168,169,
  	5,16,0,0,169,170,3,32,16,0,170,171,5,17,0,0,171,172,3,32,16,0,172,31,
  	1,0,0,0,173,174,3,34,17,0,174,175,7,0,0,0,175,176,3,34,17,0,176,181,1,
  	0,0,0,177,178,5,20,0,0,178,181,3,34,17,0,179,181,3,34,17,0,180,173,1,
  	0,0,0,180,177,1,0,0,0,180,179,1,0,0,0,181,33,1,0,0,0,182,183,3,36,18,
  	0,183,184,7,1,0,0,184,185,3,36,18,0,185,188,1,0,0,0,186,188,3,36,18,0,
  	187,182,1,0,0,0,187,186,1,0,0,0,188,35,1,0,0,0,189,190,3,38,19,0,190,
  	191,7,2,0,0,191,192,3,38,19,0,192,195,1,0,0,0,193,195,3,38,19,0,194,189,
  	1,0,0,0,194,193,1,0,0,0,195,37,1,0,0,0,196,197,3,40,20,0,197,198,7,3,
  	0,0,198,199,3,40,20,0,199,202,1,0,0,0,200,202,3,40,20,0,201,196,1,0,0,
  	0,201,200,1,0,0,0,202,39,1,0,0,0,203,209,3,42,21,0,204,205,5,7,0,0,205,
  	206,3,32,16,0,206,207,5,9,0,0,207,209,1,0,0,0,208,203,1,0,0,0,208,204,
  	1,0,0,0,209,41,1,0,0,0,210,216,5,32,0,0,211,216,5,33,0,0,212,216,5,41,
  	0,0,213,216,3,44,22,0,214,216,3,26,13,0,215,210,1,0,0,0,215,211,1,0,0,
  	0,215,212,1,0,0,0,215,213,1,0,0,0,215,214,1,0,0,0,216,43,1,0,0,0,217,
  	218,5,40,0,0,218,219,5,34,0,0,219,220,3,32,16,0,220,221,5,35,0,0,221,
  	228,1,0,0,0,222,228,5,40,0,0,223,224,5,34,0,0,224,225,3,32,16,0,225,226,
  	5,35,0,0,226,228,1,0,0,0,227,217,1,0,0,0,227,222,1,0,0,0,227,223,1,0,
  	0,0,228,45,1,0,0,0,229,230,3,44,22,0,230,231,5,36,0,0,231,232,3,32,16,
  	0,232,47,1,0,0,0,233,234,7,4,0,0,234,49,1,0,0,0,20,52,54,75,86,95,101,
  	110,112,119,138,157,162,166,180,187,194,201,208,215,227
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  languageParserStaticData = staticData.release();
}

}

LanguageParser::LanguageParser(TokenStream *input) : LanguageParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LanguageParser::LanguageParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LanguageParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *languageParserStaticData->atn, languageParserStaticData->decisionToDFA, languageParserStaticData->sharedContextCache, options);
}

LanguageParser::~LanguageParser() {
  delete _interpreter;
}

const atn::ATN& LanguageParser::getATN() const {
  return *languageParserStaticData->atn;
}

std::string LanguageParser::getGrammarFileName() const {
  return "Language.g4";
}

const std::vector<std::string>& LanguageParser::getRuleNames() const {
  return languageParserStaticData->ruleNames;
}

const dfa::Vocabulary& LanguageParser::getVocabulary() const {
  return languageParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LanguageParser::getSerializedATN() const {
  return languageParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

LanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::Simple_decContext *> LanguageParser::ProgramContext::simple_dec() {
  return getRuleContexts<LanguageParser::Simple_decContext>();
}

LanguageParser::Simple_decContext* LanguageParser::ProgramContext::simple_dec(size_t i) {
  return getRuleContext<LanguageParser::Simple_decContext>(i);
}

std::vector<LanguageParser::Routine_decContext *> LanguageParser::ProgramContext::routine_dec() {
  return getRuleContexts<LanguageParser::Routine_decContext>();
}

LanguageParser::Routine_decContext* LanguageParser::ProgramContext::routine_dec(size_t i) {
  return getRuleContext<LanguageParser::Routine_decContext>(i);
}


size_t LanguageParser::ProgramContext::getRuleIndex() const {
  return LanguageParser::RuleProgram;
}


std::any LanguageParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ProgramContext* LanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, LanguageParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LanguageParser::T__0

    || _la == LanguageParser::T__4) {
      setState(52);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LanguageParser::T__4: {
          setState(50);
          simple_dec();
          break;
        }

        case LanguageParser::T__0: {
          setState(51);
          routine_dec();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_decContext ------------------------------------------------------------------

LanguageParser::Simple_decContext::Simple_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::Var_decContext* LanguageParser::Simple_decContext::var_dec() {
  return getRuleContext<LanguageParser::Var_decContext>(0);
}


size_t LanguageParser::Simple_decContext::getRuleIndex() const {
  return LanguageParser::RuleSimple_dec;
}


std::any LanguageParser::Simple_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitSimple_dec(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Simple_decContext* LanguageParser::simple_dec() {
  Simple_decContext *_localctx = _tracker.createInstance<Simple_decContext>(_ctx, getState());
  enterRule(_localctx, 2, LanguageParser::RuleSimple_dec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    var_dec();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Routine_decContext ------------------------------------------------------------------

LanguageParser::Routine_decContext::Routine_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::Routine_decContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

LanguageParser::ParametersContext* LanguageParser::Routine_decContext::parameters() {
  return getRuleContext<LanguageParser::ParametersContext>(0);
}

LanguageParser::TypeContext* LanguageParser::Routine_decContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}

LanguageParser::BodyContext* LanguageParser::Routine_decContext::body() {
  return getRuleContext<LanguageParser::BodyContext>(0);
}


size_t LanguageParser::Routine_decContext::getRuleIndex() const {
  return LanguageParser::RuleRoutine_dec;
}


std::any LanguageParser::Routine_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitRoutine_dec(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Routine_decContext* LanguageParser::routine_dec() {
  Routine_decContext *_localctx = _tracker.createInstance<Routine_decContext>(_ctx, getState());
  enterRule(_localctx, 4, LanguageParser::RuleRoutine_dec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      match(LanguageParser::T__0);
      setState(60);
      match(LanguageParser::IDENT);
      setState(61);
      parameters();
      setState(62);
      match(LanguageParser::T__1);
      setState(63);
      type();
      setState(64);
      match(LanguageParser::T__2);
      setState(65);
      body();
      setState(66);
      match(LanguageParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      match(LanguageParser::T__0);
      setState(69);
      match(LanguageParser::IDENT);
      setState(70);
      parameters();
      setState(71);
      match(LanguageParser::T__2);
      setState(72);
      body();
      setState(73);
      match(LanguageParser::T__3);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_decContext ------------------------------------------------------------------

LanguageParser::Var_decContext::Var_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::Var_decContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

LanguageParser::TypeContext* LanguageParser::Var_decContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}

LanguageParser::ExprContext* LanguageParser::Var_decContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::Var_decContext::getRuleIndex() const {
  return LanguageParser::RuleVar_dec;
}


std::any LanguageParser::Var_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitVar_dec(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Var_decContext* LanguageParser::var_dec() {
  Var_decContext *_localctx = _tracker.createInstance<Var_decContext>(_ctx, getState());
  enterRule(_localctx, 6, LanguageParser::RuleVar_dec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(LanguageParser::T__4);
    setState(78);
    match(LanguageParser::IDENT);
    setState(79);
    match(LanguageParser::T__1);
    setState(80);
    type();
    setState(81);
    match(LanguageParser::T__2);
    setState(82);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LanguageParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::Prim_typeContext* LanguageParser::TypeContext::prim_type() {
  return getRuleContext<LanguageParser::Prim_typeContext>(0);
}

LanguageParser::Arr_typeContext* LanguageParser::TypeContext::arr_type() {
  return getRuleContext<LanguageParser::Arr_typeContext>(0);
}


size_t LanguageParser::TypeContext::getRuleIndex() const {
  return LanguageParser::RuleType;
}


std::any LanguageParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::TypeContext* LanguageParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 8, LanguageParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LanguageParser::T__36:
      case LanguageParser::T__37: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        prim_type();
        break;
      }

      case LanguageParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        arr_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arr_typeContext ------------------------------------------------------------------

LanguageParser::Arr_typeContext::Arr_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::TypeContext* LanguageParser::Arr_typeContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}


size_t LanguageParser::Arr_typeContext::getRuleIndex() const {
  return LanguageParser::RuleArr_type;
}


std::any LanguageParser::Arr_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitArr_type(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Arr_typeContext* LanguageParser::arr_type() {
  Arr_typeContext *_localctx = _tracker.createInstance<Arr_typeContext>(_ctx, getState());
  enterRule(_localctx, 10, LanguageParser::RuleArr_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(LanguageParser::T__5);
    setState(89);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

LanguageParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::Param_decContext *> LanguageParser::ParametersContext::param_dec() {
  return getRuleContexts<LanguageParser::Param_decContext>();
}

LanguageParser::Param_decContext* LanguageParser::ParametersContext::param_dec(size_t i) {
  return getRuleContext<LanguageParser::Param_decContext>(i);
}


size_t LanguageParser::ParametersContext::getRuleIndex() const {
  return LanguageParser::RuleParameters;
}


std::any LanguageParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ParametersContext* LanguageParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 12, LanguageParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      match(LanguageParser::T__6);
      setState(92);
      param_dec();
      setState(95);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LanguageParser::T__7) {
        setState(93);
        match(LanguageParser::T__7);
        setState(94);
        param_dec();
      }
      setState(97);
      match(LanguageParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      match(LanguageParser::T__6);
      setState(100);
      match(LanguageParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_decContext ------------------------------------------------------------------

LanguageParser::Param_decContext::Param_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::Param_decContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

LanguageParser::TypeContext* LanguageParser::Param_decContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}


size_t LanguageParser::Param_decContext::getRuleIndex() const {
  return LanguageParser::RuleParam_dec;
}


std::any LanguageParser::Param_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitParam_dec(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Param_decContext* LanguageParser::param_dec() {
  Param_decContext *_localctx = _tracker.createInstance<Param_decContext>(_ctx, getState());
  enterRule(_localctx, 14, LanguageParser::RuleParam_dec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(LanguageParser::IDENT);
    setState(104);
    match(LanguageParser::T__1);
    setState(105);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

LanguageParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::Simple_decContext *> LanguageParser::BodyContext::simple_dec() {
  return getRuleContexts<LanguageParser::Simple_decContext>();
}

LanguageParser::Simple_decContext* LanguageParser::BodyContext::simple_dec(size_t i) {
  return getRuleContext<LanguageParser::Simple_decContext>(i);
}

std::vector<LanguageParser::StatementContext *> LanguageParser::BodyContext::statement() {
  return getRuleContexts<LanguageParser::StatementContext>();
}

LanguageParser::StatementContext* LanguageParser::BodyContext::statement(size_t i) {
  return getRuleContext<LanguageParser::StatementContext>(i);
}

std::vector<LanguageParser::Return_statementContext *> LanguageParser::BodyContext::return_statement() {
  return getRuleContexts<LanguageParser::Return_statementContext>();
}

LanguageParser::Return_statementContext* LanguageParser::BodyContext::return_statement(size_t i) {
  return getRuleContext<LanguageParser::Return_statementContext>(i);
}


size_t LanguageParser::BodyContext::getRuleIndex() const {
  return LanguageParser::RuleBody;
}


std::any LanguageParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::BodyContext* LanguageParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 16, LanguageParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1116691516448) != 0)) {
      setState(110);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LanguageParser::T__4: {
          setState(107);
          simple_dec();
          break;
        }

        case LanguageParser::T__10:
        case LanguageParser::T__13:
        case LanguageParser::T__33:
        case LanguageParser::IDENT: {
          setState(108);
          statement();
          break;
        }

        case LanguageParser::T__9: {
          setState(109);
          return_statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

LanguageParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::AssignContext* LanguageParser::StatementContext::assign() {
  return getRuleContext<LanguageParser::AssignContext>(0);
}

LanguageParser::If_statementContext* LanguageParser::StatementContext::if_statement() {
  return getRuleContext<LanguageParser::If_statementContext>(0);
}

LanguageParser::For_loopContext* LanguageParser::StatementContext::for_loop() {
  return getRuleContext<LanguageParser::For_loopContext>(0);
}

LanguageParser::Rout_callContext* LanguageParser::StatementContext::rout_call() {
  return getRuleContext<LanguageParser::Rout_callContext>(0);
}


size_t LanguageParser::StatementContext::getRuleIndex() const {
  return LanguageParser::RuleStatement;
}


std::any LanguageParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::StatementContext* LanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, LanguageParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      assign();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      if_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(117);
      for_loop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(118);
      rout_call();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

LanguageParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::ExprContext* LanguageParser::Return_statementContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::Return_statementContext::getRuleIndex() const {
  return LanguageParser::RuleReturn_statement;
}


std::any LanguageParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Return_statementContext* LanguageParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, LanguageParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(LanguageParser::T__9);
    setState(122);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

LanguageParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::ExprContext* LanguageParser::If_statementContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}

std::vector<LanguageParser::BodyContext *> LanguageParser::If_statementContext::body() {
  return getRuleContexts<LanguageParser::BodyContext>();
}

LanguageParser::BodyContext* LanguageParser::If_statementContext::body(size_t i) {
  return getRuleContext<LanguageParser::BodyContext>(i);
}


size_t LanguageParser::If_statementContext::getRuleIndex() const {
  return LanguageParser::RuleIf_statement;
}


std::any LanguageParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::If_statementContext* LanguageParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 22, LanguageParser::RuleIf_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      match(LanguageParser::T__10);
      setState(125);
      expr();
      setState(126);
      match(LanguageParser::T__11);
      setState(127);
      body();
      setState(128);
      match(LanguageParser::T__12);
      setState(129);
      body();
      setState(130);
      match(LanguageParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(132);
      match(LanguageParser::T__10);
      setState(133);
      expr();
      setState(134);
      match(LanguageParser::T__11);
      setState(135);
      body();
      setState(136);
      match(LanguageParser::T__3);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loopContext ------------------------------------------------------------------

LanguageParser::For_loopContext::For_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::For_loopContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

LanguageParser::RangeContext* LanguageParser::For_loopContext::range() {
  return getRuleContext<LanguageParser::RangeContext>(0);
}

LanguageParser::BodyContext* LanguageParser::For_loopContext::body() {
  return getRuleContext<LanguageParser::BodyContext>(0);
}


size_t LanguageParser::For_loopContext::getRuleIndex() const {
  return LanguageParser::RuleFor_loop;
}


std::any LanguageParser::For_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitFor_loop(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::For_loopContext* LanguageParser::for_loop() {
  For_loopContext *_localctx = _tracker.createInstance<For_loopContext>(_ctx, getState());
  enterRule(_localctx, 24, LanguageParser::RuleFor_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(LanguageParser::T__13);
    setState(141);
    match(LanguageParser::IDENT);
    setState(142);
    range();
    setState(143);
    match(LanguageParser::T__14);
    setState(144);
    body();
    setState(145);
    match(LanguageParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rout_callContext ------------------------------------------------------------------

LanguageParser::Rout_callContext::Rout_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::Rout_callContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

std::vector<LanguageParser::ArgContext *> LanguageParser::Rout_callContext::arg() {
  return getRuleContexts<LanguageParser::ArgContext>();
}

LanguageParser::ArgContext* LanguageParser::Rout_callContext::arg(size_t i) {
  return getRuleContext<LanguageParser::ArgContext>(i);
}


size_t LanguageParser::Rout_callContext::getRuleIndex() const {
  return LanguageParser::RuleRout_call;
}


std::any LanguageParser::Rout_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitRout_call(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Rout_callContext* LanguageParser::rout_call() {
  Rout_callContext *_localctx = _tracker.createInstance<Rout_callContext>(_ctx, getState());
  enterRule(_localctx, 26, LanguageParser::RuleRout_call);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      match(LanguageParser::IDENT);
      setState(148);
      match(LanguageParser::T__6);
      setState(149);
      match(LanguageParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      match(LanguageParser::IDENT);
      setState(151);
      match(LanguageParser::T__6);
      setState(152);
      arg();
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LanguageParser::T__7) {
        setState(153);
        match(LanguageParser::T__7);
        setState(154);
        arg();
        setState(159);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(160);
      match(LanguageParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

LanguageParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::Rout_callContext* LanguageParser::ArgContext::rout_call() {
  return getRuleContext<LanguageParser::Rout_callContext>(0);
}

LanguageParser::ExprContext* LanguageParser::ArgContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::ArgContext::getRuleIndex() const {
  return LanguageParser::RuleArg;
}


std::any LanguageParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ArgContext* LanguageParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 28, LanguageParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(164);
      rout_call();
      break;
    }

    case 2: {
      setState(165);
      expr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

LanguageParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::ExprContext *> LanguageParser::RangeContext::expr() {
  return getRuleContexts<LanguageParser::ExprContext>();
}

LanguageParser::ExprContext* LanguageParser::RangeContext::expr(size_t i) {
  return getRuleContext<LanguageParser::ExprContext>(i);
}


size_t LanguageParser::RangeContext::getRuleIndex() const {
  return LanguageParser::RuleRange;
}


std::any LanguageParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::RangeContext* LanguageParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 30, LanguageParser::RuleRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(LanguageParser::T__15);
    setState(169);
    expr();
    setState(170);
    match(LanguageParser::T__16);
    setState(171);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

LanguageParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::RelContext *> LanguageParser::ExprContext::rel() {
  return getRuleContexts<LanguageParser::RelContext>();
}

LanguageParser::RelContext* LanguageParser::ExprContext::rel(size_t i) {
  return getRuleContext<LanguageParser::RelContext>(i);
}


size_t LanguageParser::ExprContext::getRuleIndex() const {
  return LanguageParser::RuleExpr;
}


std::any LanguageParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ExprContext* LanguageParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 32, LanguageParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(173);
      rel();
      setState(174);
      _la = _input->LA(1);
      if (!(_la == LanguageParser::T__17

      || _la == LanguageParser::T__18)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(175);
      rel();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      match(LanguageParser::T__19);
      setState(178);
      rel();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(179);
      rel();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelContext ------------------------------------------------------------------

LanguageParser::RelContext::RelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::SimContext *> LanguageParser::RelContext::sim() {
  return getRuleContexts<LanguageParser::SimContext>();
}

LanguageParser::SimContext* LanguageParser::RelContext::sim(size_t i) {
  return getRuleContext<LanguageParser::SimContext>(i);
}


size_t LanguageParser::RelContext::getRuleIndex() const {
  return LanguageParser::RuleRel;
}


std::any LanguageParser::RelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitRel(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::RelContext* LanguageParser::rel() {
  RelContext *_localctx = _tracker.createInstance<RelContext>(_ctx, getState());
  enterRule(_localctx, 34, LanguageParser::RuleRel);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(182);
      sim();
      setState(183);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132120576) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(184);
      sim();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(186);
      sim();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimContext ------------------------------------------------------------------

LanguageParser::SimContext::SimContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::FacContext *> LanguageParser::SimContext::fac() {
  return getRuleContexts<LanguageParser::FacContext>();
}

LanguageParser::FacContext* LanguageParser::SimContext::fac(size_t i) {
  return getRuleContext<LanguageParser::FacContext>(i);
}


size_t LanguageParser::SimContext::getRuleIndex() const {
  return LanguageParser::RuleSim;
}


std::any LanguageParser::SimContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitSim(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::SimContext* LanguageParser::sim() {
  SimContext *_localctx = _tracker.createInstance<SimContext>(_ctx, getState());
  enterRule(_localctx, 36, LanguageParser::RuleSim);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(189);
      fac();
      setState(190);
      _la = _input->LA(1);
      if (!(_la == LanguageParser::T__26

      || _la == LanguageParser::T__27)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(191);
      fac();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(193);
      fac();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FacContext ------------------------------------------------------------------

LanguageParser::FacContext::FacContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LanguageParser::SumContext *> LanguageParser::FacContext::sum() {
  return getRuleContexts<LanguageParser::SumContext>();
}

LanguageParser::SumContext* LanguageParser::FacContext::sum(size_t i) {
  return getRuleContext<LanguageParser::SumContext>(i);
}


size_t LanguageParser::FacContext::getRuleIndex() const {
  return LanguageParser::RuleFac;
}


std::any LanguageParser::FacContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitFac(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::FacContext* LanguageParser::fac() {
  FacContext *_localctx = _tracker.createInstance<FacContext>(_ctx, getState());
  enterRule(_localctx, 38, LanguageParser::RuleFac);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(196);
      sum();
      setState(197);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3758096384) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(198);
      sum();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(200);
      sum();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SumContext ------------------------------------------------------------------

LanguageParser::SumContext::SumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::PrimContext* LanguageParser::SumContext::prim() {
  return getRuleContext<LanguageParser::PrimContext>(0);
}

LanguageParser::ExprContext* LanguageParser::SumContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::SumContext::getRuleIndex() const {
  return LanguageParser::RuleSum;
}


std::any LanguageParser::SumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitSum(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::SumContext* LanguageParser::sum() {
  SumContext *_localctx = _tracker.createInstance<SumContext>(_ctx, getState());
  enterRule(_localctx, 40, LanguageParser::RuleSum);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LanguageParser::T__31:
      case LanguageParser::T__32:
      case LanguageParser::T__33:
      case LanguageParser::IDENT:
      case LanguageParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(203);
        prim();
        break;
      }

      case LanguageParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(204);
        match(LanguageParser::T__6);
        setState(205);
        expr();
        setState(206);
        match(LanguageParser::T__8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimContext ------------------------------------------------------------------

LanguageParser::PrimContext::PrimContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::PrimContext::INT() {
  return getToken(LanguageParser::INT, 0);
}

LanguageParser::ModContext* LanguageParser::PrimContext::mod() {
  return getRuleContext<LanguageParser::ModContext>(0);
}

LanguageParser::Rout_callContext* LanguageParser::PrimContext::rout_call() {
  return getRuleContext<LanguageParser::Rout_callContext>(0);
}


size_t LanguageParser::PrimContext::getRuleIndex() const {
  return LanguageParser::RulePrim;
}


std::any LanguageParser::PrimContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitPrim(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::PrimContext* LanguageParser::prim() {
  PrimContext *_localctx = _tracker.createInstance<PrimContext>(_ctx, getState());
  enterRule(_localctx, 42, LanguageParser::RulePrim);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(210);
      match(LanguageParser::T__31);
      break;
    }

    case 2: {
      setState(211);
      match(LanguageParser::T__32);
      break;
    }

    case 3: {
      setState(212);
      match(LanguageParser::INT);
      break;
    }

    case 4: {
      setState(213);
      mod();
      break;
    }

    case 5: {
      setState(214);
      rout_call();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModContext ------------------------------------------------------------------

LanguageParser::ModContext::ModContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LanguageParser::ModContext::IDENT() {
  return getToken(LanguageParser::IDENT, 0);
}

LanguageParser::ExprContext* LanguageParser::ModContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::ModContext::getRuleIndex() const {
  return LanguageParser::RuleMod;
}


std::any LanguageParser::ModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitMod(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ModContext* LanguageParser::mod() {
  ModContext *_localctx = _tracker.createInstance<ModContext>(_ctx, getState());
  enterRule(_localctx, 44, LanguageParser::RuleMod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(217);
      match(LanguageParser::IDENT);
      setState(218);
      match(LanguageParser::T__33);
      setState(219);
      expr();
      setState(220);
      match(LanguageParser::T__34);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(222);
      match(LanguageParser::IDENT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(223);
      match(LanguageParser::T__33);
      setState(224);
      expr();
      setState(225);
      match(LanguageParser::T__34);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

LanguageParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::ModContext* LanguageParser::AssignContext::mod() {
  return getRuleContext<LanguageParser::ModContext>(0);
}

LanguageParser::ExprContext* LanguageParser::AssignContext::expr() {
  return getRuleContext<LanguageParser::ExprContext>(0);
}


size_t LanguageParser::AssignContext::getRuleIndex() const {
  return LanguageParser::RuleAssign;
}


std::any LanguageParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::AssignContext* LanguageParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 46, LanguageParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    mod();
    setState(230);
    match(LanguageParser::T__35);
    setState(231);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Prim_typeContext ------------------------------------------------------------------

LanguageParser::Prim_typeContext::Prim_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LanguageParser::Prim_typeContext::getRuleIndex() const {
  return LanguageParser::RulePrim_type;
}


std::any LanguageParser::Prim_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitPrim_type(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::Prim_typeContext* LanguageParser::prim_type() {
  Prim_typeContext *_localctx = _tracker.createInstance<Prim_typeContext>(_ctx, getState());
  enterRule(_localctx, 48, LanguageParser::RulePrim_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    _la = _input->LA(1);
    if (!(_la == LanguageParser::T__36

    || _la == LanguageParser::T__37)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void LanguageParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  languageParserInitialize();
#else
  ::antlr4::internal::call_once(languageParserOnceFlag, languageParserInitialize);
#endif
}
