#include "tabela_hash.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    hash_table_init();

    char opcao;
    char chave[50];
    char dado[50];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir na tabela\n");
        printf("2. Buscar na tabela\n");
        printf("3. Remover da tabela\n");
        printf("4. Sair\n");

        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Insira a chave: ");
                scanf("%s", chave);
                printf("Insira o dado: ");
                scanf("%s", dado);
                hash_table_put(chave, dado);
                break;

            case '2':
                printf("Insira a chave para buscar: ");
                scanf("%s", chave);
                char* resultado = hash_table_get(chave);
                if (resultado != NULL) {
                    printf("Resultado para chave %s: %s\n", chave, resultado);
                } else {
                    printf("Chave %s nao encontrada na tabela.\n", chave);
                }
                break;

            case '3':
                printf("Insira a chave para remover: ");
                scanf("%s", chave);
                hash_table_remove(chave);
                printf("Chave %s removida da tabela.\n", chave);
                break;

            case '4':
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}
