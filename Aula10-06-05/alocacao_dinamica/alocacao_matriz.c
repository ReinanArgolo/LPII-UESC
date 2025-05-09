#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int l, c;

    printf("Digite a quantidade de linhas do vetor: ");
    scanf(" %d", &l);

    printf("Digite a quantidade de colunas do vetor: ");
    scanf(" %d", &c);

    int** matriz = malloc(l * sizeof(int*));
    if(matriz == NULL) {printf("erro."); exit(-1);}

    for(int i = 0; i < l; i++) {
        matriz[i] = malloc(c * sizeof(int));
        if(matriz[i] == NULL) {
            printf("erro."); exit(-1);
            for(int j = i; j < 0; j--) free(matriz[i]);
            free(matriz);
        }
    }

    for (int i = 0; i < l; i++) for(int j = 0; j < c; j++) matriz[i][j]=j;
    for (int i = 0; i < l; i++) { for(int j = 0; j < c; j++) {printf(" %d", matriz[i][j]); } printf("\n");}

    printf("%d", matriz[0][0]);

    for(int i = 0; i < l; i++) {
       free(matriz[i]);
    }

    free(matriz);


    return 0; 
}