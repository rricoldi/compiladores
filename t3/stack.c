#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* bottom;
    Vertice *vertice;
} Node;

typedef struct stack {
    Node* top;
    int spill;
} Stack;

Stack* create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    s->top = NULL;
    s->spill = 0;

    return s;
}

void stack_up(Stack* s, Vertice* v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertice = v;

    if(s->top != NULL) {
        node->bottom = s->top;
    } 

    s->top = node;
}

Vertice* stack_down(Stack* s) {
    Vertice* aux = s->top->vertice;
    Node* aux_node = s->top->bottom;
    free(s->top);

    s->top = aux_node;

    return aux;
}