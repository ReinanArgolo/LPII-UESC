#include <stdio.h>

void torcar_valores(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void func_aux(int** a, int** b){
    printf("%p, %p\n", *a, *b);

    torcar_valores(a,b);

    printf("%p, %p\n", *a, *b);

    printf("a: %d, b: %d", **a, **b);
}

int main(void) {

    int a = 5, b = 10;
    int* ptr1 = &a;
    int* ptr2 = &b;

    printf("ANTES\n");
    printf("%d, %d\n", a, b);

    func_aux(ptr1, ptr2);

    printf("DEPOIS\n");
    printf("%d, %d", a, b);


}