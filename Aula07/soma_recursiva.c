#include <stdio.h>

int soma(int x) {
    if(x == 0) return 0;
    else return x + soma(x-1);
}

int main(void) {
    printf("%d\n", soma(5));

}