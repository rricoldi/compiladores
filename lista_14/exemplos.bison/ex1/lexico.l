%option noyywrap
%{

#include <sintatico.tab.h>

%}
%%

"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; }
"/"    { return DIV; }
[0-9]+ { return NUMBER; }
\n     { return EOL; }
[ \t]  { /* espaço em branco/tabulação */  }
.      { printf("Caracter Misterioso: %c\n", *yytext); exit(0); }

%%
