#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Imprime o cabeçalho do jogo
    printf("\n\n");
    printf("                \\||/\n");
    printf("                |  @___oo\n");
    printf("      /\\  /\\   / (__,,,,|\n");
    printf("     ) /^\\) ^\\/ _)          BEM VINDO\n");
    printf("     )   /^\\/   _)           AO JOGO DE\n");
    printf("     )   _ /  / _)            ADVINHACAO\n");
    printf(" /\\  )/\\/ ||  | )_)\n");
    printf("<  >      |(,,) )__)\n");
    printf(" ||      /    \\)___)\\ \n");
    printf(" | \\____(      )___) )___\n");
    printf("  \\______(_______;;; __;;;\n");
    printf("\n\n");

    /*
    Para o programa conseguir gerar numeros aleatórios é necessário passar 
    uma semente (seed) para a função rand com o método srand, para isso foi utilizada
    a biblioteca time pegando o EPOCH e adicionando como semente no programa
    Depois foi calculado o resto da divisao por 100 para retornar apenas numeros com até
    2 caracteres como numero secreto
    */
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numeroSecreto = numerogrande % 100;


    int tentativas = 1;
    int chute;
    double pontos = 1000;

    int acertou = 0;

    int NUMERO_TENTATIVAS;
    int nivel = 0;
    printf("Qual o nivel de dificuldade ? \n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel) {
        case 2:
            NUMERO_TENTATIVAS = 15;
            break;
        case 3:
            NUMERO_TENTATIVAS = 6;
            break;
        default:
            NUMERO_TENTATIVAS = 20;
            break;
    }

    for(int i = 1; i <= NUMERO_TENTATIVAS; i++) {
        printf("Qual eh o seu chute ? ");
        scanf("%d", &chute);
        if(chute < 0) {
            printf("Voce nao pode enviar numeros menores que zero \n");
            continue;
        }

        printf("Seu chute foi %d, Tentativas: %d \n", chute, tentativas);

        acertou = (numeroSecreto == chute);
        int maior = (numeroSecreto > chute);

        if (acertou) {
            break;
        } else if (maior) {
            printf("O numero secreto eh maior.\n");
        } else {
            printf("O numero secreto eh menor.\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numeroSecreto) / (double) 2;
        pontos = pontos - pontosperdidos;
    }

    if(acertou) {
        printf("Fim de Jogo!\n");
        printf(" \n");
        printf("    .'     '.   \n");
        printf("   /  o   o  \\  \n");
        printf("  |           | \n");
        printf("  |  \\     /  | \n");
        printf("   \\  '---'  /  \n");
        printf("    '._____.'   \n\n");
        printf("Voce ganhou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f \n", pontos);
    } else {
        printf("Voce perdeu! Tente novamente.\n");
        printf("             *******\n");
        printf("           ***********\n");
        printf("          *****   *****\n");
        printf("         ***         ***\n");
        printf("        ***           ***\n");
        printf("        **    0   0    **\n");
        printf("        **             **                  ____\n");
        printf("        ***           ***             //////////\n");
        printf("        ****         ****        ///////////////  \n");
        printf("        *****       *****    ///////////////////\n");
        printf("        ******     ******/////////         |  |\n");
        printf("      *********   ****//////               |  |\n");
        printf("   ************* **/////*****              |  |\n");
        printf("  ****************///***********          *|  |*\n");
        printf(" **********************************    ****| <=>*\n");
        printf("*******************************************|<===>* \n");
        printf("*******************************************| <==>*\n");
        printf("*************************** ***************| <=>*\n");
        printf("***************************** *************|  |*\n");
        printf("******************************** **********|  |*  Matthew Kott  \n");
        printf("********************************* *********|  |\n");
    }
}
 
