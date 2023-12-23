#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Quest�o muito interessante e bem completa. (5a 5b - P2 antiga 2023.1.pdf)

// Fazendo quest�o 5 de Prova antiga por�m c/ ponteiros.
/*  Anota��es:
- Uma carta vale, em pontos, exatamente o seu n�mero se o seu naipe n�o for copas.
- Cartas de copas valem duas vezes o seu n�mero.
- N�o pode ser inserida na mesa carta cujo a pontua��o j� foi pontuada por outro jogador.
*/

// Defesas para inser��o de valores n�o criada por exerc�cio ser longo, inserir valores v�lidos.

typedef struct {
	char naipe; //'o','e','c' ou 'p'(ouros, espadas, copas ou paus, respec.).
	int numero; //N�mero da carta, entre 2 e 10.
	char jogador[100]; //Nome do jogador que a revelou;
} Carta;

void statusRodada(Carta* reveladas, int N);
void ordenaStruct(Carta* carta, int tam); // Bubble
void exibeVetor(Carta* carta, int tam);
int cartaPontos(Carta* carta);
bool checaCartas(Carta* carta, int tam, int pontos);
// bool addVetor(int *v, int tam, Carta carta);
// possivel(jaReveladas[], int t) <-- Fun��o que o item b) pede.

int main(void){
	int n;
	printf("Digite quantidade de jogadores: ");
	scanf("%d", &n); getchar();
	Carta* reveladas = (Carta*) calloc(n, sizeof(Carta));
	// Leitura dos jogadores
	for(int i = 0; i < n;++i){
		bool ok; // FLAG - Se pontua��o inserida for repetida, ser� falsa e continuar� loop.
		printf("Jogador %d:\n", i+1);
		printf("Nome: "); scanf("%99[^\n]", reveladas[i].jogador);
		getchar();
		do{ // Enquanto inserir pontua��o j� pontuada antes, inserir outra carta.
			ok = true;
			printf("Naipe: "); scanf(" %c", &reveladas[i].naipe);
			printf("Numero: "); scanf("%d", &reveladas[i].numero);
			int pontos = cartaPontos(&reveladas[i]);
			if(!checaCartas(reveladas, i, pontos)){
				ok = false;
				printf("Pontuacao ja inserida, insira outra carta:\n");
			}
			getchar();
		} while(!ok);
		printf("---------------------\n");
	}
	// Ordena��o dos jogadores em ordem de pontua��o e vencedor.
	ordenaStruct(reveladas, n);
	statusRodada(reveladas, n);
	
	free(reveladas);
	return 0;
}

int cartaPontos(Carta* carta){ // Retorna quantos pontos o jogador fez com naipe e n� de sua carta.
	if(carta->naipe == 'c') // Copas = 2x Pontos
		return 2*carta->numero;
	return carta->numero;
}

bool checaCartas(Carta* p, int tam, int pontos){ // Parecido com a fun��o q item (b) pede.
	for(int i = 0; i < tam;++i)
		if(cartaPontos(&p[i]) == pontos) return false;
	return true;
}

void statusRodada(Carta* reveladas, int N){ // Mostra resultado final da rodada e o vencedor.
	int maior = cartaPontos(&reveladas[0]),
	i_pessoa, soma;
	
	for(int i = 1; i < N;++i) // Loop p/ descobrir maior carta e quem a possui.
		if(cartaPontos(&reveladas[i]) > maior){
			maior = cartaPontos(&reveladas[i]);
			i_pessoa = i; // Armazena indice da pessoa que possui maior pontua��o.
		}
	for(int i = N-1; i >= 0;--i){ // Exibi��o dos jogadores em ordem decrescente de pontua��o
		int pts = cartaPontos(&reveladas[i]);
		printf("Jogador %s: %d pontos.\n", reveladas[i].jogador, pts);
	}
	for(int i = 0; i < N;++i) // Exibi��o do vencedor e quanto pontuou.
		soma += cartaPontos(&reveladas[i]);
	printf("O jogador %s ganhou a rodada e levou da mesa o total de %d pontos.", 
	reveladas[i_pessoa].jogador, soma);
}
// Ordena��o cresc. de struct com base na pontua��o das cartas dos jogadores.
void ordenaStruct(Carta* p, int tam){
	bool ordenado = false;
	int fim = tam-1;
	while(!ordenado){
		ordenado = true;
		for(int i = 0; i <fim;++i){
			if(cartaPontos(&p[i]) > cartaPontos(&p[i+1])){ 
				Carta aux = p[i];
				p[i] = p[i+1];
				p[i+1] = aux;
				ordenado = false;
			}
		}
		--fim;
	}
}
// Fun��o do item (b) Obs: N�o utilizei.
int possivel(Carta intencao, Carta reveladas[], int t){
	int i = 0, pontos = cartaPontos(&intencao);
	while(i < t)  // Se encontrou pontua��o igual j� revelada, n�o � poss�vel.
		if(cartaPontos(&reveladas[i++]) == pontos) return 0;
	return 1;
}

// Outra maneira de salvar pontua��es j� reveladas (criar vetor a parte).
/*bool addVetor(int *v, int tam, Carta carta){
	static int cont = 0;
	for(int i = 0; i < cont;++i)
		if(v[cont] == carta->numero)
			return false; // Pontua��o equivalente j� revelada.
	*(v+cont++) = carta.numero;
	return true;
}*/
