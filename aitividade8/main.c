#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista.c"

/// @brief 
/// @return 
int main() {

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL))));
    No* n3 = no('U', NULL);

    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);

    lista_imprimir(n0);
    printf("\nqtd nos: %d\n", lista_quantidade_nos(n0));

    No* n_copia = lista_copiar(n0);
    printf("\nCópia: ");
    lista_imprimir(n_copia);

    lista_concatenar(n0, n_copia);
    printf("\nConcatenada: ");
    lista_imprimir(n0);

    printf("\n");

    int existencia = lista_verificar_existencia(n0, 'X');
    printf("Existe 'X' na lista: %s\n", existencia ? "Sim" : "Não");

    int ocorrencias = lista_verificar_ocorrencias(n0, 'C');
    printf("Ocorrências de 'C': %d\n", ocorrencias);

    printf("Lista inversa: ");
    lista_imprimir_inversa(n0);

    lista_inserir_no_i(n0, 3); // Inserir 'N' na posição 3 (0-based)
    printf("\nLista com 'N' inserido: ");
    lista_imprimir(n0);

    lista_remover_no_i(n0, 3); // Remover nó na posição 3 (0-based)
    printf("\nLista com 'N' removido: ");
    lista_imprimir(n0);

    lista_remover_no(n0, 'D'); // Remover todos os nós com valor 'D'
    printf("\nLista com 'D' removido: ");
    lista_imprimir(n0);

    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    return 0;
    
    }