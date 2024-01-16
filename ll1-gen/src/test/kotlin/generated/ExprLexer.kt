package gramm
private val rules = mapOf(
	Pair(Regex("^[ \n\t]"),0),
	Pair(Regex("^[(]"),1),
	Pair(Regex("^[)]"),2),
	Pair(Regex("^[+]"),3),
	Pair(Regex("^[-]"),4),
	Pair(Regex("^[*]"),5),
	Pair(Regex("^[/]"),6),
	Pair(Regex("^!!"),7),
	Pair(Regex("^[0-9]+"),8))

private val mapping = listOf(
	"EOF",
	"SKIP", 
	"BRO",
	"BRC",
	"PLUS",
	"MINUS",
	"MUL",
	"DIV",
	"DFAC",
	"NUM")

class ExprLexer(inp:String):BaseLexer(inp, rules, mapping)
