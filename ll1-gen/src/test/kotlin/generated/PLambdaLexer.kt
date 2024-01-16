package gramm
private val rules = mapOf(
	Pair(Regex("^[ \n\t]"),0),
	Pair(Regex("^lambda"),1),
	Pair(Regex("^[(]"),2),
	Pair(Regex("^[)]"),3),
	Pair(Regex("^[+]"),4),
	Pair(Regex("^[*]"),5),
	Pair(Regex("^[-]"),6),
	Pair(Regex("^[/]"),7),
	Pair(Regex("^[0-9]+"),8),
	Pair(Regex("^[a-z]+"),9),
	Pair(Regex("^[,]"),10),
	Pair(Regex("^[:]"),11))

private val mapping = listOf(
	"EOF",
	"SKIP", 
	"LAMBDA",
	"BRO",
	"BRC",
	"PLUS",
	"MUL",
	"MINUS",
	"DIV",
	"NUM",
	"VAR",
	"COMMA",
	"D")

class PLambdaLexer(inp:String):BaseLexer(inp, rules, mapping)
