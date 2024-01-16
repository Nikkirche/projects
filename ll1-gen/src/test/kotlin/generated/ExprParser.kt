package gramm

import utils.ParsingException

import java.lang.Integer.parseInt

fun doubleFac(n:Int):Int{
	if(n<=1){
		return 1
	}
	else{
		return n* doubleFac(n-2)
	}
}

class TreeNodeExpr(val name:String) {
    var list = mutableListOf<TreeNodeExpr>()
    var value:Int? = null
var inh:Int? = null

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

class ExprParser(val lex:BaseLexer){
	var token = Token(0, "") 
	fun visit():TreeNodeExpr{
		token = lex.nextToken()
		val x =  visite()
		if(lex.getName(token)!="EOF"){
			throw ParsingException()
		}
		return x
	}
	fun visite():TreeNodeExpr{
		val node = TreeNodeExpr("e")
		when(lex.getName(token)){
			"BRO","NUM" -> {
				val x0 = visitt()
				node.list.add(x0)
				val x1 = visitep(x0.value)
				node.list.add(x1)
				node.value = x1.value
			}
			else -> throw ParsingException(lex.getName(token), "e")
		}
		return node
	}

	fun visitep(inh: Int?):TreeNodeExpr{
		val node = TreeNodeExpr("ep")
		node.inh = inh
		when(lex.getName(token)){
			"PLUS" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitt()
				node.list.add(x1)
				val x2 = visitep(inh!! + x1.value!!)
				node.list.add(x2)
				node.value = x2.value
			}
			"MINUS" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitt()
				node.list.add(x1)
				val x2 = visitep(inh!! - x1.value!!)
				node.list.add(x2)
				node.value = x2.value
			}
			"EOF","BRC"->{
				node.value = inh
				return node
			
			}
			else -> throw ParsingException(lex.getName(token), "ep")
		}
		return node
	}

	fun visitt():TreeNodeExpr{
		val node = TreeNodeExpr("t")
		when(lex.getName(token)){
			"BRO","NUM" -> {
				val x0 = visitf()
				node.list.add(x0)
				val x1 = visittp(x0.value)
				node.list.add(x1)
				node.value = x1.value
			}
			else -> throw ParsingException(lex.getName(token), "t")
		}
		return node
	}

	fun visittp(inh: Int?):TreeNodeExpr{
		val node = TreeNodeExpr("tp")
		node.inh = inh
		when(lex.getName(token)){
			"MUL" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitf()
				node.list.add(x1)
				val x2 = visittp(x1.value)
				node.list.add(x2)
				node.value = inh!! * x2.value!!
			}
			"DIV" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visitf()
				node.list.add(x1)
				val x2 = visittp(x1.value)
				node.list.add(x2)
				node.value = inh!! / x2.value!!
			}
			"EOF","PLUS","MINUS","BRC"->{
				node.value = inh
				return node
			
			}
			else -> throw ParsingException(lex.getName(token), "tp")
		}
		return node
	}

	fun visitf():TreeNodeExpr{
		val node = TreeNodeExpr("f")
		when(lex.getName(token)){
			"BRO" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				val x1 = visite()
				node.list.add(x1)
				val x2 = token
				node.list.add(TreeNodeExpr(lex.getName(x2)))
				token = lex.nextToken()
				val x3 = visitfp(x1.value)
				node.list.add(x3)
				node.value = x3.value
			}
			"NUM" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				node.value = parseInt(x0.content) 
			}
			else -> throw ParsingException(lex.getName(token), "f")
		}
		return node
	}

	fun visitfp(inh: Int?):TreeNodeExpr{
		val node = TreeNodeExpr("fp")
		node.inh = inh
		when(lex.getName(token)){
			"DFAC" -> {
				val x0 = token
				node.list.add(TreeNodeExpr(lex.getName(x0)))
				token = lex.nextToken()
				node.value =  doubleFac(inh!!) 
			}
			"EOF","PLUS","MINUS","MUL","DIV","BRC"->{
				node.value = inh
				return node
			
			}
			else -> throw ParsingException(lex.getName(token), "fp")
		}
		return node
	}

	
}