#include <stdio.h>

void menor_maior_array(int arr[], int tamanho, int *menor, int *maior) {
    if (tamanho == 0) {
        *menor = *maior = 0;
        return;
    }

    *menor = *maior = arr[0]; 

    for (int i = 1; i < tamanho; i++) {
        if (arr[i] < *menor) {
            *menor = arr[i];
        } else if (arr[i] > *maior) {
            *maior = arr[i];
        }
    }
}

int main() {
    int tamanho;
    printf("digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];
    printf("digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int menor, maior;
    menor_maior_array(array, tamanho, &menor, &maior);

    printf("menor: %d\n", menor);
    printf("maior: %d\n", maior);

    return 0;
}
