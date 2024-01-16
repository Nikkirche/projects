grammar Language;

program : (simple_dec | routine_dec)*;
simple_dec : var_dec;
routine_dec : 'routine' IDENT  parameters ':' type 'is' body 'end'
    | 'routine' IDENT  parameters 'is' body 'end';
var_dec : 'var' IDENT ':' type 'is' expr;
type : prim_type | arr_type ;
arr_type : 'array' type;
parameters : '(' param_dec (',' param_dec)? ')'
    | '(' ')';
param_dec : IDENT ':' type;
body : (simple_dec | statement | return_statement)*;
statement : assign | if_statement | for_loop | rout_call;
return_statement : 'return' expr;
if_statement : 'if' expr 'then' body 'else' body 'end'
    | 'if' expr 'then' body  'end';
for_loop : 'for' IDENT range 'loop' body 'end';
rout_call : IDENT '(' ')'
    |IDENT '(' arg  ( ',' arg)*')';
arg : (rout_call | expr);
range : 'in' expr '..' expr;
expr: rel ('and'|'or') rel
    | 'not' rel
    | rel;
rel : sim ('<'|'<='|'=='|'!='|'>='|'>')sim
    | sim;
sim : fac  ('+'|'-') fac|fac;
fac : sum  ('*'|'%'|'/') sum
    | sum;
sum : prim | '(' expr')';
prim : ('true'|'false'|INT|mod | rout_call);
mod :   IDENT '[' expr ']'|IDENT|'[' expr ']' ;
assign : mod ':=' expr;
prim_type : 'integer'|'boolean';


WS : [ \r\t\n]+ -> skip ;
IDENT :[a-zA-Z]+;
INT : ('-')?[0-9]+;


