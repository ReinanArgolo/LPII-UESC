#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int var = 17;

    int* ptr1 = NULL; int** ptr2 = NULL;

    ptr1 = &var;

    ptr2 = &ptr1;

    printf("Endereço VAR: %p\n", &var);
    printf("Conteudo VAR: %d\n", var);
    printf("Endreco que ptr1 aponta: %p\n", ptr1);
    printf("Endereço ptr1: %p\n", &ptr1);
    printf("Conteudo de quem PTR1 aponta: %d\n", *ptr1);
    printf("Endreco que ptr1 aponta: %p\n", ptr2);
    printf("Endereço ptr1: %p\n", &ptr2);
    printf("Conteudp ptr1: %p\n", *ptr2);
    
    return 0;

}