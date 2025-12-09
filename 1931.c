#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 10001
#define INF 9223372036854775807LL 

typedef struct Aresta {
    int vizinho;
    int custo;
    struct Aresta *proximo;
} Aresta;

typedef struct NoHeap {
    long long custo;
    int cidade;
    int paridade; 
} NoHeap;

Aresta *adj[MAX_CIDADES];

void adicionar_aresta(int u, int v, int custo) {
    Aresta *nova_aresta = (Aresta *)malloc(sizeof(Aresta));
    if (nova_aresta == NULL) exit(1);
    
    nova_aresta->vizinho = v;
    nova_aresta->custo = custo;
    
    nova_aresta->proximo = adj[u];
    adj[u] = nova_aresta;
    nova_aresta = (Aresta *)malloc(sizeof(Aresta));
    if (nova_aresta == NULL) exit(1);
    
    nova_aresta->vizinho = u;
    nova_aresta->custo = custo;
    nova_aresta->proximo = adj[v];
    adj[v] = nova_aresta;
}

void limpar_adj(int N) {
    for (int i = 1; i <= N; i++) {
        Aresta *atual = adj[i];
        while (atual != NULL) {
            Aresta *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        adj[i] = NULL;
    }
}

NoHeap heap[MAX_CIDADES * 2 * 4]; 
int heap_tamanho = 0;

void trocar_nos(int i, int j) {
    NoHeap temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heap_push(long long custo, int cidade, int paridade) {
    heap_tamanho++;
    int i = heap_tamanho;
    heap[i].custo = custo;
    heap[i].cidade = cidade;
    heap[i].paridade = paridade;
    
    while (i > 1 && heap[i].custo < heap[i / 2].custo) {
        trocar_nos(i, i / 2);
        i /= 2;
    }
}

NoHeap heap_pop() {
    if (heap_tamanho == 0) {
        NoHeap vazio = {INF, -1, -1};
        return vazio;
    }
    
    NoHeap no_min = heap[1];
    heap[1] = heap[heap_tamanho];
    heap_tamanho--;
    
    int i = 1;

    while (1) {
        int esq = 2 * i;
        int dir = 2 * i + 1;
        int menor = i;
        
        if (esq <= heap_tamanho && heap[esq].custo < heap[menor].custo) {
            menor = esq;
        }
        if (dir <= heap_tamanho && heap[dir].custo < heap[menor].custo) {
            menor = dir;
        }
        
        if (menor != i) {
            trocar_nos(i, menor);
            i = menor;
        } else {
            break;
        }
    }
    return no_min;
}

long long dist[MAX_CIDADES][2];

long long resolver_1931(int C, int V) {
    for (int i = 1; i <= C; i++) {
        dist[i][0] = INF; 
        dist[i][1] = INF; 
    }

    dist[1][0] = 0;
    heap_tamanho = 0;
    heap_push(0, 1, 0);

    while (heap_tamanho > 0) {
        NoHeap atual = heap_pop();
        long long u_custo = atual.custo;
        int u_cidade = atual.cidade;
        int u_paridade = atual.paridade;
        if (u_custo > dist[u_cidade][u_paridade]) {
            continue;
        }

        Aresta *aresta = adj[u_cidade];
        while (aresta != NULL) {
            int v_cidade = aresta->vizinho;
            int custo_aresta = aresta->custo;
            int v_paridade = 1 - u_paridade; 
            long long novo_custo = u_custo + custo_aresta;

            if (novo_custo < dist[v_cidade][v_paridade]) {
                dist[v_cidade][v_paridade] = novo_custo;
                heap_push(novo_custo, v_cidade, v_paridade);
            }
            
            aresta = aresta->proximo;
        }
    }
    long long resultado = dist[C][0];

    return (resultado == INF) ? -1 : resultado;
}

int main() {
    int C, V; 
    while (scanf("%d %d", &C, &V) == 2) {
        for (int i = 0; i < V; i++) {
            int C1, C2, G; 
            if (scanf("%d %d %d", &C1, &C2, &G) == 3) {
                adicionar_aresta(C1, C2, G);
            }
        }

        printf("%lld\n", resolver_1931(C, V));
        limpar_adj(C);
    }

    return 0;
}