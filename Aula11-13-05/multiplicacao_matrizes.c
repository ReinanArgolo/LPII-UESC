#include <stdio.h>
#include <stdlib.h>

void multiplicacao_de_matrizes(int**, int *, int*, int, int); 
void imprimir_matriz(int** matriz, int linhas, int colunas);
void imprimir_vetor(int* vetor, int tamanho);


int main() {
    int linhas = 3;    int colunas = 2;    int** matriz;    int i, j; int* resultado; int* vetor;

    matriz = malloc(linhas * sizeof(int*));// 1. Alocação das linhas (array de ponteiros) - sem cast explícito

    if (matriz == NULL) {
        printf("Erro: falha na alocação de memória para as linhas.\n");
        return 1;
    }


    vetor = malloc(linhas * sizeof(int));

    resultado = malloc(linhas * sizeof(int));

    for(int i = 0; i < linhas; i++) {
        int valor = 10 + rand() % (50 - 10 + 1);
        vetor[i] = valor;
    }

    for (i = 0; i < linhas; i++){    // 2. Alocação das colunas para cada linha
        matriz[i] = malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro: falha na alocação para as colunas na linha %d.\n", i);
            for (int k = 0; k < i; k++){// 3. Liberação da memória alocada anteriormente (em caso de falha)
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }


    for (i = 0; i < linhas; i++) {    // 4. Inicialização opcional da matriz (exemplo)
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 10 + rand() % (50 - 10 + 1); // ou outro valor
        }
    }

    printf("Matriz: \n");
    imprimir_matriz(matriz, linhas, colunas);

    multiplicacao_de_matrizes(matriz, vetor, resultado, linhas, colunas);

    printf("vetor: \n");
    imprimir_vetor(vetor, linhas);

    printf("resultado: \n");

    imprimir_vetor(resultado, linhas);
    


    free(vetor);
    free(resultado);


    for (i = 0; i < linhas; i++) {    // 5. Liberação correta da memória ao final (boas práticas)
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL; // Previne "dangling pointers"
    return 0;
}

void multiplicacao_de_matrizes(int** matriz, int* vetor, int* resultado, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        int acum = 0;
        for (int j = 0; j < colunas; j++) {
            acum += matriz[i][j] * vetor[j];
        }
        resultado[i] = acum;
    }
}

void imprimir_matriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimir_vetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
