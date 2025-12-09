#include <stdio.h>
#include <stdbool.h>

#define MAX_VAGOES 1001

bool eh_possivel(int N, int* ordem_desejada) {
    int pilha[MAX_VAGOES];
    int topo = -1; 
    int next_entrada = 1; 

    for (int i = 0; i < N; i++) {
        int vagao_desejado = ordem_desejada[i];

        if (topo != -1 && pilha[topo] == vagao_desejado) {
            topo--; 
            continue;
        }

        while (next_entrada <= N && next_entrada != vagao_desejado) {
            pilha[++topo] = next_entrada;
            next_entrada++; 
        }

        if (next_entrada == vagao_desejado) {
            next_entrada++; 
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) {
        
        int ordem_desejada[MAX_VAGOES];
        
        while (true) {
            int primeiro_vagao;
            
            if (scanf("%d", &primeiro_vagao) != 1) {
                break;
            }
            
            if (primeiro_vagao == 0) {
                printf("\n");
                break;
            }
            
            ordem_desejada[0] = primeiro_vagao;
            for (int i = 1; i < N; i++) {
                scanf("%d", &ordem_desejada[i]);
            }
            
            if (eh_possivel(N, ordem_desejada)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}