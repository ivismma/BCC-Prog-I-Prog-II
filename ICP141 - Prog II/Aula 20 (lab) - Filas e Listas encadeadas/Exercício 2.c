#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcpy.

#define TEMPO_PGTO 10

// Ex. 2 da Lista de Filas - Inserção de dados de pessoas e o tempo do atendimento.
// obs: Exemplo de saída (Ana 25 42) nos slides está errado, correto: (Ana 25 37).

typedef struct node{
    char nome[30];
    int chegada;
    int numprodutos;
    struct node *prox;
} Node; // Nó da pessoa

typedef struct{
    Node *inicio; // A entrada na fila (onde as pessoas entram)
    Node *fim;    // A frente da fila (a pessoa que está no começo da fila)
} Fila;

void enfileirar(Fila *fila, char *nome, int tchegada, int numprodutos);
void inicializaFila(Fila **fila);
void liberarFila(Fila **fila);

int main(void) {
    int K, C;
    Fila *fila = NULL;

    scanf("%d", &K);
    scanf("%d", &C);
    inicializaFila(&fila);

	// Input e inserção:
    for(int i = 0; i < C; ++i){
        char nome[30];
        int cheg, numprodutos;
        scanf("%s %d %d", nome, &cheg, &numprodutos);
        enfileirar(fila, nome, cheg, numprodutos);
    }
    
    // Output (Resultados):
	Node *atual = fila->fim; // Começar da frente da fila
    while(atual != NULL){
        int cheg = atual->chegada;
        int saida = TEMPO_PGTO + (atual->numprodutos) * K + cheg;
        printf("%s %d %d\n", atual->nome, cheg, saida);
        atual = atual->prox;
    }

    liberarFila(&fila);

    return 0;
}






// gerenciamento de filas...

void inicializaFila(Fila **fila){
    if(*fila != NULL) return;

    *fila = (Fila*) calloc(1, sizeof(Fila));
    if(*fila == NULL) {
        printf("Falha alocacao\n");
        exit(1);
    }

    return;
}

void enfileirar(Fila *fila, char *nome, int tchegada, int numprodutos){
    Node *novo = (Node*) calloc(1, sizeof(Node));
    if(novo == NULL) exit(2); // Falha alocação
    
	strcpy(novo->nome, nome);
    novo->chegada = tchegada;
    novo->numprodutos = numprodutos;

    if(fila->inicio == NULL){ // 1º elemento
        fila->inicio = novo;
        fila->fim = novo;
    }
	else{
        fila->inicio->prox = novo;
        fila->inicio = novo;
    }
    return;
}

void liberarFila(Fila **fila){
    if(*fila == NULL) return;

    Node *atual = (*fila)->fim; // Começar da frente da fila
    while(atual != NULL){
        Node *aux = atual;
        atual = atual->prox;
        free(aux);
    }

    free(*fila);
}

