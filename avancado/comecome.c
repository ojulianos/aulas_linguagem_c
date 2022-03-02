#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "pacman.h"
#include "mapa.h"
#include "ui.h"


MAPA m;
POSICAO heroi;
int tempilula = 0;

int acabou() {
    POSICAO pos;
    int perdeu = !encontra_mapa(&m, &pos, HEROI);
    int ganhou = !encontra_mapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;
}

int ehdirecao(char direcao) {
    return
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == ESQUERDA || 
        direcao == DIREITA;
}

void move(char direcao) {

    if(!ehdirecao(direcao)) return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao) {
        case CIMA: proximox--; break;
        case BAIXO: proximox++; break;
        case DIREITA: proximoy++; break;
        case ESQUERDA: proximoy--; break;
    }

    if(!podeandar(&m, HEROI, proximox, proximoy)) return;

    if(ehpersonagem(&m, PILULA, proximox, proximoy)) {
        tempilula = 1;
    }

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int direcaodofantasta(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
        { xatual, yatual +1 },
        { xatual +1, yatual },
        { xatual, yatual -1 },
        { xatual -1, yatual },
    };

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;
        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
    
}

void fantasmas() {
    MAPA copia;

    copia_mapa(&copia,& m);

    for(int i = 0; i< m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            
            if(copia.matriz[i][j] == FANTASMA) {
                int xdestino;
                int ydestino;
                int encontrou = direcaodofantasta(i, j, &xdestino, &ydestino);

                if(encontrou){
                    andanomapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    libera_mapa(&copia);
}

void explode_pilula() {
    if(!tempilula) return;

    explode_pilula2(heroi.x, heroi.y, 0, 1, 3);
    explode_pilula2(heroi.x, heroi.y, 0, -1, 3);
    explode_pilula2(heroi.x, heroi.y, 1, 0, 3);
    explode_pilula2(heroi.x, heroi.y, -1, 0, 3);

    tempilula = 0;
}

void explode_pilula2(int x, int y, int somax, int somay, int qtd) {

    if(qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;

    if(ehvalida(&m, novox, novoy)) return;
    if(ehparede(&m, novox, novoy)) return;
    
    m.matriz[novox][novoy] = VAZIO;
    explode_pilula2(novox, novoy, somax, somay, qtd -1);
}

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int main() {
    le_mapa(&m);

    encontra_mapa(&m, &heroi, HEROI);

    do {
        clear();

        printf("Tem pilula: %s\n", (tempilula ? "SIM": "NAO"));

        imprime_mapa(&m);

        char comando;
        scanf(" %c",&comando);
            
        move(comando);

        if(comando == BOMBA) explode_pilula();

        fantasmas();

    }while(!acabou());

    libera_mapa(&m);
}