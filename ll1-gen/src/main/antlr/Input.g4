grammar Input;
@header {
package parser;
}
gramm :  head  rule+|rule+ ;
head : HEAD;
rule : (terminal_rule|noterminal_rule);
noterminal_rule : rdec | redecl  'from' indecl rdec;
rule_inn : ruleb |ruleb code;
code : CODE;
rdec : noterminal ':' rule_inn ('|' rule_inn )*';';
redecl : |'[' (ident ',' ident)* ']';
indecl : |'[' (ident ',' ident)* ']';
ruleb: rule_body  | epsilon;
rule_body : (terminal|inh|noterminal)+;

inh : IDENT_LOW ARG;
terminal_rule : terminal ':' terminal_rule_inn ;
terminal_rule_inn :  REGEX ';';
terminal : IDENT_UP;
noterminal : IDENT_LOW;
ident : (IDENT_LOW|IDENT_UP)+;

epsilon : 'EPS';

ARG : 'arg{'(~[}])+'}';
HEAD :  'head|' .*?  '|head';
CODE : '{'(~[}])+'}';
OP : '+'|'*'| '?';
IDENT_UP :  [A-Z]+;
REGEX :  '"'(~["])+'"';
IDENT_LOW : [a-z]+;
WS : [ \r\t\n]+ -> skip ;