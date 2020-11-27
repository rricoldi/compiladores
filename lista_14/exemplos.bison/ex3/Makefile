FLEX=flex
BISON=bison
CC=gcc

PROGRAMA = calculadora
LEXICO = lexico.l
SINTATICO = sintatico.y

$(PROGRAMA): $(LEXICO) $(SINTATICO) ast.h ast.c
	$(BISON) -d $(SINTATICO)
	$(FLEX) $(LEXICO)
	$(CC) -c *.c -I.
	$(CC) *.o -o $(PROGRAMA)

clean:
	rm -f *.yy.c
	rm -f *.tab.c
	rm -f *.tab.h
	rm -f *.o
	rm -f *.exe
	rm -f $(PROGRAMA)