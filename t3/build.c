#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.c"

int get_graph_number() {
    int graph_number;
    scanf("Grafo %d:\n", &graph_number);

    return graph_number;
}

int get_number_of_colors() {
    int color_length;
    scanf("K=%d\n", &color_length);

    return color_length;
}

char get_and_insert_vertice(Grafo* grafo) {
    char token;
    int number;

    scanf("%d --> ", &number);

    Vertice* v = criaVertice(grafo, number);

    do {
        scanf("%d", &number);
        insereAresta(grafo, v->reg_number, number);

        token = getchar();
    } while( token != '\n' && token != EOF );

    return token;
}

void get_and_insert_vertices(Grafo* grafo) {
    char token;

    do {
        token = get_and_insert_vertice(grafo);
    } while( token != EOF );
}

Grafo* build() {
    int graph_number = get_graph_number();
    int number_of_colors = get_number_of_colors();
    Grafo* g = criaGrafo(graph_number, number_of_colors);
    get_and_insert_vertices(g);
    
    return g;
}