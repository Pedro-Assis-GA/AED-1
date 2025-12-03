#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

char grid[MAX][MAX + 1];
int N, M;

int qr[MAX * MAX];
int qc[MAX * MAX];

void bfs(int r, int c) {
    int head = 0, tail = 0;
    
    qr[tail] = r;
    qc[tail] = c;
    tail++;
    
    grid[r][c] = 'o';
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    while (head < tail) {
        int curr_r = qr[head];
        int curr_c = qc[head];
        head++;
        
        for (int i = 0; i < 4; i++) {
            int nr = curr_r + dr[i];
            int nc = curr_c + dc[i];
            
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == '.') {
                grid[nr][nc] = 'o';
                qr[tail] = nr;
                qc[tail] = nc;
                tail++;
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') {
                cliques++;
                bfs(i, j);
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}