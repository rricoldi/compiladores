#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

int getKey(char* string) {
    int i, result = 0;
    for(i = 0; i < strlen(string); i++) {
        result += string[i];
    }

    return result;
}

int funcaoHash(int num) {
  return(num%tam);
}

void inicializaHash(Hash tab) {
    int i;
    for(i = 0; i < tam; i++) {
        tab[i] = NULL;
    }
}

int compare(char* string1, char* string2) {
    if(strlen(string1) != strlen(string2))
        return 0;
    
    int i;
    for(i = 0; i < strlen(string1); i++) {
        if(string1[i] != string2[i])
            return 0;
    }
    return 1;
}

void insereHash(Hash tab, int type, char* identifier) {
    int i = 0;
    int chave = funcaoHash(getKey(identifier));
    Dados* aux = tab[chave];
    while(aux != NULL) {
        if(compare(aux->identifier, identifier)) {
            break;
        }
        aux = aux->prox;
    }
    if(aux == NULL) {
        aux = (Dados*)malloc(sizeof(Dados));
        aux->identifier = (char*) malloc(sizeof(char)*(strlen(identifier)+1));
        strcpy(aux->identifier, identifier);
        aux->type = type;
        aux->prox = tab[chave];
        tab[chave] = aux;
    }
}

Dados* buscaHash(Hash tab, char* identifier) {
    int num = funcaoHash(getKey(identifier));
    int pos = num;
    if(pos > tam)
        return NULL;
    Dados* aux = tab[pos];
    if(aux == NULL) {
        return NULL;
    } else {
        while(aux != NULL) {
            if(compare(aux->identifier, identifier))
                return aux;
            aux = aux->prox;
        }
    }
    return NULL;
 }
