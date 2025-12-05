#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

typedef struct Node {
    char joia[100];  // String para armazenar a jóia
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Cria um novo nó
Node* criar_no(const char* joia) {
    Node* novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->joia, joia);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Insere uma jóia na árvore (se ainda não existir)
// Retorna 1 se inseriu (era nova), 0 se já existia
int inserir_joia(Node** raiz, const char* joia) {
    if (*raiz == NULL) {
        *raiz = criar_no(joia);
        return 1;  // Inseriu nova jóia
    }
    
    int cmp = strcmp(joia, (*raiz)->joia);
    
    if (cmp < 0) {
        return inserir_joia(&(*raiz)->esquerda, joia);
    } else if (cmp > 0) {
        return inserir_joia(&(*raiz)->direita, joia);
    }
    
    return 0;  // Jóia já existia
}

// Libera a memória da árvore
void liberar_arvore(Node* raiz) {
    if (raiz == NULL) return;
    
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main() {
    Node* raiz = NULL;
    char joia[100];
    int contador = 0;
    
    // Lê até o fim do arquivo (EOF)
    while (scanf("%s", joia) != EOF) {
        if (inserir_joia(&raiz, joia)) {
            contador++;
        }
    }
    
    printf("%d\n", contador);
    
    liberar_arvore(raiz);
    
    return 0;
}