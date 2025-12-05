#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int parent[40000];

int compara(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int main() {
    int M, N;
    
    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }
        
        qsort(arestas, N, sizeof(Aresta), compara);
        
        for (int i = 0; i < M; i++) {
            parent[i] = i;
        }
        
        long long mst_soma = 0;  
        int arestas_usadas = 0;
        
        for (int i = 0; i < N; i++) {
            int raizU = find(arestas[i].u);
            int raizV = find(arestas[i].v);
            
            if (raizU != raizV) {
                parent[raizU] = raizV;
                mst_soma += arestas[i].peso;
                arestas_usadas++;
                
                if (arestas_usadas == M - 1) {
                    break;  
                }
            }
        }
        
        printf("%lld\n", mst_soma);
    }
    
    return 0;
}