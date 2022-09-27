#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

// dou um nome pro conjunto de variáveis definidos no outro arquivo
MAPA m; // como eu já defini que é uma struct, só preciso colocar o nome
POSICAO heroi;

int praondeofantasmavai(int xatual, int yatual, int* xdestino, int* ydestino){
	int opcoes[4][2] = {
		{ xatual, yatual+1},
		{ xatual+1, yatual},
		{ xatual, yatual-1},
		{ xatual-1, yatual}
	};

	srand(time(0));
	for(int i=0; i<10; i++){
		int posicao = rand() % 4;

		if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];

			return 1;
		}
	}

}

void fantasmas(){
	MAPA copia;

	copiamapa(&copia, &m);

	for(int i=0; i < m.linhas; i++){
		for(int j=0; j < m.colunas; j++){

			if(copia.matriz[i][j] == FANTASMA){
				int xdestino;
				int ydestino;

				int encontrou = praondeofantasmavai(i, j, &xdestino, &ydestino);

				if(encontrou) {
					andanomapa(&m, i, j, xdestino, ydestino);
				}
			}
		}
	}

	liberamapa(&copia);
}

int acabou(){
	POSICAO pos;

	int fogefogenomapa = encontramapa(&m, &pos, HEROI);
	return !fogefogenomapa; // Se o fogefoge não está no mapa, o jogo acabou
}

int ehdirecao(char direcao){
	return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
	// booleano, se a condição for verdadeira retorna 1, se for falta retorna 0
	// antes era: direcao != 'a' && direcao != 'w' && direcao != 's' && direcao != 'd'
}

void move(char direcao){ // recebe a variável comando e "transforma" na varivável direcao

	if(!ehdirecao(direcao)){
		printf("******* Por favor, utilize as teclas w, a, s, d para mover o personagem! *******\n");
		return;
	}

	// m.matriz[heroi.x][heroi.y] = '.'; // antes era m.matriz[x][y] = '.';


	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch(direcao){
		case ESQUERDA: // para a esquerda
			//m.matriz[heroi.x][heroi.y-1] = '@';
			//heroi.y--;
			proximoy--;
			break;
		case CIMA:
			proximox--;
			break;
		case BAIXO:
			proximox++;
			break;
		case DIREITA:
			proximoy++;
			break;
	}

	if(!podeandar(&m, HEROI, proximox, proximoy))
		return;

	if(m.matriz[proximox][proximoy] != '.')
		return;

	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);

	do{
		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);
		fantasmas();

	} while(!acabou());


	liberamapa(&m);

	system("pause");
	return 0;
}
