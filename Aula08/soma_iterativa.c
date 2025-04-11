// entrada: a e b, b>= 0 
//a) SomaI, função iterativa que retorna A + B;

#include <stdio.h>

int SomaI(int a, int b) {
    if(b<=0) return a;
    for(; b > 0; b--) {
        a++;
    }
    return a;

}

int main(void) {
    int a = 58, b = 5;

    printf("%d\n", SomaI(a, b));
}