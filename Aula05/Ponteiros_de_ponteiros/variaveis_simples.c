#include <stdio.h>
#include <stdlib.h>

int* changePointer(int* p);

int main(void) {
    int a = 5, c = 4;

    int* ptr = NULL;
    ptr = &a;

    printf("end: %p, armz: %p contd %d\n", &ptr, ptr, *ptr);

    /* ptr = &c;
    printf("end: %p, armz: %p contd %d\n", &ptr, ptr, *ptr); */

    printf("MUDANDO\n");
    ptr = changePointer(ptr); // existe um erro pois a variavel deixa de existir
    printf("end: %p, armz: %p contd %d\n", &ptr, ptr, *ptr); 


}

int* changePointer(int* p) {
    int y = 17;
    printf("endY: %p\n", &y);
    p = &y;
    return p;
}
