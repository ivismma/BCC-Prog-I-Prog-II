/*
O laborat�rio da aula 13 (Arquivos pt.1) caiu em um feriado, n�o houve exerc�cios at� o momento dessa postagem
sendo assim, pratiquei os dois exemplos do PDF da Aula 13 fazendo do meu jeito.

Primeiro exemplo:
1) Escreva um programa em C que crie e inicialize tr�s vari�veis (uma
inteiro, outra double e outra cadeia de caracteres) e salve em um
arquivo texto os valores dessas vari�veis.
*/

#include <stdio.h>
#define TAM 5

int main(){
	FILE *arquivo = fopen("Info.txt", "r"); // Abre o arquivo para leitura (tentativa)
	
	if(!arquivo){ // Checa abertura do arquivo, se � NULL, houve um problema ao abrir.
		printf("N�o foi poss�vel abrir/criar o arquivo.");
		return -1;
	}
	// Se chegou at� aqui, o arquivo foi inicializado.
	int i = 0;
	
	int n; double d; char c[TAM];
	fscanf(arquivo, "%d\n%lf\n%s", &n, &d, c);
	i = 0;
	
	// Imprime
	printf("%d\n%lf\n%s", n, d, c);
	
	
	fclose(arquivo); // Fecha arquivo. 
		
	return 0;
}
