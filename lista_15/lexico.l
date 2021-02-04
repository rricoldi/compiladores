%option noyywrap
%{
    #include <sintatico.tab.h>
    #include <string.h>
	char identifier[200] = "";
	int line = 1;
%}

%x IDENTIFIER

%%

<INITIAL>{
"int"					return INT;
"char"					return CHAR;
"float"                 return FLOAT;
"$"                     return EOL;
[a-z]+                  return ID;
","                     return COMMA;
\n                      line++;
<<EOF>>                 return ENDOF;
.
}
%%
