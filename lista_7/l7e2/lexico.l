/* Nao usar a biblioteca do flex*/
%option noyywrap

%{
#include <string.h>
%}

%%

"if"					{ printf("IF\n"); }
[a-z][a-z0-9]* 			{ printf("%s ID\n",yytext); }
"-""-"[a-z]*[\n]        { yytext[strlen(yytext) - 1] = '\0'; printf("%s comment\n", yytext); }
[0-9]+ 	         		{ printf("%s NUM\n",yytext); }
[0-9]"."[0-9]* 			{ printf("%s REAL\n",yytext); }
"."[0-9]+				{ printf("%s REAL\n",yytext); }
" "						{ printf("white space\n"); }
[\n]       				
.			          	{ printf("%s error\n", yytext); }

%%

main(int argc, char **argv)
{
	yylex();
	return 0;
}
