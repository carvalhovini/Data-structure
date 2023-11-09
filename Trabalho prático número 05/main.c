// main.c

#include "matriz.h"

int main(void) {
    Matriz A, B, C;

    inicializaMatriz(&A, 4, 4);
    inicializaMatriz(&B, 4, 4);

    insere(&A, 1, 1, 50.0);
    insere(&A, 2, 1, 10.0);
    insere(&A, 2, 3, 20.0);
    insere(&A, 4, 1, -30.0);
    insere(&A, 4, 3, -60.0);
    insere(&A, 4, 4, -5.0);

    insere(&B, 1, 1, 10.0);
    insere(&B, 1, 2, 5.0);
    insere(&B, 2, 3, 15.0);
    insere(&B, 3, 4, 8.0);
    insere(&B, 4, 1, 3.0);
    insere(&B, 4, 4, 2.0);

    imprimeMatriz(A);
    imprimeMatriz(B);

    C = somaMatrizes(A, B);
    imprimeMatriz(C);

    // Teste outras operações e cenários

    return 0;
}
