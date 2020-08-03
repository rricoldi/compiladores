FLEX=flex
BISON=bison
CC=gcc
CFLAGS=
LIBS=

PROGRAMA = l7e3
LEXICO = lexico.l

$(PROGRAMA): $(LEXICO)
	$(FLEX) $(LEXICO)
	$(CC) lex.yy.c $(LIBS) -o $(PROGRAMA)

clean:
	rm -f lex.yy.c
	rm -f $(PROGRAMA)