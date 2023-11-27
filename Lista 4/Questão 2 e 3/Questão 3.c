/*
Quest�o 3) Escreva um programa que receba o nome de um dos arquivos gerados no exerc�cio
anterior (os quais agora j� armazenam 10 n�meros em ponto flutuante). O programa dever� ent�o ler
os valores desse arquivo e imprimir na tela o maior n�mero encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30 // Tamanho m�ximo do nome do arquivo: 26 caracteres

// Para leitura de dados, vou utilizar o arquivo bin�rio (mais adequado).

// Retorna o maior n�mero de um vetor float.
float vetMaior(float v[]){
	float maior = v[0];
	for(int i = 0;i < 10; ++i) if(v[i] > maior) maior = v[i];
	return maior;
}

int main(){
	char str[TAM];
	FILE *arquivo;
	float n[10];
	
	// Nome do arquivo de texto:
	printf("Digite o nome do arquivo bin�rio que foi digitado na Q2: "); 
	scanf("%[^\n]", str); strcat(str, ".dat"); getchar();
	if(!(arquivo = fopen(str, "rb"))){
		printf("Erro na abertura do arquivo - Nome invalido ou acesso negado.");
		return -1;
	}
	// Leitura dos dados bin�rios
	fread(n, sizeof(float), 10, arquivo);
	// Impress�o do maior n�mero: 
	float maior = vetMaior(n);
	printf("Maior numero contido no arquivo \"%s\": %f", str, maior);
	
	fclose(arquivo);
	return 0;
}
