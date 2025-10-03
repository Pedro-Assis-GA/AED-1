#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int X[N];
    int menor_valor;
    int posicao_menor_valor = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        if (i == 0) {
            menor_valor = X[i];
        } else if (X[i] < menor_valor) {
            menor_valor = X[i];
            posicao_menor_valor = i;
        }
    }
    
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao_menor_valor);
    
    return 0;
}
