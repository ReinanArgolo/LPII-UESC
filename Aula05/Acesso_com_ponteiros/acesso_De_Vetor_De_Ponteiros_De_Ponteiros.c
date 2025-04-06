#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int vet0[] = {10, 11, 12};
    int vet1[] = {20, 21, 22, 24};

    int* p[] = {vet0, vet1};

    printf("Vetor p: %p\n", p);
    printf("Vetor 0: %p\n", &vet0);
    printf("Vetor 1: %p\n", &vet1);


    for(int i = 0; i < 2; i++) {

        //printf("valor de *p na posição i: %p\n", *(p+i));

        int vet_size = sizeof((p+i)[i]) / sizeof(int);
        
        for(int j = 0; j < vet_size; j++) printf("%5d", *(*(p+i)+j));
    }

    printf("\n");

    return 0;
}