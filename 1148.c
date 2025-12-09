#include <stdio.h>
#include <string.h>
#define MAX 501
#define INF 1000000000

int dist[MAX][MAX];
int adj_nao_dir[MAX][MAX]; 
int visitado[MAX];
int componente[MAX];
int N, comp_id;

void dfs(int u, int id) {
    componente[u] = id;
    visitado[u] = 1;
    
    for (int v = 1; v <= N; v++) {
        if (adj_nao_dir[u][v] && !visitado[v]) {
            dfs(v, id);
        }
    }
}

void floyd_warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= N; j++) {
                if (dist[k][j] == INF) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int E;
    
    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = INF;
                adj_nao_dir[i][j] = 0;
            }
            dist[i][i] = 0;
            visitado[i] = 0;
            componente[i] = 0;
        }
        
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            
            if (dist[Y][X] != INF) {
                dist[X][Y] = 0;
                dist[Y][X] = 0;
            } else {
                dist[X][Y] = H;
            }
            
            adj_nao_dir[X][Y] = 1;
            adj_nao_dir[Y][X] = 1;
        }
        
        comp_id = 1;
        for (int i = 1; i <= N; i++) {
            if (!visitado[i]) {
                dfs(i, comp_id);
                comp_id++;
            }
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (componente[i] == componente[j]) {
                    dist[i][j] = 0;
                }
            }
        }
        
        floyd_warshall();
        
        int K;
        scanf("%d", &K);
        
        for (int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D);
            
            if (dist[O][D] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist[O][D]);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}