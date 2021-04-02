#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"

void take_from_graph_to_stack(Grafo* g, Stack* s) {
    Vertice* v = get_lesser_degree_vertice(g);
    int v_degree = get_vertice_degree(v);
    int spill = 0;

    if(v_degree >= g->number_of_colors) {
        spill = 1;
        s->spill = 1;
        v = get_higher_degree_vertice(g);
        printf("Push: %d *\n", v->reg_number);
    } else {
        printf("Push: %d\n", v->reg_number);
    }

    remove_vertice(g, v);
    stack_up(s, v);
}

Stack* simplify(Grafo* g) {
    Stack* s = create_stack();

    printf("----------------------------------------\n");
    printf("K = %d\n\n", g->number_of_colors);

    while(g->numeroDeVertices > 0) {
        take_from_graph_to_stack(g, s);
    }

    return s;
}