#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Protótipos das funções
struct TreeNode* createNode(int key);
struct TreeNode* insert(struct TreeNode* root, int key);
int search(struct TreeNode* root, int key);
struct TreeNode* findMin(struct TreeNode* root);
struct TreeNode* findMax(struct TreeNode* root);
void preOrderPrint(struct TreeNode* root, void (*visit)(int));
void inOrderPrint(struct TreeNode* root, void (*visit)(int));
void postOrderPrint(struct TreeNode* root, void (*visit)(int));
void freeTree(struct TreeNode* root);
struct TreeNode* removeNode(struct TreeNode* root, int key);
void printValue(int value);
void printMenu();

// Função para criar um novo nó
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na ABB
struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Função para buscar um valor na ABB
int search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key) {
        return (root != NULL);
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Função para encontrar o nó com o valor mínimo na ABB
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para encontrar o nó com o valor máximo na ABB
struct TreeNode* findMax(struct TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Função para realizar o percurso em pré-ordem
void preOrderPrint(struct TreeNode* root, void (*visit)(int)) {
    if (root != NULL) {
        visit(root->key);
        preOrderPrint(root->left, visit);
        preOrderPrint(root->right, visit);
    }
}

// Função para realizar o percurso em ordem simétrica (inorder)
void inOrderPrint(struct TreeNode* root, void (*visit)(int)) {
    if (root != NULL) {
        inOrderPrint(root->left, visit);
        visit(root->key);
        inOrderPrint(root->right, visit);
    }
}

// Função para realizar o percurso em pós-ordem
void postOrderPrint(struct TreeNode* root, void (*visit)(int)) {
    if (root != NULL) {
        postOrderPrint(root->left, visit);
        postOrderPrint(root->right, visit);
        visit(root->key);
    }
}

// Função para liberar a memória alocada para os nós da árvore
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função para remover um nó com determinado valor da ABB
struct TreeNode* removeNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}

// Função para imprimir valores durante os percursos
void printValue(int value) {
    printf("%d ", value);
}

// Função para imprimir menu interativo
void printMenu() {
    printf("\n--- Menu Interativo ---\n");
    printf("1. Inserir valor na arvore\n");
    printf("2. Buscar valor na arvore\n");
    printf("3. Remover valor da arvore\n");
    printf("4. Imprimir em Pre-ordem\n");
    printf("5. Imprimir em Ordem\n");
    printf("6. Imprimir em Pos-ordem\n");
    printf("7. Encontrar valor Minimo\n");
    printf("8. Encontrar valor Maximo\n");
    printf("9. Sair\n");
    printf("Digite a opcao desejada: ");
}

// Função principal (main) para testar as operações
int main() {
    struct TreeNode* root = NULL;
    int option, value;

    do {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d encontrado na arvore.\n", value);
                } else {
                    printf("%d nao encontrado na arvore.\n", value);
                }
                break;

            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                root = removeNode(root, value);
                printf("Removido %d da arvore.\n", value);
                break;

            case 4:
                printf("Preorder: ");
                preOrderPrint(root, printValue);
                printf("\n");
                break;

            case 5:
                printf("Inorder: ");
                inOrderPrint(root, printValue);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postOrderPrint(root, printValue);
                printf("\n");
                break;

            case 7:
                printf("Valor Minimo: %d\n", findMin(root)->key);
                break;

            case 8:
                printf("Valor Maximo: %d\n", findMax(root)->key);
                break;

            case 9:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 9);

    // Liberação de memória
    freeTree(root);

    return 0;
}
