#include <stdio.h>
#include <stdlib.h>


int main() {

    // iteração de matrizes
    int numeros[20][10];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++) {
            printf("%d ", numeros[i][j]);
        }
        printf("\n");
    }

    // alocação de matrizes
    int linhas = 5;
    int colunas = 10;
    int matriz = malloc(sizeof(int*) * linhas);

    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(int) * (colunas + 1));
    }
}