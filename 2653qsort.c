#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

char joias[MAX][100];
int total = 0;

int comparar(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    while (scanf("%s", joias[total]) != EOF) {
        total++;
    }
    
    qsort(joias, total, 100, comparar);
    
    int distintas = 0;
    if (total > 0) {
        distintas = 1;
        for (int i = 1; i < total; i++) {
            if (strcmp(joias[i], joias[i-1]) != 0) {
                distintas++;
            }
        }
    }
    
    printf("%d\n", distintas);
    
    return 0;
}