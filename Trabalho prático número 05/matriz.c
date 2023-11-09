// matriz.c

#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

float obtemValor(Matriz matriz, int linha, int coluna) {
    Celula *atual = matriz.cabeca->direita;

    while (atual != matriz.cabeca) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->valor;
        }

        atual = atual->direita;
    }

    return 0.0; // Se não encontrar a célula, retorna 0.0
}

void inicializaMatriz(Matriz *matriz, int nlin, int ncol) {
    matriz->nlin = nlin;
    matriz->ncol = ncol;

    matriz->cabeca = (Celula *)malloc(sizeof(Celula));
    matriz->cabeca->direita = matriz->cabeca;
    matriz->cabeca->abaixo = matriz->cabeca;
    matriz->cabeca->linha = -1;
    matriz->cabeca->coluna = -1;
    matriz->cabeca->valor = 0.0;
}

void insere(Matriz *matriz, int linha, int coluna, float valor) {
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;

    Celula *atual = matriz->cabeca;

    while (atual->direita != matriz->cabeca && atual->direita->coluna < coluna) {
        atual = atual->direita;
    }

    while (atual->abaixo != matriz->cabeca && atual->abaixo->linha < linha) {
        atual = atual->abaixo;
    }

    novaCelula->direita = atual->direita;
    atual->direita = novaCelula;

    novaCelula->abaixo = atual->abaixo;
    atual->abaixo = novaCelula;
}

void imprimeMatriz(Matriz matriz) {
    Celula *linhaAtual = matriz.cabeca->abaixo;

    while (linhaAtual != matriz.cabeca) {
        Celula *celulaAtual = linhaAtual->direita;

        while (celulaAtual != linhaAtual) {
            printf("(%d, %d, %.2f) ", celulaAtual->linha, celulaAtual->coluna, celulaAtual->valor);
            celulaAtual = celulaAtual->direita;
        }

        printf("\n");
        linhaAtual = linhaAtual->abaixo;
    }

    printf("\n");
}

Matriz leMatriz(FILE *arquivo) {
    Matriz matriz;
    int nlin, ncol, linha, coluna;
    float valor;

    fscanf(arquivo, "%d, %d", &nlin, &ncol);
    inicializaMatriz(&matriz, nlin, ncol);

    while (fscanf(arquivo, "%d, %d, %f", &linha, &coluna, &valor) == 3) {
        insere(&matriz, linha, coluna, valor);
    }

    return matriz;
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    int i, j;

    inicializaMatriz(&C, A.nlin, A.ncol);

    for (i = 1; i <= A.nlin; i++) {
        for (j = 1; j <= A.ncol; j++) {
            float soma = obtemValor(A, i, j) + obtemValor(B, i, j);
            if (soma != 0.0) {
                insere(&C, i, j, soma);
            }
        }
    }

    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    int i, j, k;

    inicializaMatriz(&C, A.nlin, B.ncol);

    for (i = 1; i <= A.nlin; i++) {
        for (j = 1; j <= B.ncol; j++) {
            float produto = 0.0;

            for (k = 1; k <= A.ncol; k++) {
                produto += obtemValor(A, i, k) * obtemValor(B, k, j);
            }

            if (produto != 0.0) {
                insere(&C, i, j, produto);
            }
        }
    }

    return C;
}
