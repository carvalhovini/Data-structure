#include <stdio.h>

int conta_int_array(int arr[], int tamanho, int busca) {
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int tamanho;
    printf("escreva o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];
    printf("escreva os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int elementoBusca;
    printf("escreva o numero de busca: ");
    scanf("%d", &elementoBusca);

    int quantidade = conta_int_array(array, tamanho, elementoBusca);
    printf("Qnt de ocorrencias de %d: %d\n", elementoBusca, quantidade);

    return 0;
}
