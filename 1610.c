#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BRANCO 0
#define CINZA 1  
#define PRETO 2  

typedef struct No {
    int vertice;
    struct No *prox;
} No;

void adicionar_aresta(No *adj[], int u, int v) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) exit(1); 
    
    novo_no->vertice = v;
    novo_no->prox = adj[u];
    adj[u] = novo_no;
}

void liberar_grafo(No *adj[], int N) {
    for (int i = 1; i <= N; i++) {
        No *atual = adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
}


bool detectar_ciclo_dfs(int u, int cores[], No *adj[]) {
    cores[u] = CINZA;

    No *atual = adj[u];
    while (atual != NULL) {
        int v = atual->vertice;
        
        if (cores[v] == CINZA) {
            return true; 
        }
        
        if (cores[v] == BRANCO) {
            if (detectar_ciclo_dfs(v, cores, adj)) {
                return true; 
            }
        }
        
        atual = atual->prox;
    }

    cores[u] = PRETO;

    return false;
}

bool tem_ciclo(int N, No *adj[]) {
    int *cores = (int *)calloc(N + 1, sizeof(int));
    if (cores == NULL) exit(1);
    
    for (int i = 1; i <= N; i++) {
        if (cores[i] == BRANCO) {
            if (detectar_ciclo_dfs(i, cores, adj)) {
                free(cores);
                return true;
            }
        }
    }
    
    free(cores);
    return false;
}


int main() {
    int T;
    
    if (scanf("%d", &T) != 1) return 1;

    while (T--) {
        int N, M; 
        
        if (scanf("%d %d", &N, &M) != 2) break;
        No **adj = (No **)calloc(N + 1, sizeof(No *));
        if (adj == NULL) return 1;
        for (int i = 0; i < M; i++) {
            int A, B; 
            if (scanf("%d %d", &A, &B) == 2) {
                adicionar_aresta(adj, A, B);
            }
        }

        if (tem_ciclo(N, adj)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        liberar_grafo(adj, N);
        free(adj);
    }

    return 0;
}