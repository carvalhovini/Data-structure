#include "tabela_hash.h"
#include <stdlib.h>
#include <string.h>

static Entry tabela[TAMANHO_TABELA];

void hash_table_init() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i].chave = NULL;
        tabela[i].dado = NULL;
    }
}

int hash(char* chave) {
    // Lógica simples para gerar um índice a partir da chave
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TAMANHO_TABELA;
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    if (tabela[index].chave != NULL && strcmp(tabela[index].chave, chave) == 0) {
        return tabela[index].dado;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    tabela[index].chave = chave;
    tabela[index].dado = dado;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return (tabela[index].chave != NULL && strcmp(tabela[index].chave, chave) == 0);
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    tabela[index].chave = NULL;
    tabela[index].dado = NULL;
}
