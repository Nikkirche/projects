#include <iostream>

#include "antlr4-runtime.h"
#include "libs/LanguageLexer.h"
#include "libs/LanguageParser.h"
#include "LLVMVisitor.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("../main.prog");
    ANTLRInputStream input(stream);
    LanguageLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LanguageParser parser(&tokens);    
    
    LanguageParser::ProgramContext* tree = parser.program();

    LLVMVisitor visitor;
    visitor.visitProgram(tree);
    // Scene scene = std::any_cast<Scene>(visitor.visitFile(tree));

    return 0;
}