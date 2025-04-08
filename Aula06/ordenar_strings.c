#define NOME_MAX 60
#define TAM_MAX 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para ordenar a lista de nomes
void ordena(char **p, int n) {
    char *temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(p[i], p[j]) > 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(void) {
    char nomes[NOME_MAX][TAM_MAX];  // Matriz para armazenar os nomes
    char *p[30];  // Vetor de ponteiros para os nomes
    int n = 0, i;

    // Limpa a tela (funciona em sistemas UNIX)
    system("clear");

    // Loop para digitar os nomes
    while (1) {
        printf("Digite nome ou [ENTER] para fim: ");
        if (fgets(nomes[n], TAM_MAX, stdin) == NULL) {
            break;
        }
        nomes[n][strcspn(nomes[n], "\n")] = '\0';  // remove newline

        // Se o nome for vazio (apenas pressionou ENTER), sai do loop
        if (nomes[n][0] == '\0') {
            break;
        }

        // Atribui o endereço do nome para o vetor de ponteiros
        p[n] = nomes[n];
        n++;  // Incrementa o contador de nomes

        // Limpa a tela para mostrar a lista atual
        system("clear");

        // Imprime a lista original
        printf("\n\nLista original:\n");
        for (i = 0; i < n; i++) {
            printf("%s\n", p[i]);
        }
    }

    system("clear");

    printf("\n\nLista original:\n");
        for (i = 0; i < n; i++) {
            printf("%s\n", p[i]);
        }

    // Ordena a lista de ponteiros
    ordena(p, n);

    // Imprime a lista ordenada
    printf("\nLista ordenada:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", p[i]);
    }

    return 0;
}
