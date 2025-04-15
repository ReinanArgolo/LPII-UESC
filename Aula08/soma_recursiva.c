// entrada: a e b, b>= 0 
//a) SomaI, função iterativa que retorna A + B;


#include "somaRec.h"

int somaR(int a, int b) {
    if(a == 0) return 1;
    if(b == 0) return a;

    return (somaR(++a, --b));
    

    
}

// int main(void) {
//     int a = 58, b = 5;

//     printf("%d\n", somaR(a, b));
// }