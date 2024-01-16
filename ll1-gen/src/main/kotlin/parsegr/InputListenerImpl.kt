package parsegr

import data.*
import parser.InputBaseListener
import parser.InputParser

typealias mapAttr = MutableMap<String, String>

class InputListenerImpl : InputBaseListener() {
    val noTerminalRules = mutableListOf<NoTerminalRule>()
    val trules = mutableListOf<TerminalRule>()
    var name: String = ""
    private var typeIn: mapAttr = mutableMapOf()
    private var typeOut: mapAttr = mutableMapOf()
    private var listNT = mutableListOf<MutableList<Atom>>()
    private var listAlt = mutableListOf<Atom>()
    private var codes: MutableList<String> = mutableListOf()
    var head :String? = null
    override fun enterRdec(ctx: InputParser.RdecContext) {
        name = ctx.noterminal().text
        listNT = mutableListOf()
        codes = mutableListOf()
        super.enterRdec(ctx)
    }


    override fun exitNoterminal_rule(ctx: InputParser.Noterminal_ruleContext?) {
        noTerminalRules.add(NoTerminalRule(name, listNT, Action(codes, typeIn, typeOut)))
        typeIn = mutableMapOf()
        typeOut = mutableMapOf()
        super.exitNoterminal_rule(ctx)
    }

    override fun enterEpsilon(ctx: InputParser.EpsilonContext?) {
        listAlt.add(Epsilon())
        super.enterEpsilon(ctx)
    }

    override fun enterRule_inn(ctx: InputParser.Rule_innContext?) {
        listAlt = mutableListOf()
        super.enterRule_inn(ctx)
    }


    override fun exitRule_inn(ctx: InputParser.Rule_innContext) {
        listNT.add(listAlt)
        listAlt = mutableListOf()
        super.exitRule_inn(ctx)
    }

    override fun enterTerminal(ctx: InputParser.TerminalContext) {
        listAlt.add(Terminal(ctx.text))
        super.enterTerminal(ctx)
    }

    override fun enterNoterminal(ctx: InputParser.NoterminalContext) {
        listAlt.add(NoTerminal(ctx.text,null))
        super.enterNoterminal(ctx)
    }

    override fun enterTerminal_rule(ctx: InputParser.Terminal_ruleContext) {
        name = ctx.terminal().text
        super.enterTerminal_rule(ctx)
    }

    override fun exitInh(ctx: InputParser.InhContext) {
        val c = ctx.children[1].text
        listAlt.add(NoTerminal(ctx.children[0].text,c.substring(4,c.length-1)))
        super.exitInh(ctx)
    }
    override fun enterIndecl(ctx: InputParser.IndeclContext) {
        if (ctx.ident().size == 2) {
            typeIn[ctx.ident(0).text] = ctx.ident(1).text
        }
        super.enterIndecl(ctx)
    }

    override fun enterRedecl(ctx: InputParser.RedeclContext) {
        if (ctx.ident().size == 2) {
            typeOut[ctx.ident(0).text] = ctx.ident(1).text
        }
        super.enterRedecl(ctx)
    }

    override fun enterTerminal_rule_inn(ctx: InputParser.Terminal_rule_innContext) {
        trules.add(TerminalRule(name, ctx.text))
        super.enterTerminal_rule_inn(ctx)
    }

    override fun enterCode(ctx: InputParser.CodeContext) {
        codes.add(ctx.text)
        super.enterCode(ctx)
    }

    override fun enterHead(ctx: InputParser.HeadContext) {
        head = ctx.text.substring(5,ctx.text.length-6)
        super.enterHead(ctx)
    }
}