#include "pilha.h"
#include <stdlib.h>

void inicializarPilha(Pilha *p) {
    p->elementos = (int *)malloc(sizeof(int) * 100);
    p->tamanho = 100;
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == p->tamanho - 1;
}

void push(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->elementos[++(p->topo)] = valor;
    }
}

int pop(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->elementos[(p->topo)--];
    }
    return -1; // Pilha vazia
}
