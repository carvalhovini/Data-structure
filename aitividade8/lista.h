#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No* proximo_no;
} No;

No* no(char valor, No* proximo_no);
void lista_inserir_no(No* L, No* no);
void lista_imprimir(No* L);
int lista_quantidade_nos(No* L);
No* lista_copiar(No* L);
void lista_concatenar(No* L, No* Lc);
void lista_liberar(No* L);

int lista_verificar_existencia(No* L, char valor_busca);
int lista_verificar_ocorrencias(No* L, char valor_busca);
void lista_imprimir_inversa(No* L);
void lista_inserir_no_i(No* L, int i);
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No* L, char valor_busca);

#endif /* LISTA_H */