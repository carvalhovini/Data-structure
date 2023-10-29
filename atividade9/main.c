#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main(int argc, char *argv[])
{
    clock_t inicio, final;
    double cpu_time;

    No *cabeca = NULL;
    FILE *arquivo = fopen("1kk_rand_float.csv", "r");

    if (arquivo == NULL)
    {
        return 1;
    }

    float numero;

    inicio = clock();
    while (fscanf(arquivo, "%f", &numero) != EOF)
    {
        No *noTeste = (No *)malloc(sizeof(No));

        if (noTeste == NULL)
        {
            fclose(arquivo);
            return 1;
        }

        lista_inserir_no(cabeca, noTeste);
    }

    final = clock();
    cpu_time = ((double)(final - inicio)) / CLOCKS_PER_SEC;
    printf("tempo para inserir no de forma desordenada: %f segundos\n", cpu_time);

    fclose(arquivo);

    No *cabeca2 = NULL;

    arquivo = fopen("1kk_rand_float.csv", "r");

    inicio = clock();
    while (fscanf(arquivo, "%f", &numero) != EOF)
    {
        No *noTeste = (No *)malloc(sizeof(No));

        if (noTeste == NULL)
        {
            fclose(arquivo);
            return 1;
        }

        noTeste->valor = numero;
        lista_inserir_no_ordenado(cabeca2, noTeste);
    }

    final = clock();
    cpu_time = ((double)(final - inicio)) / CLOCKS_PER_SEC;
    printf("tempo para inserir no de forma ordenada: %f segundos\n", cpu_time);

    fclose(arquivo);

    lista_liberar(cabeca);
    lista_liberar(cabeca2);
    return 0;
}