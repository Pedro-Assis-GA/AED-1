#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 55

typedef struct no_fila {
    int card;
    struct no_fila *proximo;
} NoFila;

typedef struct fila {
    NoFila *cabeca;
    NoFila *fim;
} Fila;

void inicializar_fila(Fila *f) {
    f->cabeca = (NoFila *)malloc(sizeof(NoFila));
    if (f->cabeca == NULL) {
        fprintf(stderr, "Erro de alocacao da cabeca.\n");
        exit(EXIT_FAILURE);
    }
    f->cabeca->proximo = NULL; 
    f->fim = f->cabeca;
}

int is_empty(Fila *f) {
    return (f->cabeca->proximo == NULL);
}

void enqueue(Fila *f, int card) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao.\n");
        exit(EXIT_FAILURE);
    }
    novo->card = card;
    novo->proximo = NULL;

    f->fim->proximo = novo;
    f->fim = novo;
}

int dequeue(Fila *f, int *card) {
    if (is_empty(f)) {
        return 0;
    }

    NoFila *temp = f->cabeca->proximo; 
    *card = temp->card;

    f->cabeca->proximo = temp->proximo;

    if (f->fim == temp) {
        f->fim = f->cabeca;
    }

    free(temp);
    return 1;
}

void liberar_fila(Fila *f) {
    NoFila *atual = f->cabeca;
    NoFila *proximo_no;
    
    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    f->cabeca = NULL;
    f->fim = NULL;
}

void process_case(int n) {
    if (n == 0) return;

    Fila card_queue;
    inicializar_fila(&card_queue);

    int discarded_list[MAX_SIZE];
    int discarded_count = 0;
    int card_value;
    
    for (int i = 1; i <= n; i++) {
        enqueue(&card_queue, i);
    }

    if (n == 1) {
        printf("Discarded cards:\n");
        printf("Remaining card: 1\n");
        liberar_fila(&card_queue);
        return;
    }

    while (card_queue.cabeca->proximo != card_queue.fim) {
        
        dequeue(&card_queue, &card_value);
        discarded_list[discarded_count++] = card_value;
        
        dequeue(&card_queue, &card_value);
        enqueue(&card_queue, card_value);
    }
    
    printf("Discarded cards: ");
    for (int i = 0; i < discarded_count; i++) {
        printf("%d", discarded_list[i]);
        if (i < discarded_count - 1) {
            printf(", ");
        }
    }
    printf("\n"); 

    if (!is_empty(&card_queue)) {
        dequeue(&card_queue, &card_value);
        printf("Remaining card: %d\n", card_value);
    } 
    
    liberar_fila(&card_queue);
}

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        process_case(n);
    }
    
    return 0;
}
