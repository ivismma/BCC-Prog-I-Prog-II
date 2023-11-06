/*Quest�o 3) Agora sim, modifique o exerc�cio anterior como segue: crie uma fun��o chamada
arvore e que possui a seguinte assinatura:
void arvore(int linhas, int invertida);

Esta fun��o, ao ser chamada, dever� imprimir uma imagem como a do exerc�cio anterior, para o
total de linhas fornecido. Aqui, por�m, h� duas possibilidades de impress�o:
a) Caso o par�metro invertida seja igual a 0 (isto �, falso), imprimir como no exerc�cio
anterior.
b) Caso contr�rio, imprimir a imagem �de cabe�a para baixo�.

Descri��o: Algoritmo que recebe um valor n e um formato, cria uma pir�mide de asteriscos com n linhas de acordo com o formato fornecido.
Entrada: Valor n (Quantidade de linhas da pir�mide) e o formato da pir�mide.
Sa�da: A pir�mide em formato de asteriscos.
Defesa: Valor n deve ser um n�mero do intervalo [1,10].
*/

#include <stdio.h>

void arvore(int linhas, int invertida);
int lerInt(char s[40]);

int main(){
	int n, formato;
	do{ // DEFESA
		n = lerInt("Digite um valor n entre 1 e 10: ");
	} while(n < 1 || n > 10);
	formato = lerInt("Digite 0 para obter uma pir�mide invertida ou qualquer outro valor para uma pir�mide normal: ");
	printf("\n");
	arvore(n,formato);
	return 0;
}

int lerInt(char s[40]){
	int x;
	printf("%s", s); scanf("%d",&x);
	return x;
}

void arvore(int linhas, int invertida){
	int q = linhas, j=0, k=0; // q recebe a quantidade de linhas.
	if(!invertida){ // Caso (a):
		for(int i=0; i < linhas; i++, j = 0, k = 0, q -= 1){
			while(j < q){ // Quantidade de espa�os inseridos at� a coloca��o dos asteriscos.
				printf(" ");
				++j;
			}
			while (k < 1+2*i){ // Quantidade de asteriscos que ser�o colocados na itera��o atual.
				printf("*");
				++k;
			}
			printf("\n"); // Pula uma linha para pr�xima itera��o de asteriscos.
			 // A cada passo, (i++, j=0, k = 0, q-=1), Nesse �ltimo, subtrai 1 do q.
		} return;
	}
	// Caso (b):
	int cont = 0;
	for(int i=linhas; i > 0; i--, j = 0, k = 0, q = 1+i*2, cont++){
		q = -1+i*2;
		while(k < cont){
			printf(" ");
			++k;
		}
		while(j < q){
			printf("*");
			++j;
		}
		printf("\n");
	}
}


