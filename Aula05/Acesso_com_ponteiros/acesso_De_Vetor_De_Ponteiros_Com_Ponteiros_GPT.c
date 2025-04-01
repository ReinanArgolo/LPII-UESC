#include <stdio.h>

typedef struct {
    int* vetor;
    int tamanho;
} Vetor;

void imprimir_vetor(Vetor v) {
    for (int i = 0; i < v.tamanho; i++) {
        printf("%5d", v.vetor[i]);
    }
    printf("\n");
}

int main(void) {
    int vet0[] = {10, 11, 12};
    int vet1[] = {20, 21, 22, 24};

    Vetor p[] = {
        {vet0, 3},  // vetor vet0 com 3 elementos
        {vet1, 4}   // vetor vet1 com 4 elementos
    };

    for (int i = 0; i < 2; i++) {
        printf("Vetor %d (tamanho %d):\n", i, p[i].tamanho);
        imprimir_vetor(p[i]);
    }

    return 0;
}
