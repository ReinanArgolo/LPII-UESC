// #include "soma_recursiva"
#include <stdio.h>

int multi_rec(int a, int b) {

    if(a == 0 || b == 0) return 0;

    return (a + multi_rec(a, --b));
     
}

int main(void) {
    int a = 59, b = 2;

    printf("%d\n", multi_rec(a, b));
}