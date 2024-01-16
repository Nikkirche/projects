package gramm

import utils.LexerException


typealias Type = Int
class Token(val t:Type,val content:String)

abstract class BaseLexer(
    private val inp: String,
    private val rules: Map<Regex, Type>,
    private val mapping: List<String>) {
    private var index = 0
    fun nextToken(): Token {
        if (index >= inp.length) {
            return Token(-1,"")
        }
        for ((rule, tok) in rules) {
            val res = rule.find(inp.substring(index))
            if (res != null) {
                index += res.value.length
                if (tok == 0) {
                    return nextToken()
                }
                //println(res.value)
                return Token(tok,res.value)
            }
        }
        throw LexerException(inp.substring(index))
    }

    fun getName(i: Token): String {
        if (i.t > mapping.size || i.t < -1) {
            throw RuntimeException("Invalid token type given")
        }
        return mapping[i.t + 1]
    }
}