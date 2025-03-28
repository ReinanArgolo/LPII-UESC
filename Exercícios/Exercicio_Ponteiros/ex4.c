#include <stdio.h>

int main(void) {

    int a = 5;

    printf("a = %d\n", a);
    int* ptr = &a;

    *ptr = 3;
    printf("a = %d\n", a);

}