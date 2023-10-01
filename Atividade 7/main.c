#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {

    Pilha pilha;
    inicializarPilha(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);

    printf("Elementos na pilha: ");
    while (!pilhaVazia(&pilha)) {
        printf("%d ", pop(&pilha));
    }
    printf("\n");

    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    printf("Elementos na fila: ");
    while (!filaVazia(&fila)) {
        printf("%d ", dequeue(&fila));
    }
    printf("\n");

    return 0;
}
