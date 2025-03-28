#include <stdio.h>

#define SIZE 5

void somarVetores(int*, int*, int*);
void prt_vtr(int* v);

int main(void) {
    int v1[SIZE] = {1,3,5,7,9};
    int v2[SIZE] = {2,4,6,8,10};

    prt_vtr(v1);
    prt_vtr(v2);

    int somaDosVets[5] = {};

    somarVetores(v1, v2, somaDosVets);
    prt_vtr(somaDosVets);


}

void somarVetores(int* v1, int* v2, int* vr) {
    for(int i =0; i< SIZE; i++) {
        *(vr+i) = *(v1+i) + *(v2+i);
    }
}

void prt_vtr(int* v) {

    for(int i = 0; i < SIZE; i++) {
        printf("%3d", *v++);
    }

    printf("\n");
}