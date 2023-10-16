#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int lista_verificar_existencia(No* L, char valor_busca){
    if (L == NULL)
        return 0;

    if (L->valor == valor_busca)
        return 1;

    return lista_verificar_existencia(L->proximo_no, valor_busca);
}

int lista_verificar_ocorrencias(No* L, char valor_busca){
    if (L == NULL)
        return 0;

    if (L->valor == valor_busca)
        return 1 + lista_verificar_ocorrencias(L->proximo_no, valor_busca);
    else
        return lista_verificar_ocorrencias(L->proximo_no, valor_busca);
}

void lista_imprimir_inversa(No* L){
    if (L == NULL)
        return;

    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i){
    if (i < 0)
        return;

    if (i == 0) {
        // Inserir no início da lista
        No* novo_no = no(L->valor, L->proximo_no);
        L->valor = 'N'; // Valor fictício para o novo nó
        L->proximo_no = novo_no;
        return;
    }

    if (L->proximo_no != NULL) {
        lista_inserir_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no_i(No* L, int i){
    if (i < 0 || L == NULL || L->proximo_no == NULL)
        return;

    if (i == 0) {
        No* temp = L->proximo_no;
        L->valor = temp->valor;
        L->proximo_no = temp->proximo_no;
        free(temp);
        return;
    }

    lista_remover_no_i(L->proximo_no, i - 1);
}

void lista_remover_no(No* L, char valor_busca){
    if (L == NULL)
        return;

    if (L->proximo_no != NULL && L->proximo_no->valor == valor_busca) {
        No* temp = L->proximo_no;
        L->proximo_no = temp->proximo_no;
        free(temp);
        lista_remover_no(L, valor_busca); // Para remover todas as ocorrências
    } else {
        lista_remover_no(L->proximo_no, valor_busca);
    }
}