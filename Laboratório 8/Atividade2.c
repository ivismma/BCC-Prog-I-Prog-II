/*Atividade 2: Uma operação muito comum em computação é a intercalação de dois vetores que já
estão ordenados. Considere um vetor A de tamanho N e outro B de tamanho M. O vetor resultante
C é construído a partir dos dois vetores originais e terá tamanho N + M.
Tarefa:
1) Escreva uma função que receba como entrada um par de vetores já ordenados e seus
respectivos tamanhos, os intercale formando um novo vetor ordenado, e imprima o
resultado.

2) Escreva um programa para testar sua função. Use o exemplo mostrado abaixo e outros que
você mesmo pode criar.
Obs.: explore o fato de que os vetores de entrada já estão ordenados. Simplificará a
implementação da solução.*/

#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <limits.h>

void exibirVetor (int v[], int tam){
	for(int i = 0; i < tam; ++i) printf("%d ", v[i]);
}

void ordenaParVetores(int v1[],int v2[], int v3[],int tam[]){
	int total = tam[0] + tam[1];
	int i = 0, j = 0, k = 0;
	while(i < total){
		while(1){
			if(v1[j] < v2[k]){
				v3[i] = v1[j];
				++j; ++i;
				break;
			} else{
				v3[i] = v2[k];
				++k; ++i;
				break;
			}
		}
	}
}

int main(){
	int tam[2], i; // Vetor tam que armazena o tamanho do vetor 1 e vetor 2, respectivamente.
	printf("Insira o tamanho do vetor 1 e 2, respectivamente (separado por espaço):\n");
	
	for(i=0;i < 2;++i){
		scanf("%d", &tam[i]);
	} int v1[tam[0]],v2[tam[1]]; // Uso do vetor tam para criar os vetores.
	int tamTotal = tam[0] + tam[1];
	int v3[tamTotal];
	
	printf("Insira os elementos do vetor 1, separado por espaços (lembre-se do seu tamanho):\n");
	for(i=0; i < tam[0]; ++i){
		scanf("%d", &v1[i]);
	}
	printf("Insira os elementos do vetor 2, separado por espaços (lembre-se do seu tamanho):\n");
	for(i=0; i < tam[1]; ++i){
		scanf("%d", &v2[i]);
	}
	
	ordenaParVetores(v1,v2,v3,tam);
	printf("\n"); exibirVetor(v3,tamTotal);
	
	return 0;
}
