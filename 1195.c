#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    
    return raiz;
}

void prefixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void infixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        infixa(raiz->dir, primeiro);
    }
}

void posfixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
    }
}

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C, N, valor;
    int caso = 1;
    
    scanf("%d", &C);
    
    for (int i = 0; i < C; i++) {
        No* raiz = NULL;
        
        scanf("%d", &N);
        
        for (int j = 0; j < N; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        
        printf("Case %d:\n", caso++);
        
        printf("Pre.: ");
        int primeiro = 1;
        prefixa(raiz, &primeiro);
        printf("\n");
        
        printf("In..: ");
        primeiro = 1;
        infixa(raiz, &primeiro);
        printf("\n");
        
        printf("Post: ");
        primeiro = 1;
        posfixa(raiz, &primeiro);
        printf("\n");
        
        printf("\n");
        
        liberar_arvore(raiz);
    }
    
    return 0;
}