#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX];
int visited[MAX];
int component[MAX]; 
int comp_size;      
int V, E;

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void dfs(int u) {
    visited[u] = 1;
    component[comp_size++] = u;
    
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N, case_num = 1;
    
    if (scanf("%d", &N) != 1) return 0;

    while (case_num <= N) {
        if (scanf("%d %d", &V, &E) != 2) break;

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        char u_char, v_char;
        for (int i = 0; i < E; i++) {
            scanf(" %c %c", &u_char, &v_char);
            int u = u_char - 'a';
            int v = v_char - 'a';
            
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        printf("Case #%d:\n", case_num);

        int connected_components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                connected_components++;
                comp_size = 0;
                
                dfs(i);
                
                qsort(component, comp_size, sizeof(int), cmp);
                
                for (int j = 0; j < comp_size; j++) {
                    printf("%c,", component[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n", connected_components);
        printf("\n"); 

        case_num++;
    }

    return 0;
}