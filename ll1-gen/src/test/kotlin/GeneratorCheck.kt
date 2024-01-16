import org.junit.jupiter.api.assertThrows
import java.io.File
import kotlin.test.Test

class GeneratorCheck {
    @Test
    fun noLLCheck() {
        assertThrows<RuntimeException> { generate("4", File("src/test/kotlin/generated")) }
    }
}