/* Nao usar a biblioteca do flex*/
%option noyywrap

%{

%}

%%

(aba)+					{ printf("(action 1) ", yytext); }
(a(b)*a)				{ printf("(action 2) ", yytext); }
(a|b)					{ printf("(action 3) ", yytext); }

%%

main(int argc, char **argv)
{
	yylex();
	return 0;
}
