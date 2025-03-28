#include <stdio.h>
#define TAMFRASE 50

void imprimirLetras(char[]);

int main(void) {
    char frase[TAMFRASE];

    printf("Digite a frase:");

    scanf("%[^\n]s", frase);

    imprimirLetras(frase);
    inverterVetor(frase);

    
}

void imprimirLetras(char letras[]) {
    for(int i = 0; letras[i] != '\0'; i++) printf("%c\n", letras[i]);
}

void inverterVetor(char letras[]) {
    int length = 0;

    for(int i = 0; letras[i] != '\0'; i++) {
        length++;
    }

    for (int i = length; i > 0; i++)
    {
        printf("%c", letras[i]);
    }
    printf("\n");
    
}