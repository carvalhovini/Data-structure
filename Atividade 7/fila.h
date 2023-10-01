#ifndef FILA_H
#define FILA_H

typedef struct {
    int *elementos;
    int tamanho;
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void enqueue(Fila *f, int valor);
int dequeue(Fila *f);

#endif