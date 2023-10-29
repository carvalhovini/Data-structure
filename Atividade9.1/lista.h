typedef struct no{
    int valor;
    struct no* proximo;
} No;

void inserir_no_inicio(No **lista, int num);
void inserir_no_fim(No **lista, int num);
void inserir_no_meio(No **lista, int num, int ant);
void imprimir(No *no);
void inserir_ordenado(No **lista, int num