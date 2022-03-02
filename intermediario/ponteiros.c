#include <stdio.h>


void calcula(int* c){
    (*c)++;
}

int main(){
    int c = 10;
    
    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);
}
