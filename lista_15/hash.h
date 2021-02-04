#include <stdio.h>
#include <stdlib.h>

#define tam 211

struct dados {
   int type;
   char* identifier;   
   struct dados *prox;
} hashItem;

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int num);
void inicializaHash(Hash tab);
void insereHash(Hash tab, int type, char* identifier);
Dados* buscaHash(Hash tab, char* identifier);