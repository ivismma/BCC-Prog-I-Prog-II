#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int chave; // O registro é um int.
	struct node *prox;
} Node; // nó.

typedef struct{
	Node *topo; // início da lista.
} Lista;

//////////////// p/ testes /////////
void exibir(Lista *lista);
int pop(Lista *lista);               
void push(Lista *lista, int valor);  
////////////////////////////////////

void concatenaListas(Lista *l1, Lista *l2);
bool iguaisListas(Lista *l1, Lista *l2);
bool modificaElem(Lista *l1, int reg, int pos);

int main(void){
	
	Lista lista1 = {NULL};
	Lista lista2 = {NULL};
	
	push(&lista1, 8);
	push(&lista1, 7);
	push(&lista1, 6);
	push(&lista2, 11);
	push(&lista2, 10);
	push(&lista2, 9);
	
	exibir(&lista1);
	puts("");
	exibir(&lista2);
	
	if(iguaisListas(&lista1, &lista2)) printf("Sao iguais.\n\n");
	else printf("Nao sao iguais.\n\n");
	
	concatenaListas(&lista1, &lista2);
	exibir(&lista1);
	printf("Troca elemento posicao 5 para 20:\n");
	modificaElem(&lista1, 20, 5);
	exibir(&lista1);
	
	
	// suponha desalocacao de memória aqui.
	
	return 0;
}

void concatenaListas(Lista *l1, Lista *l2){
	Node* topo1 = l1->topo;
	while(topo1->prox != NULL)
		topo1 = topo1->prox;
		
	topo1->prox = l2->topo;
}

bool iguaisListas(Lista *l1, Lista *l2){
	Node *atual1 = l1->topo;
	Node *atual2 = l2->topo;
	
	while(atual1 && atual2){
		if(atual1->chave != atual2->chave){
			return false;
		}
		atual1 = atual1->prox;
		atual2 = atual2->prox;
	}
	
	if(atual1 == NULL && atual2 == NULL)
		return true;  // possuem mesmo tamanho e são iguais.
	else
		return false; // não possuem mesmo tamanho.
}

bool modificaElem(Lista *l1, int reg, int pos){
	Node *atual = l1->topo;
	
	for(int i = 0; i < pos; ++i){
		if(atual == NULL) return false;
		
		atual = atual->prox;
	}
	atual->chave = reg;
	return true;
}


















void exibir(Lista *lista){
	Node *atual = lista->topo;
	for(; atual != NULL; atual = atual->prox)
		printf("%d ", atual->chave);	
	
	printf("\n");
}

int pop(Lista *lista){
	if(lista->topo == NULL) exit(1); 
	
	Node *aux = lista->topo;
	int chave = aux->chave;
	lista->topo = aux->prox;
	free(aux);
	
	return chave;
}

void push(Lista *lista, int valor){
	Node *novo = (Node *) calloc(1, sizeof(Node)); // alocação novo nó
	if(novo == NULL) exit(2);
	novo->chave = valor;
	
	if(lista->topo == NULL){ 
		lista->topo = novo;
	}
	else{ 
		novo->prox = lista->topo;
		lista->topo = novo;
	}
}
