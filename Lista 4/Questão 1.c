/*
Quest�o 1) Implemente:
a) Uma fun��o void que receba dois argumentos: o endere�o de uma vari�vel do tipo int e um
valor para inicializ�-la. A fun��o dever� atribuir o valor passado como segundo argumento para
a vari�vel recebida como primeiro argumento. Na main(), imprimir a vari�vel.

b) Uma fun��o void que receba 4 par�metros: dois ponteiros referentes a 2 vetores de inteiros
(n�o necessariamente ordenados) e os respectivos tamanhos dos vetores. Da�, imprimir os
valores em ordem crescente global, i.e, a ordem crescente ap�s a fus�o dos 2 vetores.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TAM_1 3
#define TAM_2 5

// Item (a)
void atribuiValor(int *var, int valor){
	*var = valor;
	return;
} 

// Item (b)
void exibeVetOrdenado(int *v1, int tam1, int *v2, int tam2){
	int tamTotal = tam1+tam2, i,
	*vTotal = (int*) malloc(tamTotal * sizeof(int));
	// Uni�o dos vetores ponteiros
	for(i = 0; i < tam1; ++i) vTotal[i] = v1[i];
	for(; i < tamTotal; ++i) vTotal[i] = v2[i-tam1];
	// Ordena��o (Bubble)
	bool ordenado = false; 
	int fim = tamTotal; 
	while (!ordenado) {
		ordenado = true;
		for (i = 0; i < fim - 1; i++) {
			if (vTotal[i] > vTotal[i+1]) {
				int aux = vTotal[i];
				vTotal[i] = vTotal[i + 1];
				vTotal[i + 1] = aux;
				ordenado = false;
			}
		}
		fim--;
	}
	for(i = 0; i < tamTotal; ++i) printf("%d ", vTotal[i]);
	free(vTotal); return;
}

int main(){
	// Item (a)
	srand(time(NULL));
	int inteiro;
	
	atribuiValor(&inteiro, 5); // N�mero a ser atribu�do: 5.
	printf("Item (a): %d\n", inteiro);
	// Item (b)
    int *vet1, *vet2;
    
	vet1 = (int*) malloc(TAM_1 * sizeof(int));
    vet2 = (int*) malloc(TAM_2 * sizeof(int));
    for(int i = 0; i < TAM_1; ++i) vet1[i] = rand() % 11;
    for(int i = 0; i < TAM_2; ++i) vet2[i] = rand() % 11;
    printf("Item (b): ");
	exibeVetOrdenado(vet1, TAM_1, vet2, TAM_2);
	free(vet1);
	free(vet2);
	return 0;
}
