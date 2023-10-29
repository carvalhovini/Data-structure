#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro ao alocar memória!\n");
    }
}

void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){
            *lista = novo;
        } else{
            aux = *lista;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            
        }
    } else {
        printf("Erro ao alocar memória!\n");
    }
}

void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memória!\n");
    }
}

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else if(novo->valor < ((*lista)->valor)){
            novo->proximo = *lista;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else{
        printf("Erro ao alocar memória!\n");
    }
}


void imprimir(No *no){
    printf("\n\tLista:");
    while(no){
        printf("%d", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

