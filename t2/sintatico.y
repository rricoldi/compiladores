%{
    #include<stdio.h>
    #include<string.h>
    #include <ast.h>

    extern char* yytext;
    extern int yylex();
    extern void clearBuffer();
    void yyerror(char *s);

    int option = -2;
    int auxInt;
    float auxFloat;
    int linhas = 25;
    int colunas = 80;

    char error_matrix[] = "ERROR: Matrix limits out of boundaries.";
    char error_v_view[] = "ERROR: v_view_lo must be smaller than v_view_hi";
    char error_h_view[] = "ERROR: h_view_lo must be smaller than h_view_hi";
    char error_set_int[] = "ERROR: integral_steps must be a positive non-zero integer";
    char error_integrate[] = "ERROR: lower limit must be smaller than upper limit";
    char error_determinant[] = "Matrix format incorrect!";
    char error_linear[] = "Matrix format incorrect!";


    TreeNode* AST = NULL;
    TreeNode* AST_TEMP = NULL;
    Settings* settings = NULL;

    int error = -1;
    int quit = 0;
    int functionInserted = 0;

    void printAbout();

%}

%union{
    int integer;
    float real;
    void* ast;
}

%token PLUS
%token MINUS
%token ADD
%token SUB
%token MULTIPLY
%token DIV
%token POWER
%token REMAINDER
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
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
%token INTEGRAL_STEPS;
%token INTEGRATE;
%token MATRIX;
%token SOLVE;
%token DETERMINANT;
%token LINEAR_SYSTEM;
%token ABOUT;
%token ASSIGN
%token SEMICOLON;
%token COLON;
%token COMMA;

%type <ast> calc
%type <ast> exp
%type <ast> factor
%type <ast> term
%type <ast> operator
%type <ast> signed
%type <ast> function
%type <ast> delimit
%type <real> float
%type <integer> int
%type <integer> NUM_INTEGER
%type <real> NUM_REAL

%start calc

%%
                                                                                                                    // FUNCIONALIDADE | ERROS

calc: exp EOL {                                                                                                                 // ✅ | ✅ 
        AST_TEMP = $1;
        if(AST_TEMP)
        {
            printf("\nFunction in RPN format:\n\n");
            RPN_Walk(AST_TEMP);
            Delete_Tree(AST_TEMP);
            printf("\n\n");
        }
        return 0;
    }
    | QUIT EOL {                                                                                                                // ✅ | ✅ 
        option = quit;
        return 0;
    }
    | SHOW SETTINGS SEMICOLON EOL {                                                                                             // ✅ | ✅ 
        showSettings(settings);    
        return 0;
    }
    | RESET SETTINGS SEMICOLON EOL {                                                                                            // ✅ | ✅ 
        setDefaultSettings(settings);        
        return 0;
    }
    | SET H_VIEW float COLON float SEMICOLON EOL {                                                                              // ✅ | ✅
        if($5 <= $3) {
            yyerror(error_h_view);
            YYERROR;
        }

        settings->h_view_lo = $3;
        settings->h_view_hi = $5;
        
        return 0;
    }
    | SET V_VIEW float COLON float SEMICOLON EOL {                                                                              // ✅ | ✅
        if($5 <= $3) {
            yyerror(error_v_view);
            YYERROR;
        }
        
        settings->v_view_lo = $3;
        settings->v_view_hi = $5;
        
        return 0;
    }
    | SET AXIS ON SEMICOLON EOL {                                                                                               // ✅ | ✅ 
        settings->draw_axis = 1;
        
        return 0;
    }
    | SET AXIS OFF SEMICOLON EOL {                                                                                              // ✅ | ✅ 
        settings->draw_axis = 0;
        
        return 0;
    }
    | PLOT SEMICOLON EOL {                                                                                                      // ⏳ | ⏳        
        if(!functionInserted) {
            printf("\nNo Function defined!\n\n");
        }
        return 0;
    } PLOT L_PAREN exp R_PAREN SEMICOLON EOL {                                                                                  // ⏳ | ⏳        
        return 0;
    }
    | SET INTEGRAL_STEPS int SEMICOLON EOL {                                                                                    // ✅ | ✅
        if($3 < 1) {
            yyerror(error_set_int);
            YYERROR;
        }
        settings->integral_steps = $3;
        
        return 0;
    }
    | INTEGRATE L_PAREN float COLON float COMMA exp R_PAREN SEMICOLON EOL {                                                     // ⏳ | ⏳        
        AST = $7;
        functionInserted = 1;
        if(AST)
        {
            printf("\n%6f\n\n", integrate($3, $5, AST, settings));
        }
        return 0;
    }
    | MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET float matrixAux R_SQUARE_BRACKET matrix R_SQUARE_BRACKET SEMICOLON EOL {  // ⏳ | ⏳        
        return 0;
    }
    | SHOW MATRIX SEMICOLON EOL {                                                                                               // ⏳ | ⏳        
        return 0;
    }
    | SOLVE DETERMINANT SEMICOLON EOL {                                                                                         // ⏳ | ⏳        
        return 0;
    }
    | SOLVE LINEAR_SYSTEM SEMICOLON EOL {                                                                                       // ⏳ | ⏳        
        return 0;
    }
    | ABOUT SEMICOLON EOL {                                                                                                     // ✅ | ✅
        printAbout();        
        return 0;
    }
;

matrix: COMMA L_SQUARE_BRACKET float matrixAux R_SQUARE_BRACKET matrix {
    }
    | {}
;

matrixAux: COMMA float matrixAux {

    }
    | {}
;


exp: factor { $$ = $1; }
    | exp PLUS factor {
        TreeNode* aux = createNode(ADD, 0.0, $1, $3);
        $$ = aux;
    }
    | exp MINUS factor {
        TreeNode* aux = createNode(SUB, 0.0, $1, $3);
        $$ = aux;
    }
;

factor: operator { $$ = $1; }
    | factor DIV operator {
        TreeNode* aux = createNode(DIV, 0.0, $1, $3);
        $$ = aux;
    }
    | factor MULTIPLY operator {
        TreeNode* aux = createNode(MULTIPLY, 0.0, $1, $3);
        $$ = aux;
    }
;

operator: signed { $$ = $1; }
    | operator REMAINDER signed {
        TreeNode* aux = createNode(REMAINDER, 0.0, $1, $3);
        $$ = aux;
    }
    | operator POWER signed {
        TreeNode* aux = createNode(POWER, 0.0, $1, $3);
        $$ = aux;
    }
;

signed: function { $$ = $1; } 
    | PLUS function {
        TreeNode* aux = createNode(PLUS, 0.0, NULL, $2);
        $$ = aux;
    }  
    | MINUS function {
        TreeNode* aux = createNode(MINUS, 0.0, NULL, $2);
        $$ = aux;
    } 
;

function: delimit { $$ = $1; }
    | SEN L_PAREN exp R_PAREN {
        TreeNode* aux = createNode(SEN, 0.0, NULL, $3);
        $$ = aux;
    }
    | COS L_PAREN exp R_PAREN {
        TreeNode* aux = createNode(COS, 0.0, NULL, $3);
        $$ = aux;
    }
    | TAN L_PAREN exp R_PAREN {
        TreeNode* aux = createNode(TAN, 0.0, NULL, $3);
        $$ = aux;
    }
    | ABS L_PAREN exp R_PAREN {
        TreeNode* aux = createNode(ABS, 0.0, NULL, $3);
        $$ = aux;
    }
;

delimit: term { $$ = $1; }
    | L_PAREN exp R_PAREN {
        TreeNode* aux = createNode(L_PAREN, 0.0, NULL, $2);
        $$ = aux;
    }
;

term: NUM_INTEGER {
        TreeNode* aux = createNode(NUM_INTEGER, $1 * 1.0, NULL, NULL);
        $$ = (TreeNode*) aux;
    }
    | NUM_REAL {
        TreeNode* aux = createNode(NUM_REAL, $1, NULL, NULL);
        $$ = (TreeNode*) aux;
    }
    | VARIABLE {
        TreeNode* aux = createNode(VARIABLE, 0.0, NULL, NULL);
        $$ = (TreeNode*) aux;
    }
;

float: NUM_REAL {
        $$ = $1;
    }
    | MINUS NUM_REAL {
        $$ = -$2;
    }
    | PLUS NUM_REAL {
        $$ = $2;
    }
    | NUM_INTEGER {
        $$ = $1 * 1.0;
    }
    | MINUS NUM_INTEGER {
        $$ = -$2 * 1.0;
    }
    | PLUS NUM_INTEGER {
        $$ = $2 * 1.0;
    }
;

int: NUM_INTEGER {
        $$ = $1;
    }
    | MINUS NUM_INTEGER {
        $$ = -$2;
    }
    | PLUS NUM_INTEGER {
        $$ = $2;
    }
;

%%

void yyerror(char *s) {
    switch(yychar) {
        case LEXICAL_ERROR:
            printf("Simbolo Invalido -> %s\n\n", yytext);
            option = error;
			break;
        case EOL:
            break;
        default:
            if(!strcmp(s, "syntax error"))
                printf("Erro de Sintaxe: [%s]\n\n", yytext);
            else
                printf("%s\n\n", s);
            option = error;
			break;
    }

    clearBuffer();
}

void printAbout() {
    int i;

    printf("\n+");
    for(i=1;i<colunas-1;i++) {
        printf("-");
    }
    printf("+");
    
    printf("\n|");
    for(i=1;i<colunas-1;i++) {
        printf(" ");
    }
    printf("|");
    
    printf("|                   201800560608 - Renan Ricoldi Fróis Pedro                   |");

    printf("\n|");
    for(i=1;i<colunas-1;i++) {
        printf(" ");
    }
    printf("|");

    printf("\n+");
    for(i=1;i<colunas-1;i++) {
        printf("-");
    }
    printf("+\n\n");
}

int main() {
    // #ifdef YYDEBUG
    //     yydebug = 1;
    // #endif
    settings = createSettings();

    do {
        // if(option != error)
        printf(">");
        yyparse();
    
        // switch (option) {
        //     case quit:
        //         return 0;
        //     case rpn:
        //         printf("\n");
        //     default:
        //         break;
        // }
        // // printf("\n");
    } while(option != quit);
    
    return 0;
}