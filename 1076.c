#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 50 

int solve_case(int V_count, int A_count) {
    int degree[MAX_VERTICES] = {0}; 

    int u, v;
    for (int i = 0; i < A_count; i++) {
        if (scanf("%d %d", &u, &v) != 2) {
            break; 
        }
        
        degree[u]++;
        degree[v]++;
    }

    int odd_degree_count = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (degree[i] % 2 != 0) {
            odd_degree_count++;
        }
    }
    

    return A_count + (odd_degree_count / 2);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        int N_start, V_count, A_count;
        
        if (scanf("%d", &N_start) != 1) break;
        
        if (scanf("%d %d", &V_count, &A_count) != 2) break;
        
        int result = solve_case(V_count, A_count);
        printf("%d\n", result);
    }

    return 0;
}