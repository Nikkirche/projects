import gramm.PLambdaLexer
import gramm.PLambdaParser

import org.junit.jupiter.api.Test
import org.junit.jupiter.api.assertThrows
import utils.LexerException
import utils.ParsingException
import java.io.File

class PLambdaTest {
    private fun test(s: String) {
        generate("src/test/resources/PLambda.ps", File("src/test/kotlin/generated"))
        val l = PLambdaLexer(s)
        PLambdaParser(l).visit()
    }

    @Test
    fun parses_test() {
        test("lambda x,y :x+y")
        test("lambda x: lambda y:x+y")
        test("lambda x,y :(x+y)*(10) / 3")

    }

    @Test
    fun lexer_test() {
        assertThrows<LexerException> { test("lambda x %: 10 + lambda y:x+y") }
        assertThrows<LexerException> { test("lambda приветмир %: 10 + lambda y:x+y") }

    }

    @Test
    fun parser_test() {
        assertThrows<ParsingException> { test("lambda x: x10 + lambda y:x+y") }
        assertThrows<ParsingException> { test("lambda x: 10 + lambda y:x+y") }
        assertThrows<ParsingException> { test("lambda x,y :x+y)") }


    }
}