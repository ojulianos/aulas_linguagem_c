#include <stdio.h>

int main(){
    int x, y;

    // Imprime o cabeçalho
    printf("******************************\n");
    printf("* Multiplicação dois números *\n");
    printf("******************************\n");

    // Pede os valores para o usuário
    printf("Digite o primeiro número %d: ", x);
    scanf("%d", &x);

    printf("Digite o segundo número %d: ", y);
    scanf("%d", &y);

    // Mostra o resultado
    printf("Resultado: %d", (x*y) );
}
