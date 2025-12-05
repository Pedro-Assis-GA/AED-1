#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node* proximo;
} Node;

typedef struct {
    Node* cabeca;
} Lista;

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 0; caso < N; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);
        
        Lista* tabela = (Lista*)malloc(M * sizeof(Lista));
        
        for (int i = 0; i < M; i++) {
            tabela[i].cabeca = NULL;
        }
        
        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            
            int indice = chave % M;
            
            Node* novo = (Node*)malloc(sizeof(Node));
            novo->chave = chave;
            novo->proximo = NULL;
            
            if (tabela[indice].cabeca == NULL) {
                tabela[indice].cabeca = novo;
            } else {
                Node* atual = tabela[indice].cabeca;
                while (atual->proximo != NULL) {
                    atual = atual->proximo;
                }
                atual->proximo = novo;
            }
        }
        
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            
            Node* atual = tabela[i].cabeca;
            while (atual != NULL) {
                printf("%d -> ", atual->chave);
                atual = atual->proximo;
            }
            
            printf("\\\n");
        }
        
        for (int i = 0; i < M; i++) {
            Node* atual = tabela[i].cabeca;
            while (atual != NULL) {
                Node* temp = atual;
                atual = atual->proximo;
                free(temp);
            }
        }
        free(tabela);
        
        if (caso != N - 1) {
            printf("\n");
        }
    }
    
    return 0;
}