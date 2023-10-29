#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int opcao;
    No *lista = NULL;

    inserir_no_inicio(&lista, 8);
    inserir_no_fim(&lista, 5);
    inserir_no_meio(&lista, 2, );
    imprimir(lista);

    return 0;
}
