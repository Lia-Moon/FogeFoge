#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontramapa(MAPA* m, POSICAO* p, char c){
	// acha a localização do pac man
	for(int i=0; i<m->linhas; i++){
		for(int j=0; j<m->colunas; j++){
			if(m->matriz[i][j] == c){
				p->x = i;
				p->y = j;
				break;
			}
		}
	}
}

void liberamapa(MAPA* m){
	for (int i=0; i < m->linhas; i++){ // m.linhas estou chamando a struct m, em linhas 
	// m->linhas o m é um ponteiro, quer acessar linhas da struct
	// m->linhas é equivalente a (*m).linhas
		free(m->matriz[i]); // liberar a memória de cada uma das linhas
	}
	free(m->matriz); // liberar a memoria de mapa
}

void alocamapa(MAPA* m){
	// malloc (alocação de memória), sizeof (devolve o tamanho em bytes de um tipo espeficiado, ex: char), vezes linhas
	m->matriz = malloc(sizeof(char*) * m->linhas);
	// para cada linha iremos alocar memória para caber os chars
	for (int i=0; i < m->linhas; i++){
		m->matriz[i] = malloc(sizeof(char) * (m->colunas+1)); // +1 é referente ao /0 , e alocamos as colunas
	}
}

void lemapa(MAPA* m){
	FILE* f;

	f = fopen("mapa.txt", "r");

	if(f == 0){
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

	alocamapa(m);

	for(int i=0; i<5; i++){
		fscanf(f, "%s", m->matriz[i]); // mapa[i] devolve um array, estou passando a linha inteira, por isso utilizo o %s para pegar toda a string
	}

	fclose(f);
}

void imprimemapa(MAPA* m){
	for(int i=0; i<5; i++){
		printf("%s\n", m->matriz[i]);
	}
}
