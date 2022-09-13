#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

// dou um nome pro conjunto de variáveis definidos no outro arquivo
MAPA m; // como eu já defini que é uma struct, só preciso colocar o nome
POSICAO heroi;

int acabou(){
	return 0;
}

void move(char direcao){ // recebe a variável comando e "transforma" na varivável direcao

	m.matriz[heroi.x][heroi.y] = '.'; // antes era m.matriz[x][y] = '.';

	switch(direcao){
		case 'a': // para a esquerda
			m.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;
			break;
		case 'w':
			m.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;
			break;
		case 's':
			m.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;
			break;
		case 'd':
			m.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;
			break;
	}

	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

	lemapa(&m);
	encontramapa(&m, &heroi, '@');

	do{
		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());


	liberamapa(&m);

	system("pause");
	return 0;
}
