%option noyywrap
%{

#include <ast.h>
#include <sintatico.tab.h>

%}
%%

"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; }
"/"    { return DIV; }
[0-9]+ { yylval.integer = atoi(yytext); return NUMBER; }
\n     { return EOL; }
[ \t]  { /* espaço em branco/tabulação */  }
.      { printf("Caracter Misterioso: %c\n", *yytext); exit(0); }

%%
