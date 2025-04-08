#include <stdio.h>

void minha_func() {
    static int a = 0;
    a++;  
    printf("%d\n", a);
    minha_func();
}

int main(void) {
    minha_func();
}