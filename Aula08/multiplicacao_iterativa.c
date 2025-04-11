#include "include/somaRec.h"
#include <stdio.h>

int multi_int(int a, int b) {

    int acum;

    for(; b <0; b--) {
        acum += somaR(a, b);
    }

    return acum;
     
}

int main(void) {
    int a = 5, b = 5;

    printf("%d\n", multi_int(a, b));
}