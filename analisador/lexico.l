/* Nao usar a biblioteca do flex*/
%option noyywrap

%{
	#include <sintatico.tab.h>
	#include <string.h>
	int total_lines = 1;
	int characters = 1;
	int last_line;
	char identifier[200] = "";
%}

%x IDENTIFIER
%x COMMENT

%%
      
<INITIAL>{
" "						characters ++;
"void"					characters += strlen(yytext); return VOID;
"int"					characters += strlen(yytext); return INT;
"char"					characters += strlen(yytext); return CHAR;
"return"				characters += strlen(yytext); return RETURN;
"break"					characters += strlen(yytext); return BREAK;
"switch"				characters += strlen(yytext); return SWITCH;
"case"					characters += strlen(yytext); return CASE;
"default"				characters += strlen(yytext); return DEFAULT;
"do"					characters += strlen(yytext); return DO;
"while"					characters += strlen(yytext); return WHILE;
"for"					characters += strlen(yytext); return FOR;
"if"					characters += strlen(yytext); return IF;
"else"					characters += strlen(yytext); return ELSE;
"typedef"				characters += strlen(yytext); return TYPEDEF;
"struct"				characters += strlen(yytext); return STRUCT;
"+"						characters += strlen(yytext); return PLUS;
"-"						characters += strlen(yytext); return MINUS;
"*"						characters += strlen(yytext); return MULTIPLY;
"/"						characters += strlen(yytext); return DIV;
"%"						characters += strlen(yytext); return REMAINDER;
"++"					characters += strlen(yytext); return INC;
"--"					characters += strlen(yytext); return DEC;
"&"						characters += strlen(yytext); return BITWISE_AND;
"|"						characters += strlen(yytext); return BITWISE_OR;
"~"						characters += strlen(yytext); return BITWISE_NOT;
"^"						characters += strlen(yytext); return BITWISE_XOR;
"!"						characters += strlen(yytext); return NOT;
"&&"					characters += strlen(yytext); return LOGICAL_AND;
"||"					characters += strlen(yytext); return LOGICAL_OR;
"=="					characters += strlen(yytext); return EQUAL;
"!="					characters += strlen(yytext); return NOT_EQUAL;
"<"						characters += strlen(yytext); return LESS_THAN;
">"						characters += strlen(yytext); return GREATER_THAN;
"<="					characters += strlen(yytext); return LESS_EQUAL;
">="					characters += strlen(yytext); return GREATER_EQUAL;
">>"					characters += strlen(yytext); return R_SHIFT;
"<<"					characters += strlen(yytext); return L_SHIFT;
"="						characters += strlen(yytext); return ASSIGN;
"+="					characters += strlen(yytext); return ADD_ASSIGN;
"-="					characters += strlen(yytext); return MINUS_ASSIGN;
";"						characters += strlen(yytext); return SEMICOLON;
","						characters += strlen(yytext); return COMMA;
":"						characters += strlen(yytext); return COLON;
"("						characters += strlen(yytext); return L_PAREN;
")"						characters += strlen(yytext); return R_PAREN;
"{"						characters += strlen(yytext); return L_CURLY_BRACKET;
"["						characters += strlen(yytext); return L_SQUARE_BRACKET;
"]"						characters += strlen(yytext); return R_SQUARE_BRACKET;
"?"						characters += strlen(yytext); return TERNARY_CONDITIONAL;
"#"						characters += strlen(yytext); return NUMBER_SIGN;
"->"					characters += strlen(yytext); return POINTER;
"printf"				characters += strlen(yytext); return PRINTF;
"scanf"					characters += strlen(yytext); return SCANF;
"define"				characters += strlen(yytext); return DEFINE;
"exit"					characters += strlen(yytext); return EXIT;
"/*" 					last_line = total_lines; BEGIN(COMMENT);
"//".*\n				total_lines++;
[_a-zA-Z][_a-zA-Z0-9]*	characters += strlen(yytext); return ID;
"0"[0-9]+				characters += strlen(yytext); return NUM_OCTAL;
[0-9][0-9]*				characters += strlen(yytext); return NUM_INTEGER;
"0"[x|X][a-fA-F0-9]*	characters += strlen(yytext); return NUM_HEXA;
\"(\\.|[^"\\])*\"		characters += strlen(yytext); return STRING;
'([^'\\\n]|\\.)'		characters += strlen(yytext); return CHARACTER;
\t						characters += strlen(yytext);
\r
\n						total_lines++; characters = 1;
<<EOF>>					return END_OF_FILE;
"}"						characters += strlen(yytext); return R_CURLY_BRACKET;
.						return LEXICAL_ERROR;
}

<COMMENT>{
"*/"  					BEGIN(INITIAL); 
[^*\n]					
"*"       
\n        			 	total_lines ++; 
<<EOF>>  				return UNTERMINATED_COMMENT;
}

%%
