FLEX=flex
CC=gcc
CFLAGS=
LIBS=

PROGRAMA = lexico
LEXICO = lexico.l

$(PROGRAMA): $(LEXICO)
	$(FLEX) $(LEXICO)
	$(CC) lex.yy.c $(LIBS) -o $(PROGRAMA)

clean:
	rm -f lex.yy.c
	rm -f lexico.exe lexico