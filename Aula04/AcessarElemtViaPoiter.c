#include <stdio.h>

int main(void) {
    int vet[5] = {10, 11, 9, 8, 12};

    int *ptr = vet;

    for(int i = 0; i < 5; i++) {
        printf("%d\n", ++*ptr);
    }
}