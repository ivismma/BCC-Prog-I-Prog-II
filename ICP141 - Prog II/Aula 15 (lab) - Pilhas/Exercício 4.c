#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY_ENTER 10 // Enter em ASCII

/*
Escreva	uma	função para	verificar se uma	expressão	
matemática tem os parênteses, colchetes	e chaves	
balanceados	e agrupados	deforma correta

Utilize uma Pilha que armazene os caracteres em sua solução.
Exemplos de expressões incorretas: ((A+B) ou A+B( ou (A+B-[C+D)
[A+B(C-D]) etc.
Corretas: (A+B), [A+(B+C)], etc
*/

// Nó
typedef struct node{
	char valor;
	struct node *prox;
} Node;

Node* empilhar(Node* topo, char valor);
char desempilhar(Node** topo);
bool verificarExpressao(Node *topo);
bool letraouSinal(char c);

int main(void){
	Node *pilha = NULL; // Pilha vazia.
	char c;
		
	printf("Digite a expressao:\n--> ");
	while(scanf("%c", &c), c != KEY_ENTER)
		pilha = empilhar(pilha, c);
	
	if(verificarExpressao(pilha))
		printf("Expressao correta\n");
	else 
		printf("Expressao incorreta\n");
		
	return 0;
}

bool verificarExpressao(Node *topo){
	Node *atual = topo;
	int parenteses = 0, colchetes = 0, chaves = 0;
	while(atual != NULL){
		char c = atual->valor;
		if(letraouSinal(c)){ // Ignorar letras e sinais (A,B,+,-,...).
			atual = atual->prox;
			continue;
		}
		switch(c){
			case '(':
				if(parenteses) --parenteses;
				else return false;
				break;
			case ')':
				++parenteses;
				break;
			case '[':
				if(colchetes) --colchetes;
				else return false;
				break;
			case ']':
				++colchetes;
				break;
			case '{':
				if(chaves) --chaves;
				else return false;
				break;
			case '}':
				++chaves;
				break;
			default:
				break;
		}
		atual = atual->prox;
	}
	return !(parenteses || colchetes || chaves);
}

bool letraouSinal(char c){ // é letra ou sinal
	return (isalpha(c) || c == '+' || c == '-' || c == '*' || c == '/');
}








// gerenciamento de pilhas..

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
