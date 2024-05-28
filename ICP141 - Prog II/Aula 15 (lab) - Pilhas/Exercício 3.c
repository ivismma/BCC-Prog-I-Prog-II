#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_STR 26

/*
 Escreva uma função que verifique se uma palavra é 
um palíndromo (se pode ler,	indiferentemente, da 
esquerda para a direita ou vice-versa).
Utilize uma pilha que armazene caracteres em sua solução.
*/

typedef struct node{
	char letra;
	struct node *prox;
} Node;

Node* empilhar(Node* topo, char valor);
char desempilhar(Node** topo);

int main(void){
	
	Node *pilha1 = NULL;
	Node *pilha2 = NULL; // Checar
	int pilha1_tam = 0;
	char c;
	
	while(scanf("%c", &c), c != '\n'){
		pilha1 = empilhar(pilha1, c);
		++pilha1_tam;
	}
		
	for(int i = 0; i < pilha1_tam/2; ++i)
		pilha2 = empilhar(pilha2, desempilhar(&pilha1));
	
	if(pilha1_tam%2 != 0)
		desempilhar(&pilha1);
		
	bool palindromo = true;
	while(pilha1 != NULL && pilha2 != NULL){
		if(desempilhar(&pilha1) != desempilhar(&pilha2)){
			palindromo = false;
			break;
		}
	}
		
	if(palindromo)
		printf("Palindromo");
	else
		printf("Nao Palindromo");

	return 0;
}






Node* empilhar(Node* topo, char valor){
	Node* novo = (Node*) calloc(1, sizeof(Node));
	novo->letra = valor;
	if(topo == NULL) return novo;
	
	novo->prox = topo;
	return novo;
}

char desempilhar(Node** topo){
	if(*topo == NULL) EXIT_FAILURE;
	
	Node *aux = *topo;
	*topo = (*topo)->prox;
	int valor = aux->letra;
	free(aux);
	return valor;
}
