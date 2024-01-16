
// Generated from Language.g4 by ANTLR 4.13.0


#include "LanguageLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LanguageLexerStaticData final {
  LanguageLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LanguageLexerStaticData(const LanguageLexerStaticData&) = delete;
  LanguageLexerStaticData(LanguageLexerStaticData&&) = delete;
  LanguageLexerStaticData& operator=(const LanguageLexerStaticData&) = delete;
  LanguageLexerStaticData& operator=(LanguageLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag languagelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LanguageLexerStaticData *languagelexerLexerStaticData = nullptr;

void languagelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (languagelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(languagelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LanguageLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "T__32", 
      "T__33", "T__34", "T__35", "T__36", "T__37", "WS", "IDENT", "INT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,41,242,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,
  	1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,
  	1,16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,
  	1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,
  	1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,31,1,31,
  	1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,35,
  	1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,38,4,38,224,8,38,11,38,12,38,225,1,38,1,38,1,39,4,39,231,
  	8,39,11,39,12,39,232,1,40,3,40,236,8,40,1,40,4,40,239,8,40,11,40,12,40,
  	240,0,0,41,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,1,0,3,3,0,9,10,13,13,32,32,2,0,65,
  	90,97,122,1,0,48,57,245,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,
  	0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,
  	0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,
  	1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,
  	0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,
  	0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,1,83,
  	1,0,0,0,3,91,1,0,0,0,5,93,1,0,0,0,7,96,1,0,0,0,9,100,1,0,0,0,11,104,1,
  	0,0,0,13,110,1,0,0,0,15,112,1,0,0,0,17,114,1,0,0,0,19,116,1,0,0,0,21,
  	123,1,0,0,0,23,126,1,0,0,0,25,131,1,0,0,0,27,136,1,0,0,0,29,140,1,0,0,
  	0,31,145,1,0,0,0,33,148,1,0,0,0,35,151,1,0,0,0,37,155,1,0,0,0,39,158,
  	1,0,0,0,41,162,1,0,0,0,43,164,1,0,0,0,45,167,1,0,0,0,47,170,1,0,0,0,49,
  	173,1,0,0,0,51,176,1,0,0,0,53,178,1,0,0,0,55,180,1,0,0,0,57,182,1,0,0,
  	0,59,184,1,0,0,0,61,186,1,0,0,0,63,188,1,0,0,0,65,193,1,0,0,0,67,199,
  	1,0,0,0,69,201,1,0,0,0,71,203,1,0,0,0,73,206,1,0,0,0,75,214,1,0,0,0,77,
  	223,1,0,0,0,79,230,1,0,0,0,81,235,1,0,0,0,83,84,5,114,0,0,84,85,5,111,
  	0,0,85,86,5,117,0,0,86,87,5,116,0,0,87,88,5,105,0,0,88,89,5,110,0,0,89,
  	90,5,101,0,0,90,2,1,0,0,0,91,92,5,58,0,0,92,4,1,0,0,0,93,94,5,105,0,0,
  	94,95,5,115,0,0,95,6,1,0,0,0,96,97,5,101,0,0,97,98,5,110,0,0,98,99,5,
  	100,0,0,99,8,1,0,0,0,100,101,5,118,0,0,101,102,5,97,0,0,102,103,5,114,
  	0,0,103,10,1,0,0,0,104,105,5,97,0,0,105,106,5,114,0,0,106,107,5,114,0,
  	0,107,108,5,97,0,0,108,109,5,121,0,0,109,12,1,0,0,0,110,111,5,40,0,0,
  	111,14,1,0,0,0,112,113,5,44,0,0,113,16,1,0,0,0,114,115,5,41,0,0,115,18,
  	1,0,0,0,116,117,5,114,0,0,117,118,5,101,0,0,118,119,5,116,0,0,119,120,
  	5,117,0,0,120,121,5,114,0,0,121,122,5,110,0,0,122,20,1,0,0,0,123,124,
  	5,105,0,0,124,125,5,102,0,0,125,22,1,0,0,0,126,127,5,116,0,0,127,128,
  	5,104,0,0,128,129,5,101,0,0,129,130,5,110,0,0,130,24,1,0,0,0,131,132,
  	5,101,0,0,132,133,5,108,0,0,133,134,5,115,0,0,134,135,5,101,0,0,135,26,
  	1,0,0,0,136,137,5,102,0,0,137,138,5,111,0,0,138,139,5,114,0,0,139,28,
  	1,0,0,0,140,141,5,108,0,0,141,142,5,111,0,0,142,143,5,111,0,0,143,144,
  	5,112,0,0,144,30,1,0,0,0,145,146,5,105,0,0,146,147,5,110,0,0,147,32,1,
  	0,0,0,148,149,5,46,0,0,149,150,5,46,0,0,150,34,1,0,0,0,151,152,5,97,0,
  	0,152,153,5,110,0,0,153,154,5,100,0,0,154,36,1,0,0,0,155,156,5,111,0,
  	0,156,157,5,114,0,0,157,38,1,0,0,0,158,159,5,110,0,0,159,160,5,111,0,
  	0,160,161,5,116,0,0,161,40,1,0,0,0,162,163,5,60,0,0,163,42,1,0,0,0,164,
  	165,5,60,0,0,165,166,5,61,0,0,166,44,1,0,0,0,167,168,5,61,0,0,168,169,
  	5,61,0,0,169,46,1,0,0,0,170,171,5,33,0,0,171,172,5,61,0,0,172,48,1,0,
  	0,0,173,174,5,62,0,0,174,175,5,61,0,0,175,50,1,0,0,0,176,177,5,62,0,0,
  	177,52,1,0,0,0,178,179,5,43,0,0,179,54,1,0,0,0,180,181,5,45,0,0,181,56,
  	1,0,0,0,182,183,5,42,0,0,183,58,1,0,0,0,184,185,5,37,0,0,185,60,1,0,0,
  	0,186,187,5,47,0,0,187,62,1,0,0,0,188,189,5,116,0,0,189,190,5,114,0,0,
  	190,191,5,117,0,0,191,192,5,101,0,0,192,64,1,0,0,0,193,194,5,102,0,0,
  	194,195,5,97,0,0,195,196,5,108,0,0,196,197,5,115,0,0,197,198,5,101,0,
  	0,198,66,1,0,0,0,199,200,5,91,0,0,200,68,1,0,0,0,201,202,5,93,0,0,202,
  	70,1,0,0,0,203,204,5,58,0,0,204,205,5,61,0,0,205,72,1,0,0,0,206,207,5,
  	105,0,0,207,208,5,110,0,0,208,209,5,116,0,0,209,210,5,101,0,0,210,211,
  	5,103,0,0,211,212,5,101,0,0,212,213,5,114,0,0,213,74,1,0,0,0,214,215,
  	5,98,0,0,215,216,5,111,0,0,216,217,5,111,0,0,217,218,5,108,0,0,218,219,
  	5,101,0,0,219,220,5,97,0,0,220,221,5,110,0,0,221,76,1,0,0,0,222,224,7,
  	0,0,0,223,222,1,0,0,0,224,225,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,
  	226,227,1,0,0,0,227,228,6,38,0,0,228,78,1,0,0,0,229,231,7,1,0,0,230,229,
  	1,0,0,0,231,232,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,80,1,0,0,
  	0,234,236,5,45,0,0,235,234,1,0,0,0,235,236,1,0,0,0,236,238,1,0,0,0,237,
  	239,7,2,0,0,238,237,1,0,0,0,239,240,1,0,0,0,240,238,1,0,0,0,240,241,1,
  	0,0,0,241,82,1,0,0,0,5,0,225,232,235,240,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  languagelexerLexerStaticData = staticData.release();
}

}

LanguageLexer::LanguageLexer(CharStream *input) : Lexer(input) {
  LanguageLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *languagelexerLexerStaticData->atn, languagelexerLexerStaticData->decisionToDFA, languagelexerLexerStaticData->sharedContextCache);
}

LanguageLexer::~LanguageLexer() {
  delete _interpreter;
}

std::string LanguageLexer::getGrammarFileName() const {
  return "Language.g4";
}

const std::vector<std::string>& LanguageLexer::getRuleNames() const {
  return languagelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LanguageLexer::getChannelNames() const {
  return languagelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LanguageLexer::getModeNames() const {
  return languagelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LanguageLexer::getVocabulary() const {
  return languagelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LanguageLexer::getSerializedATN() const {
  return languagelexerLexerStaticData->serializedATN;
}

const atn::ATN& LanguageLexer::getATN() const {
  return *languagelexerLexerStaticData->atn;
}




void LanguageLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  languagelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(languagelexerLexerOnceFlag, languagelexerLexerInitialize);
#endif
}