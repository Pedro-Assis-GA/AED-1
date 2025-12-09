#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char linha[1001]; 

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    getchar(); 

    while (N--) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }

        int diamantes_encontrados = 0;
        int abridores_nao_pareados = 0;
        
        int tamanho = strlen(linha);

        for (int i = 0; i < tamanho; i++) {
            char caractere = linha[i];

            if (caractere == '<') {
                abridores_nao_pareados++;
            } else if (caractere == '>') {
                if (abridores_nao_pareados > 0) {
                    diamantes_encontrados++;
                    abridores_nao_pareados--;
                }
            }
        }

        printf("%d\n", diamantes_encontrados);
    }

    return 0;
}