#include <stdio.h>

int soma_array(int arr[], int tamanho) {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int array_exemplo[] = {5, 7, 9, 6};
    int tamanho = sizeof(array_exemplo) / sizeof(array_exemplo[0]);
    int resultado = soma_array(array_exemplo, tamanho);
    printf("%d\n", resultado);
    return 0;
}
