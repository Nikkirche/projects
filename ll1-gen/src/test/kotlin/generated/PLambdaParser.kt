package gramm

import utils.ParsingException
class TreeNodePLambda(val name:String) {
    var list = mutableListOf<TreeNodePLambda>()
    
    override fun toString(): String {
        return toStringWithDepth(0)
    }
    private fun toStringWithDepth(i:Int):String{
        return buildString {
            for (j in 0..<i){
                append(" ")
            }
            append("Parser \n")
            for (j in list){
                append(j.toStringWithDepth(i+1))
            }
        }
    }
}

class PLambdaParser(val lex:BaseLexer){
	var token = Token(0, "") 
	fun visit():TreeNodePLambda{
		token = lex.nextToken()
		val x =  visits()
		if(lex.getName(token)!="EOF"){
			throw ParsingException()
		}
		return x
	}
	fun visits():TreeNodePLambda{
		val node = TreeNodePLambda("s")
		when(lex.getName(token)){
			"LAMBDA" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = token
				node.list.add(TreeNodePLambda(lex.getName(x1)))
				token = lex.nextToken()
				val x2 = visitargs()
				node.list.add(x2)
				val x3 = token
				node.list.add(TreeNodePLambda(lex.getName(x3)))
				token = lex.nextToken()
				val x4 = visitsp()
				node.list.add(x4)
			}
			else -> throw ParsingException(lex.getName(token), "s")
		}
		return node
	}

	fun visitsp():TreeNodePLambda{
		val node = TreeNodePLambda("sp")
		when(lex.getName(token)){
			"NUM","VAR","BRO" -> {
				val x0 = visite()
				node.list.add(x0)
			}
			"LAMBDA" -> {
				val x0 = visits()
				node.list.add(x0)
			}
			else -> throw ParsingException(lex.getName(token), "sp")
		}
		return node
	}

	fun visitargs():TreeNodePLambda{
		val node = TreeNodePLambda("args")
		when(lex.getName(token)){
			"COMMA" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = token
				node.list.add(TreeNodePLambda(lex.getName(x1)))
				token = lex.nextToken()
				val x2 = visitargs()
				node.list.add(x2)
			}
			"D"->return node
			else -> throw ParsingException(lex.getName(token), "args")
		}
		return node
	}

	fun visite():TreeNodePLambda{
		val node = TreeNodePLambda("e")
		when(lex.getName(token)){
			"NUM","VAR","BRO" -> {
				val x0 = visitt()
				node.list.add(x0)
				val x1 = visitep()
				node.list.add(x1)
			}
			else -> throw ParsingException(lex.getName(token), "e")
		}
		return node
	}

	fun visitep():TreeNodePLambda{
		val node = TreeNodePLambda("ep")
		when(lex.getName(token)){
			"PLUS" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitt()
				node.list.add(x1)
				val x2 = visitep()
				node.list.add(x2)
			}
			"MINUS" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitt()
				node.list.add(x1)
				val x2 = visitep()
				node.list.add(x2)
			}
			"EOF","BRC"->return node
			else -> throw ParsingException(lex.getName(token), "ep")
		}
		return node
	}

	fun visitt():TreeNodePLambda{
		val node = TreeNodePLambda("t")
		when(lex.getName(token)){
			"NUM","VAR","BRO" -> {
				val x0 = visitf()
				node.list.add(x0)
				val x1 = visittp()
				node.list.add(x1)
			}
			else -> throw ParsingException(lex.getName(token), "t")
		}
		return node
	}

	fun visittp():TreeNodePLambda{
		val node = TreeNodePLambda("tp")
		when(lex.getName(token)){
			"MUL" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitf()
				node.list.add(x1)
				val x2 = visittp()
				node.list.add(x2)
			}
			"DIV" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitf()
				node.list.add(x1)
				val x2 = visittp()
				node.list.add(x2)
			}
			"EOF","PLUS","MINUS","BRC"->return node
			else -> throw ParsingException(lex.getName(token), "tp")
		}
		return node
	}

	fun visitf():TreeNodePLambda{
		val node = TreeNodePLambda("f")
		when(lex.getName(token)){
			"NUM" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
			}
			"VAR" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
			}
			"BRO" -> {
				val x0 = token
				node.list.add(TreeNodePLambda(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visite()
				node.list.add(x1)
				val x2 = token
				node.list.add(TreeNodePLambda(lex.getName(x2)))
				token = lex.nextToken()
			}
			else -> throw ParsingException(lex.getName(token), "f")
		}
		return node
	}

	
}