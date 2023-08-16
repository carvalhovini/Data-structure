#include <stdio.h>
#include <string.h>

int busca_string(char *arr[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(arr[i], busca) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    char *array[tamanho];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        char elemento[50];
        printf("Elemento %d: ", i + 1);
        scanf("%s", elemento);
        array[i] = strdup(elemento);
     }

    char busca[50];
    printf("Digite a string de busca: ");
    scanf("%s", busca);
    int resultado = busca_string(array, tamanho, busca);
    printf("%d\n", resultado);

    for (int i = 0; i < tamanho; i++) {
        free(array[i]);
    }

    return 0;
}
