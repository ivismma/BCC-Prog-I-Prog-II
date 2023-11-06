/*Quest�o 6) Matematicamente, pode-se definir o M�ximo Divisor Comum (MDC) entre dois
inteiros positivos a e b como

mdc(a, b) = a , se b = 0;
= mdc(b, a%b) , caso contr�rio

Podemos assim escrever uma fun��o recursiva para o c�lculo de MDC, como segue:
int mdc(int x, int y){
if (y == 0) //caso base
return x;
return mdc(y, x % y); //chamada recursiva!
}
Ou simplesmente:
int mdc(int x, int y){
return (y == 0) ? x : mdc(y, x % y);
}
*/

#include <math.h>

// a) Implemente a vers�o recursiva da Quest�o 1 desta lista (m�todo de Newton).

int metodoDeNewtonRecursivo(double n, double xantes, double x){
	if (fabs(x - xantes < pow(10,-6)))
		return x;
	return metodoDeNewtonRecursivo(n,x, xantes - (pow(xantes,2)-n)/(2*n));
}

int main(){
	double n, res;
	printf("Digite um n�mero n racional:  ");
	scanf("%lf", &n);
	res = metodoDeNewtonRecursivo(n, 0, 10);
	printf("\nResultado: %f", res);
}
