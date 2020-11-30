%{
    #include<stdio.h>
    #include<string.h>
    extern char* yytext;
    extern int yylex();
    extern int characters;
    extern int total_lines;
    extern int last_line;

    void yyerror(char *s);
%}

%token VOID
%token INT
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token LESS_EQUAL
%token GREATER_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token ID
%token NUM_OCTAL
%token NUM_INTEGER
%token NUM_HEXA
%token STRING
%token CHARACTER
%token R_CURLY_BRACKET
%token END_OF_FILE
%token UNTERMINATED_COMMENT
%token LEXICAL_ERROR

%start program

%%

program: 
        declarations programAux END_OF_FILE    { printf("SUCCESSFUL COMPILATION."); return 0; }
    |   function programAux END_OF_FILE    { printf("SUCCESSFUL COMPILATION."); return 0; }
;

programAux: 
        program {}
    |   {}
;

declarations: 
        NUMBER_SIGN DEFINE ID expression {}
    |   varDeclaration {}
    |   protoDeclaration {}
;

function: 
        type pointer ID parameters L_CURLY_BRACKET varAux commands R_CURLY_BRACKET {}
;

pointer: 
        MULTIPLY pointer {}
    |   {}
;

varAux: 
        varDeclaration varAux {}
    |   {}
;

varDeclaration: 
        type varDeclarationAux SEMICOLON {}
;

varDeclarationAux: 
        pointer ID expressionAux atribAux {}
    |   pointer ID expressionAux atribAux COMMA varDeclarationAux {}
;

expressionAux: 
        L_SQUARE_BRACKET expression R_SQUARE_BRACKET {}
    |   {}
;

expressionAuxB:
        expression {}
    |   {}
;

atribAux: 
        ASSIGN atribExpression {}
    |   {}
;

protoDeclaration:
        type pointer ID parameters SEMICOLON {}
;

parameters: L_PAREN parametersAux R_PAREN {}
;

parametersAux: 
        type pointer ID expressionAux {}
    |   type pointer ID expressionAux COMMA parametersAuxB {}
    |   {}
;

parametersAuxB: 
        type pointer ID expressionAux {}
    |   type pointer ID expressionAux COMMA parametersAuxB {}
;

type:
        INT {}
    |   CHAR {}
    |   VOID {}
;

block:
        L_CURLY_BRACKET commands R_CURLY_BRACKET {}
;

commands:
        commandsList commands {}
    |   commandsList {}
;

commandsList:
        DO block WHILE L_PAREN expression R_PAREN SEMICOLON {}
    |   IF L_PAREN expression R_PAREN block {}
    |   IF L_PAREN expression R_PAREN block ELSE block {}
    |   WHILE L_PAREN expression R_PAREN block {}
    |   FOR L_PAREN expressionAuxB SEMICOLON expressionAuxB SEMICOLON expressionAuxB R_PAREN block {}
    |   PRINTF L_PAREN STRING R_PAREN SEMICOLON {}
    |   PRINTF L_PAREN STRING COMMA expression R_PAREN SEMICOLON {}
    |   SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON {}
    |   EXIT L_PAREN expression R_PAREN SEMICOLON {}
    |   RETURN expressionAuxB SEMICOLON {}
    |   expression SEMICOLON {}
    |   SEMICOLON {}
    |   block {}
;

expression: 
        atribExpression {}
    |   atribExpression COMMA expression {}
;

atribExpression:
        conditionalExpression {}
    |   unaryExpression operator atribExpression {}
;

operator:
        ASSIGN {}
    |   ADD_ASSIGN {}
    |   MINUS_ASSIGN {}
;

conditionalExpression:
        logicalOR {}
    |   logicalOR TERNARY_CONDITIONAL expression COLON conditionalExpression {}
;


logicalOR: 
        logicalAND {}
    |   logicalAND LOGICAL_OR logicalOR {}
;

logicalAND: 
        or LOGICAL_AND {}
    |   or {}
;

or: 
        xor BITWISE_OR or {}
    |   xor {}
;

xor: 
        and BITWISE_XOR xor {}
    |   and {}
;

and: 
        equalityExpression BITWISE_AND and {}
    |   equalityExpression {}
;

equalityExpression:
        relationalExpression comparison equalityExpression {}
    |   relationalExpression {}
;

comparison:
        EQUAL {}
    |   NOT_EQUAL {}
;

relationalExpression:
        shiftExpression {}
    |   shiftExpression comparisonAux relationalExpression {}
;

comparisonAux:
        LESS_THAN {}
    |   LESS_EQUAL {}
    |   GREATER_THAN {}
    |   GREATER_EQUAL {}
;

shiftExpression:
        aditiveExpression {}        
    |   aditiveExpression L_SHIFT shiftExpression {}
    |   aditiveExpression R_SHIFT shiftExpression {}
;

aditiveExpression:
        multiplyExpression {}
    |   multiplyExpression MINUS aditiveExpression {}
    |   multiplyExpression PLUS aditiveExpression {}
;

multiplyExpression:
        castExpression {}
    |   castExpression DIV multiplyExpression {}
    |   castExpression MULTIPLY multiplyExpression {}
    |   castExpression REMAINDER multiplyExpression {}
;

castExpression:
        unaryExpression {}
    |   L_PAREN type pointer R_PAREN castExpression {}
;

unaryExpression:
        postfixExpression {}
    |   INC unaryExpression {}
    |   DEC unaryExpression {}
    |   BITWISE_AND castExpression {}
    |   MULTIPLY castExpression {}
    |   PLUS castExpression {}
    |   MINUS castExpression {}
    |   BITWISE_NOT castExpression {}
    |   NOT castExpression {}
;

postfixExpression:
        primaryExpression {}
    |   postfixExpression L_SQUARE_BRACKET expression R_SQUARE_BRACKET {}
    |   postfixExpression INC {}
    |   postfixExpression DEC {}
    |   postfixExpression L_PAREN atribExpressionAux R_PAREN {}
;

atribExpressionAux:
        atribExpressionAuxB {}
    |   {}
;

atribExpressionAuxB: 
        atribExpression COMMA atribExpressionAuxB {}
    |   atribExpression
;

primaryExpression:
        ID {}
    |   number {}
    |   CHARACTER {}
    |   STRING {}
    |   L_PAREN expression R_PAREN {}
;

number:
        NUM_INTEGER {}
    |   NUM_HEXA {}
    |   NUM_OCTAL {}
;

%%

void yyerror(char *s) {
    int i;
    int lineNumber = 1;
    char line[1024];
    char aux;
    
    FILE* file = fseek(stdin, 0, SEEK_SET);

    switch(yychar){		
		case LEXICAL_ERROR:
			characters -= strlen(yytext);
			printf("error:lexical:%d:%d: %s", total_lines, characters, yytext);
			break;
		case END_OF_FILE:
			printf("error:syntax:%d:%d: expected declaration or statement at end of input\n", total_lines, characters);
		
			while(lineNumber < total_lines) {
                aux = fgetc(stdin);
                if(aux == '\n')
                    lineNumber++;
                if(aux == EOF)
                    break;
            }

            fgets(line, sizeof(line), stdin);
            printf("%s", line);

            for(i=1;i<characters;i++) {
				printf(" ");
            }
			printf("^");

			break;
        case UNTERMINATED_COMMENT:
			printf("error:lexical:%d:%d: unterminated comment", total_lines, characters);
			break;
		default:
			characters -= strlen(yytext);
			printf("error:syntax:%d:%d: %s\n", total_lines, characters, yytext);
			
			while(lineNumber < total_lines) {
                aux = fgetc(stdin);
                if(aux == '\n')
                    lineNumber++;
                if(aux == EOF)
                    break;
            }

            fgets(line, sizeof(line), stdin);
            printf("%s", line);

            for(i=1;i<characters;i++) {
				printf(" ");
            }
			printf("^");
			break;
	}
}

int main() {
    yyparse();

    return 0;
}