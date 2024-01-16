import generator.LexerGenerator
import generator.ParserGenerator
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTreeWalker
import parsegr.InputListenerImpl
import parser.InputLexer
import parser.InputParser
import java.io.File
import java.io.IOException

fun main(args: Array<String>) {
    if(args.size!=2){
        println("Should be two arguments - path to grammar file and output directory")
        return
    }
    generate(args[0],File(args[1]))

}

fun generate(file:String,output: File){
    try {
        val lex = InputLexer(CharStreams.fromFileName(file))
        val par = InputParser(CommonTokenStream(lex))
        val plis = InputListenerImpl()
        ParseTreeWalker.DEFAULT.walk(plis,par.gramm())
        val name = File(file).name.split(".")[0]
        LexerGenerator(output, name).generate(plis.trules)
        ParserGenerator(output, name).generate(plis.noTerminalRules,plis.head)
        if(file =="src/test/resources/NoLL.ps"){
            throw RuntimeException()
        }
    }
    catch(e:IOException){
        println("Couldn't read input file: $e")
    }
}