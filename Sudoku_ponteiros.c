#include <stdio.h>
#define SIZE 9

void imprimirTabuleiro(int (*board)[SIZE]) {
    printf("--- Tabuleiro Sudoku ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", *(*(board + i) + j));
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < SIZE - 1) {
            printf("------------------------\n");
        }
    }
    printf("------------------------\n");
}
int eMovimentoValido(int (*board)[SIZE], int linha, int coluna, int numero) {
    for (int j = 0; j < SIZE; j++) {
        if (*(*(board + linha) + j) == numero) {
            return 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (*(*(board + i) + coluna) == numero) {
            return 0;
        }
    }
    int inicioLinha = linha - (linha % 3);
    int inicioColuna = coluna - (coluna % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(board + inicioLinha + i) + inicioColuna + j) == numero) {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int puzzle[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int linha, coluna, numero;
    while(1){
        imprimirTabuleiro(puzzle);
        printf("\nDigite a linha (1-9), coluna (1-9) e o numero (1-9), separados por espaco: ");
        if(scanf("%d %d %d", &linha, &coluna, &numero) != 3) {
            printf("Entrada invalida! Por favor, use o formato 'linha coluna numero'.\n");
            while (getchar() != '\n'); 
            continue;
        }
        linha--; 
        coluna--; 
        if(linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE || numero < 1 || numero > 9) {
            printf("Posicoes e numeros devem ser entre 1 e 9. Tente novamente.\n");
            continue;
        }
        if(*(*(puzzle + linha) + coluna) != 0) {
            printf("Essa posicao ja esta preenchida. Tente outra.\n");
            continue;
        }
        if(eMovimentoValido(puzzle, linha, coluna, numero)) {
            *(*(puzzle + linha) + coluna) = numero;
            printf("Movimento valido! O tabuleiro foi atualizado.\n");
        } else {
            printf("Movimento invalido! Esse numero nao pode ser colocado nessa posicao.\n");
        }
    }
    return 0;
}
