%option noyywrap
%{

#include <sintatico.tab.h>
extern YYSTYPE yylval; /* YYSTYPE eh int por padrao */

%}
%%

"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; }
"/"    { return DIV; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
\n     { return EOL; }
[ \t]  { /* espaço em branco/tabulação */  }
.      { printf("Caracter Misterioso: %c\n", *yytext); exit(0); }

%%
