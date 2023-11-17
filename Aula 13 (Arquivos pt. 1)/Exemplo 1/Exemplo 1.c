/*
O laborat�rio da aula 13 (Arquivos pt.1) caiu em um feriado, n�o houve exerc�cios at� o momento dessa postagem
sendo assim, pratiquei os dois exemplos do PDF da Aula 13 fazendo do meu jeito.

Primeiro exemplo:
1) Escreva um programa em C que crie e inicialize tr�s vari�veis (uma
inteiro, outra double e outra cadeia de caracteres) e salve em um
arquivo texto os valores dessas vari�veis.
*/

#include <stdio.h>
#define TAM 4

int main(){
	int n = 2023;
	double d = 3.14159265359; // Pi
	char c[TAM] = {'I','v','i','s'};
	FILE *arquivo = fopen("Info.txt", "w"); // Abre o arquivo (tentativa)
	
	if(!arquivo){ // Checa abertura do arquivo, se � NULL, houve um problema ao abrir.
		printf("N�o foi poss�vel abrir/criar o arquivo.");
		return -1;
	}
	// Se chegou at� aqui, o arquivo foi inicializado.
	int i = 0;
	
	fprintf(arquivo, "%d\n", n);
	fprintf(arquivo, "%f\n", d);
	while(i < TAM) fprintf(arquivo, "%c", c[i++]);
	fclose(arquivo); // Fecha arquivo. 
		
	return 0;
}
