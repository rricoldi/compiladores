%{
    #include<stdio.h>
    #include<string.h>
    #include <ast.h>
    
    extern char* yytext;
    extern int yylex();
    void yyerror(char *s);

    int option = -1;
    TreeNode* AST = NULL;

    enum options {
        quit
    };

%}

%union{
    int integer;
    float real;
    void* ast;
}

%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token POWER
%token REMAINDER
%token L_PAREN
%token R_PAREN
%token SEN
%token COS
%token TAN
%token ABS
%token NUM_INTEGER
%token NUM_REAL
%token VARIABLE
%token EOL
%token END_OF_FILE
%token LEXICAL_ERROR
%token SHOW;
%token SETTINGS;
%token RESET;
%token QUIT;
%token SET;
%token H_VIEW;
%token V_VIEW;
%token AXIS;
%token ON;
%token OFF;
%token PLOT;
%token INTEGRATION_STEPS;
%token INTEGRATE;
%token MATRIX;
%token SOLVE;
%token DETERMINANT;
%token LINEAR_SYSTEM;
%token ABOUT;
%token SEMICOLON;

%type <ast> calc
%type <ast> exp
%type <ast> factor
%type <ast> term
%type <integer> NUM_INTEGER

%start calc

%%


calc: exp EOL { 
    AST = $1; 
    if(AST)
    {
        RPN_Walk(AST);
        Delete_Tree(AST);
    }
    else
    {
        printf("AST is NULL\n");
    }
    return 0;
}
    | QUIT { 
        option = quit;
        return 0;
    }
;

exp: factor { $$ = $1;}
    | exp PLUS factor {
        TreeNode* aux = createNode(PLUS, 0, $1, $3);
        $$ = aux;
    }
    | exp MINUS factor {
        TreeNode* aux = createNode(MINUS, 0, $1, $3);
        aux->right = $3;
        $$ = aux;
    }
;

factor: term { $$ = $1; }
    | factor MULTIPLY term {
        TreeNode* aux = createNode(MULTIPLY, 0, $1, $3);                       
        $$ = aux;
    }
    | factor DIV term {
        TreeNode* aux = createNode(DIV, 0, $1, $3);
        $$ = aux;
    }
;

term: NUM_INTEGER { 
    TreeNode* aux = createNode(NUM_INTEGER, $1, NULL, NULL);
    $$ = aux;
}
;

%%

void yyerror(char *s) {
    option = quit;
}

int main() {
    // #ifdef YYDEBUG
    //     yydebug = 1;
    // #endif


    do {
        printf("> ");
        yyparse();
    
        switch (option) {
            case quit:
                return 0;
            default:
                break;
        }
        printf("\n");
    } while(option != quit);
    
    return 0;
}