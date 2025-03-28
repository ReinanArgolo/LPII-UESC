#include <stdio.h>
#define SIZE 5

void rrar_vtr(int* , int*);
void prt_vtr(int*);

int main(void) {
    int vetor1[SIZE] = {1, 3, 5, 7, 9};
    int vetor2[SIZE] = {2, 4, 6, 8, 10};

    prt_vtr(vetor1);
    prt_vtr(vetor2);

    rrar_vtr(vetor1, vetor2);

    printf("\n");

    prt_vtr(vetor1);
    prt_vtr(vetor2);
}

void rrar_vtr(int* v1, int* v2) {
    int temp;
    for(int i = 0; i < SIZE; i++) {
        temp = *(v2+i);
        *(v2+i) = *(v1+i);
        *(v1+i) = temp; 
    }


}

void prt_vtr(int* v) {

    for(int i = 0; i < SIZE; i++) {
        printf("%3d", *v++);
    }

    printf("\n");
}