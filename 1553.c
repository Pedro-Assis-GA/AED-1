#include <stdio.h>
#include <string.h> 

#define MAX_PERGUNTA 101 

int main() {
    int N, K;

    while (scanf("%d %d", &N, &K) == 2 && (N != 0 || K != 0)) {
        int frequencia[MAX_PERGUNTA];

        memset(frequencia, 0, sizeof(frequencia));
        
        int P;    
        for (int i = 0; i < N; i++) {
            if (scanf("%d", &P) == 1) {
                frequencia[P]++;
            }
        }       
        int perguntas_frequentes = 0;      
        for (int i = 1; i < MAX_PERGUNTA; i++) {
            if (frequencia[i] >= K) {
                perguntas_frequentes++;
            }
        }
        
        printf("%d\n", perguntas_frequentes);
    }
    
    return 0;
}