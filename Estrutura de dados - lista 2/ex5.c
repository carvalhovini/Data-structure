#include <stdio.h>

void multiplica_array(int arr1[], int arr2[], int tamanho, int resultado[]) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int tamanho;
    printf("escreva o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int array1[tamanho];
    int array2[tamanho];

    printf("escreva os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("escreva os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("elemento %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    int resultado[tamanho];
    multiplica_array(array1, array2, tamanho, resultado);

    printf("Res: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
