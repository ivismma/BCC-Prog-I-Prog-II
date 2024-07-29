#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Ex. 2

Faça um programa que calcule o resultado de uma expressão em notação 
pós-fixada, recebida através de um arquivo texto, utilizando uma pilha.

Considere que os operandos e resultados das operações realizadas são todos
inteiros.
*/

// nó
typedef struct node{
	double num;
	struct node *prox;
} Node;

void empilhar(Node** topo, double num);
double desempilhar(Node** topo);
void esvaziar(Node **topo);
bool numero(char c);
float operacao(double n1, double n2, char op);

int main(void){

	Node *pilha = NULL;
	FILE *arq = fopen("ex2.txt", "r");
	if(arq == NULL){
		printf("Falha na abertura do arquivo\n");
		EXIT_FAILURE;
	}
	
	char buffer;
	while( (buffer = getc(arq)) != EOF){
		if(numero(buffer))
			empilhar(&pilha, atof(&buffer));
		else{
			double n2 = desempilhar(&pilha);
			double n1 = desempilhar(&pilha);
			double res = operacao(n1, n2, buffer);
			printf("%.2lf %c %.2lf = %.2lf\n", n1, buffer, n2, res);
			empilhar(&pilha, res);
		}
	}
	printf("\nResultado da expressao em notacao pos fixada:\n-->%.2lf\n", desempilhar(&pilha));
	
	esvaziar(&pilha);
	
	return 0;
}

float operacao(double n1, double n2, char op){
	switch(op){
		case '+':
			return n1 + n2;
		case '-':
			return n1 - n2;
		case '*':
			return n1 * n2;
		case '/':
			return n1 / n2;
		default:
			printf("Operacao invalida.\n");
			EXIT_FAILURE;
	}
}

bool numero(char c){
	return (c >= '0' && c <= '9');
}









// gerenciamento de pilha

void esvaziar(Node **topo){
	Node *prox;
	for(Node *atual = *topo; atual != NULL; atual = prox){
		prox = atual->prox;
		free(atual);
	}
	*topo = NULL;
}

void empilhar(Node** topo, double num){
	Node* novo = (Node*) calloc(1, sizeof(Node));
	novo->num = num;
	
	if(*topo == NULL) *topo = novo;
	else{
		novo->prox = *topo;
		*topo = novo;
	}
}

double desempilhar(Node** topo){
	if(*topo == NULL) EXIT_FAILURE;
	
	Node *aux = *topo;
	*topo = (*topo)->prox;
	double ret = aux->num;
	free(aux);
	return ret;
}
