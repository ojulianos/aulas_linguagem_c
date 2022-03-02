#ifndef _MAPA_H_
#define _MAPA_H_


#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void aloca_mapa(MAPA* m);
void le_mapa(MAPA* m);
void libera_mapa(MAPA* m);

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

int encontra_mapa(MAPA* m, POSICAO* p, char c);

int ehvalida(MAPA* m, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);

void andanomapa(MAPA* m, int origem_x, int origem_y, int destino_x, int destino_y);

void copia_mapa(MAPA* destino, MAPA* origem);

int podeandar(MAPA* m, char personagem, int x, int y);

#endif