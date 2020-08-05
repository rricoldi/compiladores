/* Nao usar a biblioteca do flex*/
%option noyywrap

%{
	#include <string.h>
	int total_lines = 1;
	int last_line;
	int characters = 1;
	int id_counter = 0;
	int token_counter = 0;
	char identifier[200] = "";
%}

%x IDENTIFIER
%x COMMENT

%%
      
<INITIAL>{
" "						characters ++;
"void"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("VOID"); characters += strlen(yytext);
"int"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("INT"); characters += strlen(yytext);
"char"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("CHAR"); characters += strlen(yytext);
"return"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("RETURN"); characters += strlen(yytext);
"break"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("BREAK"); characters += strlen(yytext);
"switch"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("SWITCH"); characters += strlen(yytext);
"case"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("CASE"); characters += strlen(yytext);
"default"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("DEFAULT"); characters += strlen(yytext);
"do"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("DO"); characters += strlen(yytext);
"while"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("WHILE"); characters += strlen(yytext);
"for"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("FOR"); characters += strlen(yytext);
"if"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("IF"); characters += strlen(yytext);
"else"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("ELSE"); characters += strlen(yytext);
"typedef"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("TYPEDEF"); characters += strlen(yytext);
"struct"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("STRUCT"); characters += strlen(yytext);
"+"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("PLUS"); characters += strlen(yytext);
"-"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("MINUS"); characters += strlen(yytext);
"*"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("MULTIPLY"); characters += strlen(yytext);
"/"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("DIV"); characters += strlen(yytext);
"%"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("REMAINDER"); characters += strlen(yytext);
"++"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("INC"); characters += strlen(yytext);
"--"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("DEC"); characters += strlen(yytext);
"&"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("BITWISE_AND"); characters += strlen(yytext);
"|"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("BITWISE_OR"); characters += strlen(yytext);
"~"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("BITWISE_NOT"); characters += strlen(yytext);
"^"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("BITWISE_XOR"); characters += strlen(yytext);
"!"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("NOT"); characters += strlen(yytext);
"&&"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("LOGICAL_AND"); characters += strlen(yytext);
"||"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("LOGICAL_OR"); characters += strlen(yytext);
"=="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("EQUAL"); characters += strlen(yytext);
"!="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("NOT_EQUAL"); characters += strlen(yytext);
"<"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("LESS_THAN"); characters += strlen(yytext);
">"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("GREATER_THAN"); characters += strlen(yytext);
"<="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("LESS_EQUAL"); characters += strlen(yytext);
">="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("GREATER_EQUAL"); characters += strlen(yytext);
">>"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("R_SHIFT"); characters += strlen(yytext);
"<<"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("L_SHIFT"); characters += strlen(yytext);
"="						if(token_counter > 0) { printf("\n"); } token_counter++; printf("ASSIGN"); characters += strlen(yytext);
"+="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("ADD_ASSIGN"); characters += strlen(yytext);
"-="					if(token_counter > 0) { printf("\n"); } token_counter++; printf("MINUS_ASSIGN"); characters += strlen(yytext);
";"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("SEMICOLON"); characters += strlen(yytext);
","						if(token_counter > 0) { printf("\n"); } token_counter++; printf("COMMA"); characters += strlen(yytext);
":"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("COLON"); characters += strlen(yytext);
"("						if(token_counter > 0) { printf("\n"); } token_counter++; printf("L_PAREN"); characters += strlen(yytext);
")"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("R_PAREN"); characters += strlen(yytext);
"{"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("L_CURLY_BRACKET"); characters += strlen(yytext);
"["						if(token_counter > 0) { printf("\n"); } token_counter++; printf("L_SQUARE_BRACKET"); characters += strlen(yytext);
"]"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("R_SQUARE_BRACKET"); characters += strlen(yytext);
"?"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("TERNARY_CONDITIONAL"); characters += strlen(yytext);
"#"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("NUMBER_SIGN"); characters += strlen(yytext);
"->"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("POINTER"); characters += strlen(yytext);
"printf"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("PRINTF"); characters += strlen(yytext);
"scanf"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("SCANF"); characters += strlen(yytext);
"define"				if(token_counter > 0) { printf("\n"); } token_counter++; printf("DEFINE"); characters += strlen(yytext);
"exit"					if(token_counter > 0) { printf("\n"); } token_counter++; printf("EXIT"); characters += strlen(yytext);
"/*" 					last_line = total_lines; BEGIN(COMMENT);
"//".*\n				total_lines++;
[_a-zA-Z][_a-zA-Z0-9]*	if(token_counter > 0) { printf("\n"); } token_counter++; printf("IDENTIFIER(%s)", yytext); characters += strlen(yytext);
"0"[0-9]+				if(token_counter > 0) { printf("\n"); } token_counter++; printf("NUM_OCTAL(%s)", yytext); characters += strlen(yytext);
[0-9][0-9]*				if(token_counter > 0) { printf("\n"); } token_counter++; printf("NUM_INTEGER(%s)", yytext); characters += strlen(yytext);
"0"[x|X][a-fA-F0-9]*	if(token_counter > 0) { printf("\n"); } token_counter++; printf("NUM_HEXA(%s)", yytext); characters += strlen(yytext);
\"(\\.|[^"\\])*\"		if(token_counter > 0) { printf("\n"); } token_counter++; printf("STRING("); for(last_line=1;last_line<strlen(yytext)-1;last_line++) { printf("%c", yytext[last_line]); } printf(")"); characters += strlen(yytext);
'([^'\\\n]|\\.)'		if(token_counter > 0) { printf("\n"); } token_counter++; printf("CHARACTER("); for(last_line=1;last_line<strlen(yytext)-1;last_line++) { printf("%c", yytext[last_line]); } printf(")"); characters += strlen(yytext);
\t						characters += strlen(yytext);
\r
\n						total_lines++; characters = 1;
"}"						if(token_counter > 0) { printf("\n"); } token_counter++; printf("R_CURLY_BRACKET"); characters += strlen(yytext);
.						if(token_counter > 0) { printf("\n"); } token_counter++; printf("error:lexical:%d:%d: %s", total_lines, characters, yytext); characters ++;
}

<COMMENT>{
"*/"  					BEGIN(INITIAL); 
[^*\n]					
"*"       
\n        			 	total_lines ++; 
<<EOF>>  				if(token_counter > 0) { printf("\n"); } token_counter++; printf("error:lexical:%d:%d: unterminated comment", last_line, characters); BEGIN(INITIAL);
}

%%

int main(int argc, char **argv) {
	yylex();
	return 0;
}
