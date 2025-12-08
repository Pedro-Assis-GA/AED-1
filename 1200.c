#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no {
    char valor;
    struct no *esq;
    struct no *dir;
} No;

No* criar_no(char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, char valor) {
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

void infixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        infixa(raiz->dir, primeiro);
    }
}

void prefixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void posfixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

int buscar(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    
    if (valor == raiz->valor) {
        return 1;
    } else if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
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
    char linha[20];
    char comando[10];
    char valor;
    No* raiz = NULL;
    
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = 0;
        
        if (strlen(linha) == 0) continue;
        
        if (sscanf(linha, "%s", comando) == 1) {
            if (strcmp(comando, "I") == 0) {
                sscanf(linha, "%s %c", comando, &valor);
                raiz = inserir(raiz, valor);
            } 
            else if (strcmp(comando, "INFIXA") == 0) {
                int primeiro = 1;
                infixa(raiz, &primeiro);
                printf("\n");
            }
            else if (strcmp(comando, "PREFIXA") == 0) {
                int primeiro = 1;
                prefixa(raiz, &primeiro);
                printf("\n");
            }
            else if (strcmp(comando, "POSFIXA") == 0) {
                int primeiro = 1;
                posfixa(raiz, &primeiro);
                printf("\n");
            }
            else if (strcmp(comando, "P") == 0) {
                sscanf(linha, "%s %c", comando, &valor);
                if (buscar(raiz, valor)) {
                    printf("%c existe\n", valor);
                } else {
                    printf("%c nao existe\n", valor);
                }
            }
        }
    }
    
    liberar_arvore(raiz);
    
    return 0;
}