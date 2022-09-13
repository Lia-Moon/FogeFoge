struct mapa { // declarei uma estrutura de variáveis
	// matriz de 5 x 10, linhas x colunas
	// char mapa[5][10+1]; // o +1 serve para indicar o /0 que é o fim da matriz
	char** matriz; // ** é um ponteiro de um ponteiro
	int linhas;
	int colunas;
}; // lembrar de terminar com ';'

typedef struct mapa MAPA; // typedef permite não precisar ficar usando a palavra struct, como se fosse um apelido pra struct

struct posicao {
	int x;
	int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO* p, char c);
