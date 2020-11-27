%option noyywrap
%{
#include <ast.h>

#include <sintatico.tab.h>
int characters = 1;
%}
%%

" "	    { characters += strlen(yytext); }
"+"     { characters += strlen(yytext); return ADD; }
"-"     { characters += strlen(yytext); return SUB; }
"*"     { characters += strlen(yytext); return MUL; }
"/"     { characters += strlen(yytext); return DIV; }
"^"     { characters += strlen(yytext); return UPPER; }
"%"     { characters += strlen(yytext); return PERCENT; }
"("     { characters += strlen(yytext); return LPAREN; }
")"     { characters += strlen(yytext); return RPAREN; }
"sen"   { characters += strlen(yytext); return SEN; }
"cos"   { characters += strlen(yytext); return COS; }
"tan"   { characters += strlen(yytext); return TAN; }
"abs"   { characters += strlen(yytext); return ABS; }
[a-z][a-z0-9]* { return VAR; characters += strlen(yytext); } 
[0-9]+  { yylval.integer = atoi(yytext); return NUMBER; characters += strlen(yytext); }
[0-9]+"."[0-9]* | 
"."[0-9]+ {  yylval.real = atof(yytext); return FLOAT; }

\n      { characters = 1; return EOL; }
[ \t]   { characters += strlen(yytext); }
<<EOF>> { return ENDOF; }
.       { return ERR; }

%%
