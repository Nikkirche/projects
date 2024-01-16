package generator

import java.io.File
import java.io.IOException

abstract class AbstractGenerator(private val dir: File, val gramm:String, val name: String) {
    var buff:String= ""
    val NL = "\n"
    val TAB = "\t"
    val NLF = "\n\t\t"
    val NLT = "\n\t"
    val className = "$gramm$name"
    fun write(){
        val n = "$className.kt"
        try {
            dir.resolve(File(n)).writeText(buff)
        }
        catch (e:IOException){
            println("Couldn't write $n, with directory ${dir.name}")
        }
    }

}