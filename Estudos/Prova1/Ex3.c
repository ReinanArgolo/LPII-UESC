#include <stdio.h>

int main(void) {
    int vet[] = {1, 3, 5, 7, 9};


    for(int i = 0; i < 5; i++) {
        printf("%d\n", *(vet+i));
    }
}