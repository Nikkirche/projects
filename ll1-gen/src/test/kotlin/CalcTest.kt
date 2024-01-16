
import gramm.ExprLexer
import gramm.ExprParser
import org.junit.jupiter.api.Test
import org.junit.jupiter.api.assertThrows
import utils.LexerException
import utils.ParsingException
import java.io.File
import kotlin.test.assertEquals

class CalcTest{
    private fun test(s:String):Int{
        generate("src/test/resources/Expr.ps", File("src/test/kotlin/generated") )
        val  l = ExprLexer(s)
        val p = ExprParser(l)
        return p.visit().value!!
    }

    @Test
    fun priority_test(){
        assertEquals(8,test("1 + 1  * 7"))
        assertEquals(8,test("1 + (1  * 7)"))
        assertEquals(14,test("(1 + 1)  * 7"))
        assertEquals(20,test("36/6/3+2"))
    }
    @Test
    fun double_fac_test(){
        assertEquals(1,test("(1)!!"))
        assertEquals(2,test("(2)!!"))
        assertEquals(48,test("(6)!!"))

    }
    @Test
    fun  lexer_test(){
        assertThrows<LexerException> { test("jgdw") }
        assertThrows<LexerException> { test("[]") }
        assertThrows<LexerException> { test("1.2") }
    }

    @Test
    fun  parser_test(){
        assertThrows<ParsingException> { test("1 ++ 4") }
        assertThrows<ParsingException> { println(test("1) + 2")) }
        assertThrows<ParsingException> { test("2 + ()") }
    }
}