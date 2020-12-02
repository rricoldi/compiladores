%{
    #include<stdio.h>
    #include<string.h>
    #include <ast.h>
    #include <settings.h>

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

    enum options {
        error = -1,
        quit,
        show_settings,
        reset_settings,
        set_h_view,
        set_v_view,
        set_axis_on,
        set_axis_off,
        plot,
        plot_fn,
        rpn,
        set_integral_steps,
        integrate,
        matrix,
        show_matrix,
        solve_determinant,
        solve_linear_system,
        about
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
%type <real> float
%type <integer> int
%type <integer> NUM_INTEGER
%type <real> NUM_REAL

%start calc

%%
                                                                                                                    // FUNCIONALIDADE | ERROS

calc: exp EOL {                                                                                                                 // ⏳ | ⏳        
        option = rpn;
        return 0;
    }
    | QUIT EOL {                                                                                                                // ✅ | ✅ 
        option = quit;
        return 0;
    }
    | SHOW SETTINGS SEMICOLON EOL {                                                                                             // ✅ | ✅ 
        option = show_settings;
        return 0;
    }
    | RESET SETTINGS SEMICOLON EOL {                                                                                            // ✅ | ✅ 
        option = reset_settings;
        return 0;
    }
    | SET H_VIEW float COLON float SEMICOLON EOL {                                                                              // ✅ | ✅
        if($5 <= $3) {
            yyerror(error_h_view);
            YYERROR;
        }

        settings->h_view_lo = $3;
        settings->h_view_hi = $5;

        option = set_h_view;
        return 0;
    }
    | SET V_VIEW float COLON float SEMICOLON EOL {                                                                              // ✅ | ✅
        if($5 <= $3) {
            yyerror(error_v_view);
            YYERROR;
        }
        
        settings->v_view_lo = $3;
        settings->v_view_hi = $5;

        option = set_v_view;
        return 0;
    }
    | SET AXIS ON SEMICOLON EOL {                                                                                               // ✅ | ⏳
        settings->draw_axis = 1;

        option = set_axis_on;
        return 0;
    }
    | SET AXIS OFF SEMICOLON EOL {                                                                                              // ✅ | ⏳
        settings->draw_axis = 0;

        option = set_axis_off;
        return 0;
    }
    | PLOT SEMICOLON EOL {                                                                                                      // ⏳ | ⏳
        option = plot;
        return 0;
    } PLOT L_PAREN exp R_PAREN SEMICOLON EOL {                                                                                  // ⏳ | ⏳
        option = plot_fn;
        return 0;
    }
    | SET INTEGRAL_STEPS int SEMICOLON EOL {                                                                                    // ✅ | ✅
        if($3 < 1) {
            yyerror(error_set_int);
            YYERROR;
        }
        settings->integral_steps = $3;

        option = set_integral_steps;
        return 0;
    }
    | INTEGRATE L_PAREN float COLON float COMMA exp R_PAREN SEMICOLON EOL {                                                     // ⏳ | ⏳
        option = integrate;
        return 0;
    }
    | MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET float matrixAux R_SQUARE_BRACKET matrix R_SQUARE_BRACKET SEMICOLON EOL {  // ⏳ | ⏳
        option = matrix;
        return 0;
    }
    | SHOW MATRIX SEMICOLON EOL {                                                                                               // ⏳ | ⏳
        option = show_matrix;
        return 0;
    }
    | SOLVE DETERMINANT SEMICOLON EOL {                                                                                         // ⏳ | ⏳
        option = solve_determinant;
        return 0;
    }
    | SOLVE LINEAR_SYSTEM SEMICOLON EOL {                                                                                       // ⏳ | ⏳
        option = solve_linear_system;
        return 0;
    }
    | ABOUT SEMICOLON EOL {                                                                                                     // ✅ | ✅
        option = about;
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

exp: factor {}
    | exp PLUS factor {}
    | exp MINUS factor {}
;

factor: operator {}
    | factor DIV operator {}
    | factor MULTIPLY operator {}
;

operator: signed {}
    | operator REMAINDER signed {}
    | operator POWER signed {}
;

signed: function {} 
    | PLUS function {}  
    | MINUS function {} 
;

function: delimit {}
    | SEN L_PAREN exp R_PAREN {}
    | COS L_PAREN exp R_PAREN {}
    | TAN L_PAREN exp R_PAREN {}
    | ABS L_PAREN exp R_PAREN {}
;

delimit: term {}
    | L_PAREN exp R_PAREN {}
;

term: NUM_INTEGER {}
    | NUM_REAL {}
    | VARIABLE {}
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
    
        switch (option) {
            case quit:
                return 0;
            case show_settings:
                showSettings(settings);
                break;
            case reset_settings:
                setDefaultSettings(settings);
                break;
            case about:
                printAbout();
                break;
            default:
                break;
        }
        // printf("\n");
    } while(option != quit);
    
    return 0;
}