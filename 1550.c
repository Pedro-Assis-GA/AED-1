#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005 

int dist[MAX];
int queue[MAX];

int reverse_num(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}

int bfs(int start, int target) {
    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }
    
    int head = 0, tail = 0;
    
    queue[tail++] = start;
    dist[start] = 0;
    
    while (head < tail) {
        int u = queue[head++];
        
        if (u == target) {
            return dist[u];
        }
        
        int v1 = u + 1;
        if (v1 < MAX && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            queue[tail++] = v1;
        }
        
        
        int v2 = reverse_num(u);
        if (v2 < MAX && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            queue[tail++] = v2;
        }
    }
    return -1;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        int A, B;
        if (scanf("%d %d", &A, &B) != 2) break;
        
        printf("%d\n", bfs(A, B));
    }
    
    return 0;
}