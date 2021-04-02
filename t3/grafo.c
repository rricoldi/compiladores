#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia {
    int reg_number;
    struct adjacencia *proximo;
} Adjacencia;

typedef struct vertice {
    Adjacencia *inicio;
    int reg_number;
    int color;
    struct vertice *next;
} Vertice;

typedef struct grafo {
    int numeroDeVertices;
    int numeroDeArestas;
    int graph_number;
    int number_of_colors;
    Vertice *arranjo;
} Grafo;

Grafo *criaGrafo(int graph_number, int number_of_colors) {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->numeroDeVertices = 0;
    g->numeroDeArestas = 0;
    g->graph_number = graph_number;
    g->number_of_colors = number_of_colors;
    g->arranjo = NULL;
    // g->arranjo = (Vertice *) malloc(numeroDeVertices*sizeof(Vertice));
    
    // for(int i = 0; i<numeroDeVertices; i++)
    //     g->arranjo[i].inicio = NULL;
    return g;
}

Vertice *criaVertice(Grafo* grafo, int reg_number) {
    Vertice *v = (Vertice*) malloc(sizeof(Vertice));

    grafo->numeroDeVertices++;

    v->reg_number = reg_number;
    v->inicio = NULL;

    if(grafo->arranjo == NULL) {
        grafo->arranjo = v;
        v->next = NULL;
    } else {
        v->next = grafo->arranjo;
        grafo->arranjo = v;
    }

    return v;
}

Adjacencia *criaAdjacencia(int noFinal) {
    Adjacencia *lista = (Adjacencia *) malloc(sizeof(Adjacencia));
    
    lista->reg_number = noFinal;
    lista->proximo = NULL;
    
    return lista;
}

void removeAresta(Grafo* grafo, Vertice* noInicial, Vertice* noFinal) {
    Adjacencia *adjacencia = noInicial->inicio;
    Adjacencia *aux;

    while(adjacencia) {
        if(adjacencia->reg_number == noFinal->reg_number){
            grafo->numeroDeArestas--;
            if(noInicial->inicio == adjacencia){
                noInicial->inicio = adjacencia->proximo;
            } else {
                aux->proximo = adjacencia->proximo;
            }              
            free(adjacencia);
            return;
        }
        aux = adjacencia;
        adjacencia = adjacencia->proximo;
        
    }
}

void insereAresta(Grafo* grafo, int noInicial, int noFinal) {
    Adjacencia *novo = criaAdjacencia(noFinal);

    Vertice* v = grafo->arranjo;

    while (v->reg_number != noInicial) 
        v = v->next;
    
    novo->proximo = v->inicio;
    v->inicio = novo;

    grafo->numeroDeArestas ++;
}

void imprime(Grafo* grafo) {
    if (grafo == NULL) {
        printf("Grafo vazio!\n");
        return;
    }

    printf("Vertices: %d. Arestas: %d.\n", grafo->numeroDeVertices, grafo->numeroDeArestas);

    Vertice* v = grafo->arranjo;
    Adjacencia* a = v->inicio;

    while (v) {
        printf("v%d: ", v->reg_number);

        while(a) {
            printf("v%d ", a->reg_number);

            a = a->proximo;
        }
        
        printf("\n");
        v = v->next;
        if(v != NULL)
            a = v->inicio;
    }
}

int get_vertice_degree(Vertice* v) {
    int degree = 0;
    Adjacencia* a = v->inicio;

    while(a != NULL) {
        degree++;
        a = a->proximo;
    }

    return degree;
}

Vertice* get_lesser_degree_vertice(Grafo *g) {
    Vertice *v = g->arranjo;

    Vertice *lesser = v;
    int lesser_degree = get_vertice_degree(v);
    int aux;

    while (1) {
        v = v->next;
        if(v == NULL)
            break;
        aux = get_vertice_degree(v);
        if(aux <= lesser_degree) {
            lesser = v;
            lesser_degree = aux;
        }
    }

    return lesser;
}

Vertice* get_higher_degree_vertice(Grafo *g) {
    Vertice *v = g->arranjo;

    Vertice *higher = v;
    int higher_degree = get_vertice_degree(v);
    int aux;

    while (1) {
        v = v->next;
        if(v == NULL)
            break;
        aux = get_vertice_degree(v);
        if(aux >= higher_degree) {
            higher = v;
            higher_degree = aux;
        }
    }

    return higher;
}

void remove_vertice(Grafo *g, Vertice* v) {
    Vertice* aux = g->arranjo, *aux2 = NULL;

    while (aux != NULL) {
        if(aux->reg_number == v->reg_number) {
            if(aux2 != NULL) {
                aux2->next = aux->next;
            }
        } else {
            removeAresta(g, aux, v);
        }
        aux2 = aux;
        aux = aux->next;
    }

    g->numeroDeVertices --;
    g->numeroDeArestas -= get_vertice_degree(v);
}