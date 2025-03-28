#include <stdio.h>

void inverterVariaveis(int *, int *);

int main(void) {
    int a = 1, b = 2;

    printf("a: %d\n", a);
    printf("b: %d\n", b);

    inverterVariaveis(&a, &b);

    printf("----\n");

    printf("a: %d\n", a);
    printf("b: %d\n", b);

}

void inverterVariaveis(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}