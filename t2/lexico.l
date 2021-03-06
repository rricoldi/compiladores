%option noyywrap

%{
	#include <sintatico.tab.h>
	
	void clearBuffer();
%}

%%
      
" "

"+"						return PLUS;
"-"						return MINUS;
"*"						return MULTIPLY;
"/"						return DIV;
"^"						return POWER;
"%"						return REMAINDER;

"("						return L_PAREN;
")"						return R_PAREN;
"["						return L_SQUARE_BRACKET;
"]"						return R_SQUARE_BRACKET;

"sen"					return SEN;
"cos"					return COS;
"tan"					return TAN;
"abs"					return ABS;

"show"					return SHOW;
"settings"				return SETTINGS;
"reset"					return RESET;
"quit"					return QUIT;
"set"					return SET;
"h_view"				return H_VIEW;
"v_view"				return V_VIEW;
"axis"					return AXIS;
"on"					return ON;
"off"					return OFF;
"plot"					return PLOT;
"integral_steps"		return INTEGRAL_STEPS;
"integrate"				return INTEGRATE;
"matrix"				return MATRIX;
"solve"					return SOLVE;
"determinant"			return DETERMINANT;
"linear_system"			return LINEAR_SYSTEM;
"about"					return ABOUT;



[0-9]+"."[0-9]+			yylval.real = atof(yytext); return NUM_REAL;
[0-9]+					yylval.integer = atoi(yytext); return NUM_INTEGER;

"="						return ASSIGN;
";"						return SEMICOLON;
":"						return COLON;
","						return COMMA;
"x"						return VARIABLE;

[ \t]
\r
\n						return EOL;

<<EOF>>					return END_OF_FILE;

.						return LEXICAL_ERROR;

%%

void clearBuffer() {
	yy_flush_buffer(YY_CURRENT_BUFFER);
}