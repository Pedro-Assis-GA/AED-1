#include<stdio.h>
#include<stdlib.h>

int main(){

    int n;
    printf("Tamanho vetor: ");
    scanf("%d", &n);
    while(n<1||n>1000){
        printf("Valor invalido, digite entre 1 e 1000");
        return 1;
    }
    int *v = (int*)malloc(n * sizeof(int));
    if(v == NULL){
        printf("Erro de aloc de memoria");
        return 1;
    }
    printf("Preencha o vetor:\n");
    for(int i=0; i<n; i++){
        printf("Elemento V[%d]= ", i+1);
        scanf("%d", &v[i]);
    }    
    int menor = v[0];
    int posicao = 0;
    for(int i=0; i<n; i++){
        if(menor > v[i]){
            menor = v[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao = %d\n", posicao+1);

    return 0;
}
