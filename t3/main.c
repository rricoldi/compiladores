#include <stdio.h>
#include "build.c"
#include "simplify.c"

int main() {
    Grafo* grafo = build();
    printf("Graph %d -> Physical Registers: %d\n", grafo->graph_number, grafo->number_of_colors);
    printf("----------------------------------------\n");
    // imprime(grafo);

    grafo->number_of_colors --;

    int* spillStacks = malloc((grafo->number_of_colors)*sizeof(int));
    int i = 0, j;
    while (grafo->number_of_colors > 1) {
        Stack* stack = simplify(grafo);
        spillStacks[i] = stack->spill;
        i++;
        grafo->number_of_colors--;
    }

    printf("----------------------------------------\n");
    printf("----------------------------------------\n");

    for(j=0; j < i; j++) {
        printf("Graph %d -> K = %d: ", grafo->graph_number, i - j + 2);
        if(spillStacks[j] == 1){
            printf("SPILL\n");
        } else {
            printf("Successful Allocation\n");
        }
    }

    return 0;
}