#include <stdio.h>
#include <stdlib.h>

int comparar_decrescente(const void *a, const void *b) {
    int nota_a = *(const int *)a;
    int nota_b = *(const int *)b;
    
    return (nota_b - nota_a);
}

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    while (N--) {
        int M;
        
        if (scanf("%d", &M) != 1) {
            continue;
        }

        int notas_original[M];
        int notas_ordenada[M];
        
        int mantiveram_posicao = 0;

        for (int i = 0; i < M; i++) {
            int nota;
            if (scanf("%d", &nota) != 1) {
                break; 
            }
            notas_original[i] = nota;
            notas_ordenada[i] = nota;
        }
        
        qsort(notas_ordenada, M, sizeof(int), comparar_decrescente);
        
        for (int i = 0; i < M; i++) {
            if (notas_original[i] == notas_ordenada[i]) {
                mantiveram_posicao++;
            }
        }
        
        printf("%d\n", mantiveram_posicao);
    }

    return 0;
}