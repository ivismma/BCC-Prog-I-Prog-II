#include <stdio.h>
#include <stdlib.h>

/*
Fa�a uma fun��o	para obter a convers�o	
num�rica, utilizando	uma	pilha, de Decimal	
(base 10) para Bin�rio (base 2).		
Teste sua fun��o, criando um programa	
principal que a	utilize.
*/

typedef struct node{
	char valor;
	struct node *prox;
} Node;

Node* empilhar(Node* topo, char valor);
char desempilhar(Node** topo);

int main(void){	
	int n;
	Node *pilha = NULL;
	printf("Digite um numero decimal\n--> ");
	scanf("%d", &n);
	
	while(n){
		pilha = empilhar(pilha, 48+n%2);
		n = n/2;
	}
	Node *atual = pilha;
	while(atual != NULL)
		printf("%c", desempilhar(&atual));
	
	return 0;
}








Node* empilhar(Node* topo, char valor){
	Node* novo = (Node*) calloc(1, sizeof(Node));
	novo->valor = valor;
	if(topo == NULL) return novo;
	
	novo->prox = topo;
	return novo;
}

char desempilhar(Node** topo){
	if(*topo == NULL) EXIT_FAILURE;
	
	Node *aux = *topo;
	*topo = (*topo)->prox;
	int valor = aux->valor;
	free(aux);
	return valor;
}
