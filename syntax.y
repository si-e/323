%{
    #include"lex.yy.c"
    void yyerror(const char *s){}
    int result;
%}
%token LP RP LB RB LC RC
%%
String: LP String RP {}
    | LB String RB {}
    | LC String RC {}
    | LP RP {}
    | LB RB {}
    | LC RC {}
    ;
%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}
