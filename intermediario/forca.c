#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavra_secreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_dados = 0;

void abertura() {
    printf("***********************\n");
    printf("*    JOGO DE FORCA    *\n");
    printf("***********************\n\n");
}

int chuta() {
    char chute;
    scanf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutes_dados] = chute;
    return chutes_dados++;
}

int ja_chutou(char letra) {
    int achou = 0;

    for(int j = 0; j < chutes_dados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenha_forca() {
    int erros = chutes_errados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %s     \n", (erros>=1?"(_)":" "));
    printf(" |      %c%c%c \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c    \n", (erros>=2?'|':' '));
    printf(" |      %s     \n", (erros>=4?"/ \\":" "));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavra_secreta); i++) {
         
        int achou = ja_chutou(palavra_secreta[i]);
        
        if(achou) {
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhe_palavra() {
    FILE* f;
    f = fopen("palavras.txt", "r");
    arquivo_disponivel(f);

    int quantidade_palavras;
    fscanf(f, "%d", &quantidade_palavras);

    srand(time(0));
    int randomico = rand() % quantidade_palavras;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavra_secreta);
    }

    fclose(f);
}

int arquivo_disponivel(FILE* f){
    if(f == 0) {
        printf("Desculpe, banco de dados indisponivel\n\n");
        exit(1);
    }
}

void adiciona_palavra() {
    char quer;
    printf("Deseja adicionar uma nova palavra no jogo? (S/N) ");
    scanf(" %c", &quer);
    if(quer == 'S') {
        char nova_palavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", &nova_palavra);
        
        FILE* f;
        f = fopen("palavras.txt", "r+");
        arquivo_disponivel(f);
        
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        // SEEK_SET posiciona o cursor no inicio do arquivo
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        // SEEK_END posiciona o cursor no final do arquivo
        fseek(f, 0, SEEK_END);
        
        fprintf(f, "\n%s", nova_palavra);

        printf("Sua palavra foi adicionada ao dicionario, Obrigado pela contribicao.\n\n");
    }
}

int chutes_errados() {
    int erros = 0;

    for (int i = 0; i < chutes_dados; i++) {
        int existe = 0;
        for(int j = 0; j < strlen(palavra_secreta); j++) {
            if(chutes[i] == palavra_secreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros;
}

int enforcou() {
    return chutes_errados() >= 5;
}

int acertou() {
    for(int i = 0; i < strlen(palavra_secreta); i++) {
        if(!ja_chutou(palavra_secreta[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {

    escolhe_palavra();

    abertura();

    do {
        desenha_forca();
        chuta();
    } while(!acertou() && !enforcou());


    if(acertou()) {
        printf("\n");
        printf("Parabens, voce ganhou\n");
        printf(" .__.\n");
        printf("(|  |)\n");
        printf(" (  )\n");
        printf(" _)(_\n\n");
    } else {
        printf("\n");
        printf("(?_^    Voce perdeu\n");
        printf(" |\\ )  e foi enforcado\n");
        printf(" |/_\\  A Palavra era **%s** \n", palavra_secreta);
    }

    adiciona_palavra();
}


