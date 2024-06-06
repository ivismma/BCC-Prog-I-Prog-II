#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex. 1 da Lista de Filas - inserção e intercalação entre duas filas (respeitando a ordem de inserção).

typedef struct node{
	int valor;
	struct node *prox;
} Node;

typedef struct{
	Node *inicio;
	Node *fim;
} Fila;

void inicializaFila(Fila **fila);
void enfileirar(Fila *fila, int valor);
int liberar(Fila *fila);
bool par(int n) {return n%2 == 0;};

 int main(void){
 	int n;
 	Fila *fila_par = NULL;
    Fila *fila_impar = NULL;
    inicializaFila(&fila_par);
    inicializaFila(&fila_impar);
	
	// leitura até que n = 0...
 	while(scanf("%d", &n), n != 0){
 		if(par(n))
		 	enfileirar(fila_par, n);
		else
			enfileirar(fila_impar, n);
 	}
    puts("\n");
    // Começar pelos ímpares (e verificar se ao menos há um).
    if(fila_impar->fim) printf("%d\n", liberar(fila_impar));
   
	// Intercalar entre as filas..
	for(int i = 0;fila_par->fim && fila_impar->fim;++i){
		if(par(i))
			printf("%d\n", liberar(fila_par));
		else
			printf("%d\n", liberar(fila_impar));
    }
    // Verificar se ainda resta números de uma das filas...
    if(fila_par->fim && !fila_impar->fim){
		Node *atual = fila_par->fim;
		for(;atual != NULL; atual = atual->prox)
			printf("%d\n", atual->valor);
	}
	else if(fila_impar->fim){
		Node *atual = fila_impar->fim;
		for(;atual != NULL; atual = atual->prox)
			printf("%d\n", atual->valor);
	}
    
    free(fila_par);
    free(fila_impar);
 	return 0;
}







// gerenciamento de filas...

void inicializaFila(Fila **fila){
    if(*fila != NULL) return;
    
    *fila = (Fila* ) calloc(1, sizeof(Fila));
    if(*fila == NULL){
        printf("Falha alocacao\n");
        exit(1);
    }
  
    return;
}

void enfileirar(Fila *fila, int valor){
    Node *novo = (Node*) calloc(1, sizeof(Node));
    if(novo == NULL) exit(2);
    novo->valor = valor;
    
    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }
    else{
        fila->inicio->prox = novo;
        fila->inicio = novo;
    }
    return;
}

int liberar(Fila *fila){
	if(fila->fim == NULL) return INT_MIN;
	
	Node *aux = fila->fim;
	int valor = aux->valor;
	fila->fim = aux->prox;
	free(aux);
	
	return valor;
}
