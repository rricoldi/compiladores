%{
    #include<stdio.h>
    #include<string.h>
    #include "hash.h"

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    extern int line;


    enum types { integer, real, character };
    int type = integer;
    int error;
    int primeira_linha = 1;

    char* getType();
    void verificaSeImprime();
    Hash tab;
%}

%token INT
%token CHAR
%token FLOAT
%token ID
%token COMMA
%token EOL
%token ENDOF

%start program

%%

program:
        D D_ EOL { if(error == 0) { verificaSeImprime(); printf("%d: All Identifiers on Hash.", line);} return 0; }
;

D_:
        D D_ {}
    |   {}
;

D:
        T I {}
;

T:
        INT { type = integer; }
    |   FLOAT { type = real; }
    |   CHAR { type = character; }
;

I:
        ID { 
            Dados* item = buscaHash(tab, yytext); 
            if(item != NULL) { 
                verificaSeImprime(); 
                error = 1; 
                if(item->type == type) { 
                    printf("%d: identifier \'%s\' already declared", line, yytext);
                } else { 
                    printf("%d: redefinition of identifier \'%s\'", line, yytext); 
                } 
            } else { 
                insereHash(tab, type, yytext); 
            } 
        }
    |   I COMMA ID { 
            Dados* item = buscaHash(tab, yytext); 
            if(item != NULL) { 
                verificaSeImprime(); 
                error = 1; 
                if(item->type == type) { 
                    printf("%d: identifier \'%s\' already declared", line, yytext); 
                } else { 
                    printf("%d: redefinition of identifier \'%s\'", line, yytext); 
                } 
            } else { 
                insereHash(tab, type, yytext); 
            } 
        }
;

%%

void yyerror (char *s) {
}

void verificaSeImprime() {
    if(primeira_linha) {
        primeira_linha = 0;
    } else {
        printf("\n");
    }
}

char* getType() {
    switch(type) {
        case integer:
            return "int";
        case real:
            return "float";
        case character:
            return "char";
        default:
            return "error";
    }
}

int main() {
    while(yychar != ENDOF) {
        error = 0;
        inicializaHash(tab);
        yyparse();
    }

    return 0;
}