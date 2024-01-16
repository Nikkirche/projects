package generator

import data.TerminalRule
import java.io.File

class LexerGenerator(output: File,gramm:String) : AbstractGenerator(output,gramm,"Lexer") {
    fun generate( rules:List<TerminalRule>){
        val p = rules.partition { it.atom.name=="SKIP" }
        buff = buildString {
            append("package gramm$NL")
            var c = 0
            append("private val rules = mapOf($NLT")
            if(p.first.isNotEmpty()) {
                append(p.first.joinToString(separator = ",$NLT", postfix = ",$NLT") {
                    val k = it.what.substring(1, it.what.length - 2)
                    """Pair(Regex("^$k"),0)"""
                })
            }
            append(p.second.joinToString (separator = ",$NLT"){
                c++
                val k = it.what.substring(1,it.what.length-2)
                """Pair(Regex("^$k"),$c)"""
            })
            append(")$NL$NL")
            append("""private val mapping = listOf($NLT"EOF",$NLT"SKIP", $NLT""")
            append(p.second.joinToString (separator = ",$NLT"){
                "\"${it.atom.name}\""
            })
            append(")$NL$NL")
            append("class $className(inp:String):BaseLexer(inp, rules, mapping)$NL")
        }
        write()
    }
}