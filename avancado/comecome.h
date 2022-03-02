#ifndef _PACMAN_H_
#define _PACMAN_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();
void move(char direcao);

int ehdirecao(char direcao);
void fantasmas();
void explode_pilula();
void explode_pilula2(int x, int y, int somax, int somay, int qtd);
void clear();

#endif