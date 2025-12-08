#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003 

int hash(int id) {
    return id % HASH_SIZE;
}

int main() {
    int N, M;
    
    scanf("%d", &N);
    
    int fila[N];
    int tabela[HASH_SIZE];

    for (int i = 0; i < HASH_SIZE; i++) {
        tabela[i] = -1;
    }
    
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
        int pos = hash(fila[i]);
        tabela[pos] = fila[i];  
    }
    
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        int pos = hash(id);
        tabela[pos] = -2;  
    }
    
    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        int pos = hash(fila[i]);
        if (tabela[pos] == fila[i]) {  
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");
    
    return 0;
}