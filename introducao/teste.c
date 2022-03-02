#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int a = 2;
    int b = 3;
    // double pontos = a / (double) b;
    // printf("%f \n", pontos);


    a = abs(3);
    b = abs(-3);
    printf("%d %d \n", a, b);

    int segundos = time(0);
    srand(segundos);
    int n1 = rand();
    int n2 = rand();
    printf("%d %d \n", n1, n2);


}

