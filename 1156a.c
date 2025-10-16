#include<stdio.h>
#include<stdlib.h>

#define ALTURA_MAX 211 
#define ALTURA_MIN 20

void count_sort_altura(int N){
    int count[ALTURA_MAX] = {0};
    int h;

    for(int i=0; i<N; i++){
        if(scanf("%d", &h) != 1){
            break;
        }
        count[h - ALTURA_MIN]++;
    }

    int primeira_impressao = 1;

    for(int i=0; i<ALTURA_MAX; i++){
        int altura_atual = i + ALTURA_MIN;

        int quantidade = count[i];

        for(int j=0;j<quantidade;j++){
            if(!primeira_impressao){
                printf(" ");
            }

            printf("%d", altura_atual);
            primeira_impressao = 0;
        }
    }
    printf("\n");
}

int main(){
    int NC;

    if(scanf("%d", &NC) != 1){
        return 0;
    }

    for(int i=0; i<NC; i++){
        int N;
        if(scanf("%d", &N) != 1){
            break;
        }
        count_sort_altura(N);
    }
    
    return 0;
}
