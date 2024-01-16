package generator

import data.*
import java.io.File

typealias NTL = List<NoTerminalRule>

class ParserGenerator(output: File, gramm: String) : AbstractGenerator(output, gramm, "Parser") {
    private lateinit var nname: String
    fun generate(noTerminalRules: List<NoTerminalRule>, head: String?) {

        nname = "TreeNode$gramm"
        val first = generateFirst(noTerminalRules)
        val follow = generateFollow(noTerminalRules, first)
        checkLL1(first, follow, noTerminalRules)
        buff = buildString {
            append("package gramm$NL$NL")
            append("import utils.ParsingException$NL")
            if (head != null) {
                append("$head$NL")
            }
            append(
                """class $nname(val name:String) {
    var list = mutableListOf<$nname>()
    """
            )
            val attrs = mutableMapOf<String, String>()
            for (nt in noTerminalRules) {
                attrs.putAll(nt.action.input)
                attrs.putAll(nt.action.output)
            }
            println("Has following attributes - $attrs")
            for ((k, v) in attrs) {
                append("var ${k}:$v? = null$NL")
            }
            append(
                """
    override fun toString(): String {
        return toStringWithDepth(0)
    }
    private fun toStringWithDepth(i:Int):String{
        return buildString {
            for (j in 0..<i){
                append(" ")
            }
            append("$name \n")
            for (j in list){
                append(j.toStringWithDepth(i+1))
            }
        }
    }
}

"""
            )
            append("class $className(val lex:BaseLexer){$NLT")
            append("var token = Token(0, \"\") $NLT")
            append("fun visit():$nname{$NLF")
            append("token = lex.nextToken()$NLF")
            append("val x =  visit${noTerminalRules[0].atom.name}()$NLF")
            append(
                "if(lex.getName(token)!=\"EOF\"){$NLF" +
                        "\tthrow ParsingException()\n" +
                        "\t\t}$NLF"
            )
            append("return x$NLT}$NLT")
            for (rule in noTerminalRules) {
                append(genVisit(rule, first, follow))
            }
            append("$NL}")
        }
        write()
    }

    private fun checkLL1(
        first: Map<NoTerminal, MutableSet<Atom>>,
        follow: Map<NoTerminal, Set<Atom>>,
        noTerminalRules: List<NoTerminalRule>
    ) {
        for (rule in noTerminalRules) {
            val foll = follow[rule.atom as NoTerminal]!!
            for ((a, b) in rule.v.cartesianProduct(rule.v)) {
                if (a != b) {
                    val ast = a[0]
                    val bst = b[0]
                    val firstA = mutableSetOf<Atom>()
                    val firstB = mutableSetOf<Atom>()
                    if (ast is Terminal) {
                        firstA.add(ast)
                    }
                    if (ast is NoTerminal) {
                        firstA.addAll(first[ast]!!)
                    }
                    if (bst is Terminal) {
                        firstB.add(bst)
                    }
                    if (bst is NoTerminal) {
                        firstB.addAll(first[bst]!!)
                    }
                    if (firstB.intersect(firstA).isNotEmpty()) {

                        throw RuntimeException("No LL Grammmatic rule 1  $firstA $firstB ")
                    }
                    if (firstB.contains(Epsilon()) && foll.intersect(firstB).isNotEmpty()) {
                        throw RuntimeException("No LL Grammmatic rule 2")
                    }
                }
            }

        }
    }

    fun <S> List<S>.cartesianProduct(other: List<S>): List<Pair<S, S>> =
        this.flatMap { s ->
            List(other.size) { s }.zip(other)
        }

    private fun genVisit(
        r: NoTerminalRule,
        first: Map<NoTerminal, Set<Atom>>,
        follow: Map<NoTerminal, Set<Atom>>
    ): String {

        return buildString {
            val m = r.action.input
            append("fun visit${r.atom.name}" +
                    "(${
                        m.entries.joinToString(separator = ", ")
                        { k -> "${k.key}: ${k.value}?" }
                    }):$nname{$NLF"
            )
            append("val node = $nname(\"${r.atom.name}\")$NLF")
            for (k in m.keys) {
                append("node.$k = $k$NLF")
            }
            append("when(lex.getName(token)){$NLF$TAB")
            for ((j, a) in r.v.withIndex()) {
                if (a[0] == Epsilon()) {
                    append("${
                        follow[r.atom]!!.joinToString(separator = ",")
                        { "\"${it.name}\"" }
                    }->")
                    val tmp = "return node$NLF$TAB"
                    val t = r.action.code
                    if (t.isNotEmpty()) {
                        append("{$NLF")
                        append("$TAB$TAB${t[j].subSequence(1, t[j].length - 1)}$NLF$TAB")
                        append("$TAB$tmp$NLF$TAB}$NLF$TAB")
                    } else {
                        append(tmp)
                    }
                    continue
                }

                val fst1 = getFirst1(first, follow, r.atom, a[0])
                append("${fst1.joinToString(separator = ",") { "\"${it}\"" }} -> {$NLF$TAB")
                for ((i, value) in a.withIndex()) {
                    if (value is NoTerminal) {
                        var t = ""
                        if (value.args != null) {
                            t = value.args
                        }
                        append("${TAB}val x$i = visit${value.name}($t)$NLF$TAB")
                        append("${TAB}node.list.add(x$i)$NLF$TAB")
                    }
                    if (value is Terminal) {
                        append("${TAB}val x$i = token$NLF$TAB")
                        append("${TAB}node.list.add($nname(lex.getName(x$i)))$NLF$TAB")
                        append("${TAB}token = lex.nextToken()$NLF$TAB")
                    }
                }
                val t = r.action.code
                if (t.isNotEmpty()) {
                    append("$TAB${t[j].subSequence(1, t[j].length - 1)}$NLF$TAB")
                }
                append("}$NLF$TAB")
            }
            append("else -> throw ParsingException(lex.getName(token), \"${r.atom.name}\")$NLF")
            append("}$NLF")
            append("return node$NLT")
            append("}$NL$NLT")
        }
    }

    private fun getFirst1(
        first: Map<NoTerminal, Set<Atom>>,
        follow: Map<NoTerminal,
                Set<Atom>>, st: Atom, to: Atom
    ): List<String> {
        return if (to is Terminal) {
            listOf(to.name)
        } else {
            val f = first[to as NoTerminal]!!.toMutableSet()
            if (f.remove(Epsilon())) {
                f.addAll(follow[st]!!)
            }
            f.map { it.name }
        }
    }

    private fun generateFollow(
        rules: List<NoTerminalRule>,
        first: Map<NoTerminal, Set<Atom>>
    ): Map<NoTerminal, Set<Atom>> {
        val r = mutableMapOf<NoTerminal, MutableSet<Atom>>()
        for ((i, a) in rules.withIndex()) {
            if (i != 0) {
                r[a.atom as NoTerminal] = mutableSetOf()
            } else {
                r[a.atom as NoTerminal] = mutableSetOf(Terminal("EOF"))
            }
        }
        var changed = true
        while (changed) {
            changed = false
            for (rule in rules) {
                for (alt in rule.v) {
                    for ((k, s) in alt.withIndex()) {
                        if (s !is NoTerminal) {
                            continue
                        }
                        if (k == alt.size - 1) {
                            changed = r[s]!!.addAll(r[rule.atom as NoTerminal]!!) || changed
                            continue
                        }
                        val end = alt[k + 1]
                        if (end is Terminal) {
                            changed = r[s]!!.add(end) || changed
                        } else if (end is NoTerminal) {
                            val f = first[end]!!.toMutableSet()
                            if (Epsilon() in f) {
                                f.remove(Epsilon())
                                changed = r[s]!!.addAll(r[rule.atom as NoTerminal]!!) || changed
                            }
                            changed = r[s]!!.addAll(f) || changed
                        }

                    }
                }
            }
        }
        println("Follow is ${r.map { it.value.map { t -> t.name } }}")
        return r
    }

    private fun generateFirst(rules: NTL): Map<NoTerminal, MutableSet<Atom>> {
        val r = mutableMapOf<NoTerminal, MutableSet<Atom>>()
        for (a in rules) {
            r[a.atom as NoTerminal] = mutableSetOf()
        }
        var changed = true
        while (changed) {
            changed = false
            for (rule in rules) {
                for (alt in rule.v) {
                    val s = alt[0]
                    if (s is NoTerminal) {
                        changed = r[rule.atom]!!.addAll(r[s]!!) || changed
                    } else if (s is Terminal || s is Epsilon) {
                        changed = r[rule.atom]!!.add(s) || changed
                    }
                }
            }
        }
        println("First is ${r.map { it.value.map { t -> t.name } }}")
        return r
    }
}