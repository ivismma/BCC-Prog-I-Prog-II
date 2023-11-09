/*
 Implemente um programa que cumpra os seguintes requisitos:
- Crie o tipo de dado Polinomio, fixado em grau 2 (isto �, todos os polin�mios ser�o de 2o grau),
e use um vetor de tamanho 3 para guardar os coeficientes (o quadr�tico, o linear e o
independente);
- Leia do teclado os coeficientes de dois polin�mios, p1 e p2, desse tipo.
- Imprima �Verdadeiro� se, para um inteiro N = 2, � o caso que p1 = N x p2 (ou vice-versa), e
�Falso� caso contr�rio. Por exemplo:
Entrada:
p1 = {9, 12, 21}
p2 = {3, 4, 7}
Sa�da:
�Verdadeiro� pois 9x� + 12x + 21 == 3 * (3x� + 4x + 7), para N = 3.
*/

#include <stdio.h>
#define TAM 1000
#define FALSE 0
#define TRUE 1

typedef struct{
	int coef[3];
} Polinomio;


// Retorna FALSE caso n�o exista ou o inteiro N encontrado caso exista.
int verifica_p1p2(Polinomio p1, Polinomio p2){
	int N = 2;
	while(N < TAM){ // Exerc�cio n�o especifica o limite de N, ent�o ser� definido em 1000 (para n�o haver loop infinito).
		if( (p1.coef[0] + p1.coef[1] + p1.coef[2]) == (N * (p2.coef[0] + p2.coef[1] + p2.coef[2])) )
			return N;
		++N;
	} return FALSE;
}

int main(){
	int N;
	Polinomio p1, p2;
	printf("Insira os coeficientes c1,c2 e c3 polinomio p1 de grau 2, separado por espacos:\n");
	scanf("%d %d %d", &p1.coef[0], &p1.coef[1], &p1.coef[2]);
	printf("Insira os coeficientes c1,c2 e c3 polinomio p2 de grau 2, separado por espacos:\n");
	scanf("%d %d %d", &p2.coef[0], &p2.coef[1], &p2.coef[2]);
	
	N = verifica_p1p2(p1, p2);
	if(N)
		printf("Verdadeiro - Para N = %d", N);
	else // N = FALSE.
		printf("Falso");
	return 0;
}
