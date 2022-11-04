#ifndef _UI_H_ // Significa que se o _UI_H_ não estiver definido, irá definir
#define _UI_H_

#include "mapa.h"

void imprimeparte(char desenho[4][7], int parte);
void imprimemapa(MAPA* m);

#endif // Sempre que eu usar ifndef, usar o endif para fechar o if