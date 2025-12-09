#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liberarMemoria(char **amigos, int total) {
    for (int i = 0; i < total; i++) {
        free(amigos[i]);
    }
}

int main() {
    char listaAtual[1000], novaLista[1000], amigoIndicado[21];
    char *amigos[200];
    int totalAmigos = 0;
    
    char listaAtualCopia[1000];
    char novaListaCopia[1000];

    if (!fgets(listaAtual, sizeof(listaAtual), stdin)) return 0;
    if (!fgets(novaLista, sizeof(novaLista), stdin)) return 0;
    if (!fgets(amigoIndicado, sizeof(amigoIndicado), stdin)) return 0;

    listaAtual[strcspn(listaAtual, "\n")] = '\0';
    novaLista[strcspn(novaLista, "\n")] = '\0';
    amigoIndicado[strcspn(amigoIndicado, "\n")] = '\0';
    
    strcpy(listaAtualCopia, listaAtual);
    strcpy(novaListaCopia, novaLista);

    char *nomeAmigo = strtok(listaAtualCopia, " ");
    while (nomeAmigo != NULL) {
        amigos[totalAmigos] = (char*)malloc((strlen(nomeAmigo) + 1) * sizeof(char));
        if (!amigos[totalAmigos]) return 1;
        strcpy(amigos[totalAmigos], nomeAmigo);
        totalAmigos++;
        nomeAmigo = strtok(NULL, " ");
    }

    int posicaoInsercao = totalAmigos;
    if (strcmp(amigoIndicado, "nao") != 0) {
        for (int i = 0; i < totalAmigos; i++) {
            if (strcmp(amigos[i], amigoIndicado) == 0) {
                posicaoInsercao = i;
                break;
            }
        }
    }

    nomeAmigo = strtok(novaListaCopia, " ");
    while (nomeAmigo != NULL) {
        for (int i = totalAmigos; i > posicaoInsercao; i--) {
            amigos[i] = amigos[i - 1];
        }

        amigos[posicaoInsercao] = (char*)malloc((strlen(nomeAmigo) + 1) * sizeof(char));
        if (!amigos[posicaoInsercao]) {
            liberarMemoria(amigos, totalAmigos);
            return 1;
        }
        strcpy(amigos[posicaoInsercao], nomeAmigo);
        
        posicaoInsercao++;
        totalAmigos++;
        
        nomeAmigo = strtok(NULL, " ");
    }

    for (int i = 0; i < totalAmigos; i++) {
        printf("%s", amigos[i]);
        if (i != totalAmigos - 1) printf(" ");
        free(amigos[i]);
    }
    printf("\n");
    
    return 0;
}
