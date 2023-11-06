/*Quest�o 8) (adaptada da OBI 2012, Fase 2, N�vel J�nior):
Jo�o deseja fazer bolos usando uma receita que indica que devem ser usadas
2 x�caras de farinha de trigo, 3 ovos e 5 colheres de sopa de leite.
Em casa ele tem A x�caras de farinha de trigo, B ovos e C colheres de sopa de leite.
Jo�o n�o tem muita pr�tica com a cozinha, e portanto ele s� se arriscar� a fazer
medidas exatas da receita de bolo (por exemplo, se ele tiver material suficiente para
fazer mais do que 2 e menos do que 3 bolos, ele far� somente 2 bolos).
Sabendo disso, escreva um programa que determine qual a quantidade m�xima de
bolos que ele consegue fazer. */

#include <stdio.h>

int menor(x,y,z){ // Retorna o menor n�mero entre tr�s.
	return (x < y && x < z)? x: (y < z)? y:z; // if utilizando Operador tern�rio.
}

int main(){
	int a, b, c, qtd; // a = x�caras de farinha | b = ovos | c = colheres de sopa de leite. | qtd = Quantidade de bolos.
	
	printf("Quantas x�caras de farinha?\n");
	scanf("%d", &a);
	printf("Quantos ovos?\n");
	scanf("%d", &b);
	printf("Quantas colheres de sopa de leite?\n");
	scanf("%d", &c);
	
	a = a/2; b = b/3;c = c/5; // a,b e c s�o, respectivamente, a quantidade de bolos que s�o poss�veis fazer com o ingrediente (individualmente).
	qtd = menor(a,b,c); // Jo�o consegue fazer a quantidade de bolos contanto que todos os ingredientes sejam suficientes --> a quantidade ser� de quantos bolos fazem o ingrediente que n�o est� sobrando para mais um bolo. <--
	printf("Jo�o consegue fazer %d bolo(s) com a quantidade de ingredientes dispon�veis.", qtd);
	
	return 0;
}
