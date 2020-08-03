/* Nao usar a biblioteca do flex*/
%option noyywrap

%{
	#include <string.h>
	int total_lines = 1;
	int characters = 1;
	int id_counter = 0;
	char identifier[200] = "";
%}

%x IDENTIFIER
%x COMMENT

%%
      
<INITIAL>{
" "						characters ++;
"void"					printf("VOID\n"); characters += strlen(yytext);
"int"					printf("INT\n"); characters += strlen(yytext);
"char"					printf("CHAR\n"); characters += strlen(yytext);
"return"				printf("RETURN\n"); characters += strlen(yytext);
"break"					printf("BREAK\n"); characters += strlen(yytext);
"switch"				printf("SWITCH\n"); characters += strlen(yytext);
"case"					printf("CASE\n"); characters += strlen(yytext);
"default"				printf("DEFAULT\n"); characters += strlen(yytext);
"do"					printf("DO\n"); characters += strlen(yytext);
"while"					printf("WHILE\n"); characters += strlen(yytext);
"for"					printf("FOR\n"); characters += strlen(yytext);
"if"					printf("IF\n"); characters += strlen(yytext);
"else"					printf("ELSE\n"); characters += strlen(yytext);
"typedef"				printf("TYPEDEF\n"); characters += strlen(yytext);
"struct"				printf("STRUCT\n"); characters += strlen(yytext);
"+"						printf("PLUS\n"); characters += strlen(yytext);
"-"						printf("MINUS\n"); characters += strlen(yytext);
"*"						printf("MULTIPLY\n"); characters += strlen(yytext);
"/"						printf("DIV\n"); characters += strlen(yytext);
"%"						printf("REMAINDER\n"); characters += strlen(yytext);
"++"					printf("INC\n"); characters += strlen(yytext);
"--"					printf("DEC\n"); characters += strlen(yytext);
"&"						printf("BITWISE	_AND\n"); characters += strlen(yytext);
"|"						printf("BITWISE_OR\n"); characters += strlen(yytext);
"~"						printf("BITWISE_NOT\n"); characters += strlen(yytext);
"^"						printf("BITWISE_XOR\n"); characters += strlen(yytext);
"!"						printf("NOT\n"); characters += strlen(yytext);
"&&"					printf("LOGICAL_AND\n"); characters += strlen(yytext);
"||"					printf("LOGICAL_OR\n"); characters += strlen(yytext);
"=="					printf("EQUAL\n"); characters += strlen(yytext);
"!="					printf("NOT_EQUAL\n"); characters += strlen(yytext);
"<"						printf("LESS_THAN\n"); characters += strlen(yytext);
">"						printf("GREATER_THAN\n"); characters += strlen(yytext);
"<="					printf("LESS_EQUAL\n"); characters += strlen(yytext);
">="					printf("GREATER_EQUAL\n"); characters += strlen(yytext);
">>"					printf("R_SHIFT\n"); characters += strlen(yytext);
"<<"					printf("L_SHIFT\n"); characters += strlen(yytext);
"="						printf("ASSIGN\n"); characters += strlen(yytext);
"+="					printf("ADD_ASSIGN\n"); characters += strlen(yytext);
"-="					printf("MINUS_ASSIGN\n"); characters += strlen(yytext);
";"						printf("SEMICOLON\n"); characters += strlen(yytext);
","						printf("COMMA\n"); characters += strlen(yytext);
":"						printf("COLON\n"); characters += strlen(yytext);
"("						printf("L_PAREN\n"); characters += strlen(yytext);
")"						printf("R_PAREN\n"); characters += strlen(yytext);
"{"						printf("L_CURLY_BRACKET\n"); characters += strlen(yytext);
"????"					printf("R_CURLY_BRACKET\n"); characters += strlen(yytext);
"["						printf("L_SQUARE_BRACKET\n"); characters += strlen(yytext);
"]"						printf("R_SQUARE_BRACKET\n"); characters += strlen(yytext);
"?"						printf("TERNARY_CONDITIONAL\n"); characters += strlen(yytext);
"#"						printf("NUMBER_SIGN\n"); characters += strlen(yytext);
"->"					printf("POINTER\n"); characters += strlen(yytext);
"printf"				printf("PRINTF\n"); characters += strlen(yytext);
"scanf"					printf("SCANF\n"); characters += strlen(yytext);
"define"				printf("DEFINE\n"); characters += strlen(yytext);
"exit"					printf("EXIT\n"); characters += strlen(yytext);
"/*" 					BEGIN(COMMENT);
"//".*\n				total_lines++;
[_a-zA-Z][_a-zA-Z0-9]*	printf("IDENTIFIER(%s)\n", yytext); characters += strlen(yytext);
\n						total_lines++; characters = 1;
.						characters ++;
}

<COMMENT>{
"*/"  					BEGIN(INITIAL); 
([^*]|\n)+				total_lines++;		
<<EOF>>  				printf("error:lexical:%d:%d: unterminated comment\n", total_lines, characters); BEGIN(INITIAL);
.
}

%%

int main(int argc, char **argv) {
	yylex();
	return 0;
}
