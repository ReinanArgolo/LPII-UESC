#include <stdio.h>

void imprimirQuadrado(int n);
void imprimirQuadradoVazado(int n);
void imprimirTriangulo(int n);

void imprimirNMaisUm(int n);

int main(void) {
    printf("Exercicio 1\n");
    int n;
    printf("Digite um numero");
    scanf("%d", &n);

    imprimirQuadrado(n);
    printf("\n");
    imprimirQuadradoVazado(n);
    printf("\n");
    imprimirTriangulo(n);
    printf("\n");

    imprimirNMaisUm(n);
}

void imprimirQuadrado(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void imprimirQuadradoVazado(int n) {
    for(int i=0; i<n; i++) {
        printf("* ");
    }
    printf("\n");
    for (int i = 0; i < n-2; i++) {
        printf("* ");
        for(int j = 0; j < n-2; j++) {
            printf("  ");
        }
        printf("*\n");
    }
     for(int i=0; i<n; i++) {
        printf("* ");
    }
    printf("\n");
}

void imprimirTriangulo(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirNMaisUm(int n) {
    int i;
    for(i=n; i<n+2; i++) {
        imprimirQuadrado(i);
        printf("\n");
        imprimirQuadradoVazado(i);
        printf("\n");
        imprimirTriangulo(i);
        printf("\n");
    }
}