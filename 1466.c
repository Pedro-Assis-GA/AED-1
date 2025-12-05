#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

typedef struct {
    Node* nos[MAX];
    int frente;
    int tras;
} Fila;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

Fila* criar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = 0;
    fila->tras = 0;
    return fila;
}

void enfileirar(Fila* fila, Node* no) {
    fila->nos[fila->tras] = no;
    fila->tras = (fila->tras + 1) % MAX;
}

Node* desenfileirar(Fila* fila) {
    Node* no = fila->nos[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    return no;
}

int fila_vazia(Fila* fila) {
    return fila->frente == fila->tras;
}

void percorrer_por_nivel(Node* raiz, int caso) {
    if (raiz == NULL) return;
    
    printf("Case %d:\n", caso);
    
    Fila* fila = criar_fila();
    enfileirar(fila, raiz);
    
    int primeiro = 1; 
    
    while (!fila_vazia(fila)) {
        Node* atual = desenfileirar(fila);
        
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;
        
        if (atual->esquerda != NULL) {
            enfileirar(fila, atual->esquerda);
        }
        if (atual->direita != NULL) {
            enfileirar(fila, atual->direita);
        }
    }
    
    printf("\n\n");
    free(fila);
}

void liberar_arvore(Node* raiz) {
    if (raiz == NULL) return;
    
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    
    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);
        
        Node* raiz = NULL;
        
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        
        percorrer_por_nivel(raiz, caso);
        
        liberar_arvore(raiz);
    }
    
    return 0;
}