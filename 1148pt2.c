#include <stdio.h>
#include <string.h>
#define INF 1000000000
#define MAX 501

int main() {
    int N, E;
    int dist[MAX][MAX];
    int i, j, k;
    int X, Y, H;
    int K, O, D;
    
    while(1) {
        scanf("%d %d", &N, &E);
        
        if(N == 0 && E == 0) break;
        
        
        for(i = 1; i <= N; i++) {
            for(j = 1; j <= N; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }
        
        
        for(i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            
            
            
            if(dist[Y][X] != INF) {
                
                dist[X][Y] = 0;
                dist[Y][X] = 0;
            } else {
                dist[X][Y] = H;
            }
        }
        
        
        for(k = 1; k <= N; k++) {
            for(i = 1; i <= N; i++) {
                if(dist[i][k] == INF) continue;
                for(j = 1; j <= N; j++) {
                    if(dist[k][j] == INF) continue;
                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        scanf("%d", &K);
        
        
        for(i = 0; i < K; i++) {
            scanf("%d %d", &O, &D);
            
            if(dist[O][D] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist[O][D]);
            }
        }
        
        
        printf("\n");
    }
    
    return 0;
}