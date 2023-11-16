/*Quest�o 5) Assim como fizemos no Laborat�rio 9, crie um tipo de dados para representar uma
Pessoa, mas agora, al�m dos campos idade (inteiro) e peso (float), inclua tamb�m o campo nome
(string). Implemente a fun��o main, onde um vetor de Pessoas (m�ximo de 50) dever� ser preenchido
pelo usu�rio. Ordene esse vetor em ordem decrescente de idade e imprima o vetor ordenado na tela.
Crie essa l�gica de ordena��o na pr�pria main.
- Agora, modifique o programa como segue: ap�s a ordena��o do vetor, permita que o
usu�rio insira uma idade. A partir da�, crie uma fun��o que receba de entrada o vetor ordenado e a
idade informada, e ent�o realize uma busca bin�ria no vetor de Pessoas, retornando o �ndice no vetor
onde a pessoa possui a referida idade, ou -1 se ningu�m for encontrado. No caso de duas ou mais
pessoas com idades iguais, basta retornar um �nico �ndice. Na main, imprima o nome dessa pessoa.
CUIDADO: o vetor est� em ordem decrescente. Sua busca bin�ria leva isso em conta!*/

#include <stdio.h>
#include <stdbool.h>
#define TAM 3
#define FALSE 0
#define TRUE 1

typedef struct{
	char nome[50+1];
	float peso;
	int idade;
} TPessoa;

void preencheVetor(TPessoa pessoa[], int v[]){
	for (int i = 0; i < TAM; i++)
		v[i] = pessoa[i].idade;
} 

void exibirVetor(int v[]){
	int i = 0;
	while(i < TAM)
		printf("%d ", v[i++]);
} 

// Recebe um vetor v1 e o copia em v2.
// Ambos devem ter o mesmo tamanho.
int copiaVetor(int v1[], int v2[]){
	int n = (sizeof(v1)/sizeof(v1[0]))+1;
	
	if ( (sizeof(v2)/sizeof(v2[0]))+1 != n ){
		printf("Erro - Vetores n�o possuem o mesmo tamanho.");
		return FALSE;
	}
	
	int i = 0;
	for(int i = 0; i < n;++i) v2[i] = v1[i];
	return TRUE;
}

int main(){
	TPessoa pessoa[TAM];
	int idade[TAM], idadeDec[TAM];
	
	for(int i = 0;i < TAM;i++){
		printf("Pessoa %d - Insira separado por espa�o o nome, a idade e o peso, respectivamente: ", i+1);
		scanf("%s", pessoa[i].nome);
		scanf("%d %d", &pessoa[i].idade, &pessoa[i].peso);
	} preencheVetor(pessoa, idade);
	
	printf("\nIdades inseridas:\n");
	exibirVetor(idade);
	
	/*Ordene esse vetor em ordem decrescente de idade e imprima o vetor ordenado na tela.
	Crie essa l�gica de ordena��o na pr�pria main.*/
	
	// Usa vetor ordenado decrescentemente a parte para preservar os dados da idade.
	copiaVetor(idade, idadeDec);
	
	// Bubble Sort p/ ordem decrescente | escopo criado para que a vari�vel i, aux, fim e ordenado deixe de ocupar mem�ria depois.
	{
		int i, aux, fim = TAM;
		bool ordenado; // o bool ordenado � uma flag.
		while(!ordenado){
			ordenado = true;
			for(i = 0;i < fim-1;++i){
				if(idadeDec[i] < idadeDec[i+1]){
					aux = idadeDec[i];
					idadeDec[i] = idadeDec[i+1];
					idadeDec[i+1] = aux;
					ordenado = false;
				}
			}
			--fim;
		}
	}
	
	printf("\nIdades em ordem decrescente:\n");
	exibirVetor(idadeDec);
	
	// Parte 2 do exerc�cio. Modificando...
	
	int busca, resultado = -1; // O resultado ser� iniciado como -1, se n�o for encontrada a idade, o valor j� est� pr� definido.
	printf("\nInsira uma idade para obter o indice (ser� retornado -1 caso ela n�o seja encontrada): ");
	scanf("%d", &busca);
	// Busca bin�ria decrescente:
	{
		int esq, meio, dir;
	    esq = 0;
	    dir = TAM - 1;
	    while (esq <= dir) {
	        meio = (esq + dir) / 2;
	        if (idadeDec[meio] == busca) {
	            resultado = meio; 
	            break; 
	        }
	        if (busca > idadeDec[meio]) // Basta inverter a esquerda com direita no caso de decrescente.
	            dir = meio - 1; 
	        else
	            esq = meio + 1; 
	    }
	}
	// Vale lembrar que por se tratar de uma busca bin�ria, pode haver mais de uma pessoa com mesma idade, ent�o
	// ele retornar� o primeiro encontrado.
	
	if(resultado == -1){
		printf("Idade n�o encontrada.");
		return -1;
	} 
	printf("\nIndice da idade inserida: %d", resultado);
	printf("\nNome da pessoa: %s", pessoa[resultado].nome);
	return 0;
}
