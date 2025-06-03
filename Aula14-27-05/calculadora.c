#include <stdio.h>

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);


int main(void) {

    float a, b, result;
    printf("Digite um número: \n");
    scanf("%f", &a);
     printf("Digite um número: \n");
    scanf("%f", &b);
    printf("(1) SOMAR\n(2) SUBTRAIR\n(3)MULTIPLICAR\n(4)DIVIDIR\n");

    int opc;
    scanf("%d", &opc);

    switch (opc) {
        case 1:
            result = somar(a, b);
            break;
        case 2:
            result = subtrair(a, b);
            break;
        case 3:
            result = multiplicar(a, b);
            break;
        case 4:
            result = dividir(a, b);
            break;
        
        default:
            printf("Opção não encontrada!");
            break;
    }

    printf("%f\n", result);
}

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if(b <= 0) {
        printf("Divisão por zero!");
        return 0;
    }

    return a / b;
}