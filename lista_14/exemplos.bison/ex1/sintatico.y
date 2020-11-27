%{

#include <stdio.h>
extern int yylex();
extern char* yytext;
void yyerror(char *s);

%}

/* declare tokens */
%token NUMBER
%token ADD
%token SUB
%token MUL
%token DIV
%token EOL

%start calclist

%%

calclist: exp EOL { printf("Cadeia Aceita.\n"); return 0; }
;

exp: factor 		 { }
	| exp ADD factor { }
	| exp SUB factor { }
;

factor: term          { }
	| factor MUL term { }
	| factor DIV term { }
;

term: NUMBER   { }
;

%%

void yyerror(char *s)
{
	fprintf(stderr, "Error de Sintaxe: %s\n", yytext);
}

int main(int argc, char **argv)
{
    yyparse();
    return 0;
}
