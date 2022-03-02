#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void le_mapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));    
    aloca_mapa(m );

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void aloca_mapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for (int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void copia_mapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    aloca_mapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void libera_mapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}


int encontra_mapa(MAPA* m, POSICAO* p, char c) {
    for(int i = 0; i < m->linhas; i++) {
        for(int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

int podeandar(MAPA* m, char personagem, int x, int y) {
    return ehvalida(m, x, y) && !ehparede(m, x, y) && !ehpersonagem(m, personagem, x, y);
}

int ehvalida(MAPA* m, int x, int y) {
    if(x >= m->linhas) return 0;
    if(y >= m->colunas) return 0;
    return 1;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y) {
    return m->matriz[x][y] == personagem;
}

int ehparede(MAPA* m, int x, int y) {
    return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

void andanomapa(MAPA* m, int origem_x, int origem_y, int destino_x, int destino_y) {
    char personagem = m->matriz[origem_x][origem_y];
    m->matriz[destino_x][destino_y] = personagem;
    m->matriz[origem_x][origem_y] = VAZIO;
}

