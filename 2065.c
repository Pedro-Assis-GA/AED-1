#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i, j;
    
    scanf("%d %d", &N, &M);
    
    int V[N];
    int C[M];
    
    long long tempo_termino_caixa[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &V[i]);
        tempo_termino_caixa[i] = 0;
    }

    for (j = 0; j < M; j++) {
        scanf("%d", &C[j]);
    }

    for (i = 0; i < M; i++) {
        int caixa_livre_idx = 0;
        
        for (j = 1; j < N; j++) {
            if (tempo_termino_caixa[j] < tempo_termino_caixa[caixa_livre_idx]) {
                caixa_livre_idx = j;
            }
        }
        
        tempo_termino_caixa[caixa_livre_idx] += (long long)V[caixa_livre_idx] * C[i];
    }

    long long tempo_maximo = 0;
    
    for (i = 0; i < N; i++) {
        if (tempo_termino_caixa[i] > tempo_maximo) {
            tempo_maximo = tempo_termino_caixa[i];
        }
    }

    printf("%lld\n", tempo_maximo);

    return 0;
}
