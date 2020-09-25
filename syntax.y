%{
    #include"lex.yy.c"
    void yyerror(const char *s){}
    int result;
%}
%token LP RP LB RB LC RC
%%
String: 
    | String Sub { result = $2; }
    ;
Sub: LP Sub RP Sub { $$ = $2 * $4; }
    | LB Sub RB Sub { $$ = $2 * $4; }
    | LC Sub RC Sub { $$ = $2 * $4; }
    | S Sub { $$ = 0; }
    | { $$ = 1; }
    ;
S: LP
    | RP
    | LB
    | RB
    | LC
    | RC
    ;
%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}
