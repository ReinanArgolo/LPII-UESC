#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int x = 4;

    int* ptr = malloc(sizeof(int));
    if(ptr == NULL) { printf("Erro"); exit(-1); }

    *ptr = 10;
    printf("%d\n", *ptr);

    free(ptr);

    ptr = &x;

    printf("%d\n", *ptr);

    return 0;
}