#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO_MAX 1005

typedef struct NoPilha{
    char caractere;
    struct NoPilha *proximo;
} NoPilha;

NoPilha *push(NoPilha *topo, char valor){
    NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    if(novoNo == NULL){
        exit(EXIT_FAILURE);
    }

    novoNo->caractere = valor;
    novoNo->proximo = topo;

    return novoNo;
}

NoPilha *pop(NoPilha *topo){
    NoPilha *temp = topo;
    NoPilha *novo_topo = topo->proximo;

    free(temp);

    return novo_topo;
}

int checar_parenteses(const char *expressao){
    NoPilha *topo = NULL;
    int i;

    for(i=0; expressao[i] != '\0'; i++){
        char caractere = expressao[i];

        if(caractere == '('){
            topo = push(topo, caractere);
        }else if(caractere == ')'){
            if(topo == NULL){
                return 0;
            }
            topo = pop(topo);
        }
    }

    if(topo == NULL){
        return 1;
    }else{
        while(topo != NULL){
            NoPilha *temp = topo;
            topo = topo->proximo;
            free(temp);
        }
        return 0;
    }
}

int main(){
    char linha[TAMANHO_MAX];

    while(fgets(linha, TAMANHO_MAX, stdin) != NULL){
        if(checar_parenteses(linha)){
            printf("Correto\n");
        }else{
            printf("Incorreto\n");
        }
    }

    return 0;
}
