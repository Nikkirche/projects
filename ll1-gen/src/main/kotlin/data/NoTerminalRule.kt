package data

class NoTerminalRule( name:String,val v:MutableList<MutableList<Atom>>,val action: Action):Rule(NoTerminal(name,null))
class Action(var code:List<String>,val input:Map<String,String>,val output: Map<String,String>)