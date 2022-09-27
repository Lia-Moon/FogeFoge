#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
int encontramapa(MAPA* m, POSICAO* p, char c);

int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);

int podeandar(MAPA* m, char personagem, int x, int y);

int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
