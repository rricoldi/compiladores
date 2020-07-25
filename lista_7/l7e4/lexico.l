/* Nao usar a biblioteca do flex*/
%option noyywrap

%{
	#include <string.h>
	int total_lines = 1;
	int blank_lines = 0;
	int lines_with_comments = 0;
	int code_lines = 0;
	int semi_colons = 0;
	int direct = 0;
	int total_total_lines = 0;
	int total_blank_lines = 0;
	int total_lines_with_comments = 0;
	int total_code_lines = 0;
	int total_semi_colons = 0;
	int total_direct = 0;
%}
%x IN_COMMENT
    

%%
      
<INITIAL>{
"/*"              		BEGIN(IN_COMMENT);	   
";"			          	semi_colons ++;
"#include"				direct ++;
"#define"				direct ++;
"//"					lines_with_comments ++;
^[ ]*[\n]				blank_lines ++; total_lines ++; 
[\n]       				total_lines ++;
.
}

<IN_COMMENT>{
"*/"      lines_with_comments++; BEGIN(INITIAL);
[^*\n]+    
"*"       
\n        lines_with_comments++; total_lines ++; 
}

%%

void retorna_formatado(int value, int aditional) {
	int spaces = 0;
	int i;
	char response[10];

	if(value < 10)
		spaces = 5;
	else if(value < 100)
		spaces = 4;
	else if(value < 1000)
		spaces = 3;
	else if(value < 10000)
		spaces = 2;
	else if(value < 100000)
		spaces = 1;
	
	spaces += aditional;

	for(i = 0; i < spaces; i++)
		printf(" ");

	printf("%d ", value);
}

int main(int argc, char **argv) {
	printf(" total    blank lines w/   nb, nc    semi- preproc. file\n");
	printf(" lines    lines comments    lines   colons  direct.\n");
	printf("------+--------+--------+--------+--------+--------+----\n");
	while(1) {
		++argv, --argc;
		if ( argc > 0 )
			yyin = fopen( argv[0], "r" );
		else
			break;
		yylex();
		code_lines = total_lines - (blank_lines + lines_with_comments);
		retorna_formatado(total_lines, 0);
		retorna_formatado(blank_lines, 2);
		retorna_formatado(lines_with_comments, 2);
		retorna_formatado(code_lines, 2);
		retorna_formatado(semi_colons, 2);
		retorna_formatado(direct, 2);
		printf("%s\n", argv[0]);
		total_total_lines += total_lines;
		total_blank_lines += blank_lines;
		total_lines_with_comments += lines_with_comments;
		total_code_lines += code_lines;
		total_semi_colons += semi_colons;
		total_direct += direct;
		total_lines = 1;
		blank_lines = 0;
		lines_with_comments = 0;
		code_lines = 0;
		semi_colons = 0;
		direct = 0;
	}
	retorna_formatado(total_total_lines, 0);
	retorna_formatado(total_blank_lines, 2);
	retorna_formatado(total_lines_with_comments, 2);
	retorna_formatado(total_code_lines, 2);
	retorna_formatado(total_semi_colons, 2);
	retorna_formatado(total_direct, 2);
	printf("total\n");
	return 0;
}
