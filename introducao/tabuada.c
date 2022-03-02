#include <stdio.h>


int main(){

    // Imprime o cabeçalho do jogo
    printf("**********************\n");
    printf("* Gerador de Tabuada *\n");
    printf("**********************\n");

    int numeroTabuada;
    int resultado;
    printf("Qual tabuada voce deseja ? \n");
    scanf("%d", &numeroTabuada);

    for (int i = 1; i <= 10; i++)
    {
        resultado = numeroTabuada * i;
        printf("%d x %d = %d \n", numeroTabuada, i, resultado);
    }

    printf("Fim!\n");
}
 