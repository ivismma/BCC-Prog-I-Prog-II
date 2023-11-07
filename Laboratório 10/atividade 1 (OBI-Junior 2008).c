/*
Atividade 1 (baseada no problema �Vestibular� da OBI-Junior 2008):
Parte das universidades brasileiras ainda usa o vestibular para selecionar seus alunos. O
vestibular consiste de uma ou mais provas sobre as mat�rias do Ensino M�dio, visando
avaliar os conhecimentos dos candidatos. Um formato popular de prova de vestibular �
a prova objetiva. Neste formato, cada candidato deve escolher uma das cinco alternativas
apresentadas pela quest�o como sendo a correta. Durante a corre��o dos cart�es, cada
quest�o onde a alternativa escolhida pelo candidato � a mesma do gabarito, ele ganha um
ponto. Escreva um programa que, dado o gabarito e as respostas de um dos candidatos,
determina o n�mero de acertos daquele candidato.
Entrada: A entrada cont�m um �nico conjunto de testes, que deve ser lido do
dispositivo de entrada padr�o. A primeira linha da entrada cont�m um �nico inteiro N (1 <=
N <= 80), representando o n�mero de quest�es na prova. A segunda linha da entrada
cont�m uma cadeia de N caracteres, indicando o gabarito da prova. A terceira linha da
entrada cont�m outra cadeia de N caracteres, indicando as op��es marcadas pelo candidato.
Ambas as cadeias cont�m apenas os caracteres �A�, �B�, �C�, �D� e �E� (sempre em letra
mai�scula).
Sa�da: Seu programa deve imprimir na sa�da padr�o uma �nica linha contendo um
�nico inteiro, indicando o n�mero de acertos do candidato.
Obs.: Para ler as cadeias de caracteres use o formato %s
*/

#include <stdio.h>
#include <string.h>

void verificaResp(int v[], int n) // Verifica se as alternativas selecionadas est�o entre 'A' e 'E', e ao mesmo tempo, se n�o � mai�scula.
	for(int i = 0; i < n; ++i)
		if(v[i] < 'A' || v[i] 'E')
			return -1; // Retorna -1 caso n�o respeite os requisitos.

int contabilizaAcertos(char resp[], char gabarito[], int n){
    int cont = 0;
    for(int i = 0; i < n; i++)
        cont += (resp[i] == gabarito[i]);
    return cont;
} 

int main(){  
    int n, acertos;
    // "A primeira linha da entrada cont�m um �nico inteiro N (1 <= N <= 80)"
	do {scanf("%d", &n);} while(n < 1 || n > 80);
	char resp[n], gabarito[n];

	scanf("%s", gabarito);
    verificaResp(gabarito,n); 
   
    scanf("%s", resp);
    verificaResp(resp,n); 
    
	acertos = contabilizaAcertos(resp, gabarito, n);
	printf("%d", acertos);
    
    return 0;
}
