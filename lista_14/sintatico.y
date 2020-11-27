%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int yylex();
extern char* yytext;
extern int characters;
void yyerror(char *s);

int erro = 0;
%}

%union{
    int integer;
    float real;
    int vazio;
    int coluna;
}

/* declare tokens */
%token <integer> NUMBER
%token <real> FLOAT
%token ADD
%token SUB
%token MUL
%token DIV
%token EOL
%token UPPER
%token PERCENT
%token LPAREN
%token RPAREN
%token SEN
%token COS
%token TAN
%token ABS
%token VAR
%token ERR
%token ENDOF

%type <integer> calc
%type <vazio> exp
%type <vazio> factor
%type <vazio> term

%start calc

%%

calc: 
    exp EOL { 
        if(erro == 0){
            printf("EXPRESSAO CORRETA\n");
        } else if(erro == 1) {
            printf("]\n");
        }
        erro = 0;
        return 0;
    }
;

exp:
      factor {}
    | exp ADD factor {}
    | exp SUB factor {}
;

factor:
      unary {}
    | factor MUL unary {}
    | factor DIV unary {}
    | factor PERCENT unary {}
    | factor UPPER unary {}
;

unary: 
      functions {}
    | ADD functions {}
    | SUB functions {}
;

functions: 
      delimit {}
    | SEN LPAREN exp RPAREN {}
    | TAN LPAREN exp RPAREN {}
    | ABS LPAREN exp RPAREN {}
    | COS LPAREN exp RPAREN {}
;

delimit: 
      term {}
    | LPAREN exp RPAREN {}
;

term: 
      NUMBER {}
    | FLOAT {}
    | VAR {}
;

%%

void yyerror(char *s)
{
    if(yychar == ENDOF) {
        printf("EXPRESSAO CORRETA");
        exit(0);
    }
        
    if(yychar == ERR && erro == 0) {
        printf("Caractere(s) invalido(s) -> [%s", yytext);
        erro = 1;
    } else if(yychar == ERR && erro == 1) {
        printf(", %s", yytext);
        erro = 1;
    } else if(erro == 0 && (yychar == EOL) ) {
        printf("A expressao terminou de forma inesperada.\n");
        erro = 3;
        return;
    } else if(yychar == EOL) {
        return;
    } else if(erro == 0) {
	    printf("Erro de sintaxe na coluna [%d]: %s\n", characters - (int) strlen(yytext), yytext);
        erro = 2;
        return;
    }

}

int main(int argc, char **argv)
{
    while(yychar != ENDOF) {
        yyparse();  
        if(yychar == EOL) {            
            if(erro == 1)
                printf("]\n");
            erro = 0;
        }
    }

}
