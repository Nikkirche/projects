package utils

class LexerException(tok:String):Exception("Unexpected symbol $tok")
class ParsingException(str:String):Exception(str){
    constructor(tok:String,where:String) : this("Unexpected $tok at state $where")
    constructor() : this("Lexer at end not in the EOF state")

}