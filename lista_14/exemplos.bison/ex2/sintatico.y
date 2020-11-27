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

calclist: exp EOL { printf("= %d\n\n", $1); return $1;}
        | error   { return 0; }
;

exp: factor 		 { $$ = $1;      }
	| exp ADD factor { $$ = $1 + $3; }
	| exp SUB factor { $$ = $1 - $3; }
;

factor: term          { $$ = $1;      }
	| factor MUL term { $$ = $1 * $3; }
	| factor DIV term { $$ = $1 / $3; }
;

term: NUMBER   { $$ = $1; }
;

%%

void yyerror(char *s)
{
	fprintf(stderr, "Erro de sintaxe: %s\n", yytext);
}

int main(int argc, char **argv)
{
    while(yyparse());
    return 0;
}

