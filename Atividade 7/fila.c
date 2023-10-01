#include "fila.h"
#include <stdlib.h>

void inicializarFila(Fila *f) {
    f->elementos = (int *)malloc(sizeof(int) * 100);
    f->tamanho = 100;
    f->frente = 0;
    f->tras = -1;
}

int filaVazia(Fila *f) {
    return f->tras < f->frente;
}

int filaCheia(Fila *f) {
    return f->tras - f->frente == f->tamanho - 1;
}

void enqueue(Fila *f, int valor) {
    if (!filaCheia(f)) {
        f->elementos[++(f->tras)] = valor;
    }
}

int dequeue(Fila *f) {
    if (!filaVazia(f)) {
        return f->elementos[(f->frente)++];
    }
    return -1; // Fila vazia
}
