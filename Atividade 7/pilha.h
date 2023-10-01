#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *elementos;
    int tamanho;
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);

#endif