#include <stdio.h>
#include "somas.h"

void somar1(void);
void somar2(int, int);
int somar3(void);

int main() {
    int a = 5, b = 7;

    somar1();
    somar2(a, b);
    int result_func_3 = somar3();
    printf("Soma 3: %d\n", result_func_3);
    int result_func_4 = somar4(a, b);
    printf("Soma 4: %d\n", result_func_4);

}

void somar1(void) {
    int a, b, c;

    a = 5;
    b = 5;

    c = a+b;

    printf("Soma 1: %d\n", c);
}

void somar2(int a, int b) {
    int c = a+b;

    printf("Soma 2: %d\n", c);
}

int somar3(void) {
    int a, b;

    a = 3; b = 4;

    return a+b;
}

int somar4(int a, int b) {
    return a+b;
}
