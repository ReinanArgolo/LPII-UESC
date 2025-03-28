#include <stdio.h>

void somarVetor(int []);
int somar(int a, int b);

int main(void) {

    int vetor[2] = {12, 14};

    somarVetor(vetor);

}

void somarVetor(int vetor[]) {
 printf("Soma: %d\n", somar(vetor[0], vetor[1]));
}

int somar(int a, int b) {
    return a+b;
}
