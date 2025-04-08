// Usar ponteiros de ponteiros para mudar o valor de uma aiavel atraves de função

#include <stdio.h>
#include <stdlib.h>

void trocaraiavel(int **p) {
   int nova = 42;
    *p = &nova;
}

int main(void) {
    int a = 10;
    int *pa = &a;
    printf("Valor original: %d\n", *pa);
    printf("Valor original: %p\n", pa);

    
    trocaraiavel(&pa);
    
    printf("Valor modificado: %d\n", *pa);
    printf("Valor original: %p\n", pa);
    return 0;
}