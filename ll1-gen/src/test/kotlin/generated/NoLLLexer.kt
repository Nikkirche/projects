package gramm
private val rules = mapOf(
	Pair(Regex("^[a-z]+"),1),
	Pair(Regex("^[0-9]+"),2))

private val mapping = listOf(
	"EOF",
	"SKIP", 
	"VAR",
	"INT")

