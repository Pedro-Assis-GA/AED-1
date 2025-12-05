#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int parent[MAX];
int rank[MAX];

int compara(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  
    }
    return parent[x];
}

int union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX == rootY) return 0;  
    
    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    
    return 1;
}

int main() {
    int m, n;
    
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            total += arestas[i].peso;
        }
        
        qsort(arestas, n, sizeof(Aresta), compara);
        
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int mst_peso = 0;
        int arestas_usadas = 0;
        
        for (int i = 0; i < n && arestas_usadas < m - 1; i++) {
            if (union_sets(arestas[i].u, arestas[i].v)) {
                mst_peso += arestas[i].peso;
                arestas_usadas++;
            }
        }
        
        printf("%d\n", total - mst_peso);
    }
    
    return 0;
}