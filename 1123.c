#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 260
#define INF INT_MAX

int grafo[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int N, M, C, K;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dijkstra(int origem) {
    int i, j, u, min_dist;
    
    for (i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;
    
    for (i = 0; i < N; i++) {
        u = -1;
        min_dist = INF;
        for (j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        
        if (u == -1 || dist[u] == INF) break;
        
        visitado[u] = 1;
        
        for (j = 0; j < N; j++) {
            if (grafo[u][j] != -1 && !visitado[j]) {
                int custo = grafo[u][j];
                
                if (u < C) {
                    if (j == u + 1) {
                        if (dist[j] > dist[u] + custo) {
                            dist[j] = dist[u] + custo;
                        }
                    }
                } else {
                    if (dist[j] > dist[u] + custo) {
                        dist[j] = dist[u] + custo;
                    }
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        
        int i, j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                grafo[i][j] = -1;
            }
        }
        
        
        for (i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            
            grafo[U][V] = P;
            grafo[V][U] = P;
        }
        
        
        dijkstra(K);
        
        
        printf("%d\n", dist[C-1]);
    }
    
    return 0;
}