#include <stdio.h>

int main (void) {
    
    int* ptrA;
    
    int a = 9;
    ptrA = &a;
    *ptrA = 5;

    printf("%p\n", (void*) &a);
    printf("%p\n", &ptrA);
    printf("%d\n", a);
    printf("%p\n", (void*) ptrA);
    printf("%d\n", *ptrA);


    return 0;

}