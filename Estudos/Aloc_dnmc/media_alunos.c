#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    float *notas;
    int qtd_notas;
    float media;
} Aluno;

void cadastrar_alunos(Aluno *alunos, int qtd_alunos) {
    for (int i = 0; i < qtd_alunos; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", alunos[i].nome);

        printf("Quantas notas para %s? ", alunos[i].nome);
        scanf("%d", &alunos[i].qtd_notas);

        alunos[i].notas = (float *)malloc(alunos[i].qtd_notas * sizeof(float));
        if (alunos[i].notas == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1);
        }

        for (int j = 0; j < alunos[i].qtd_notas; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }
}

void calcular_medias(Aluno *alunos, int qtd_alunos) {
    for (int i = 0; i < qtd_alunos; i++) {
        float soma = 0.0;
        for (int j = 0; j < alunos[i].qtd_notas; j++) {
            soma += alunos[i].notas[j];
        }
        alunos[i].media = (alunos[i].qtd_notas > 0) ? soma / alunos[i].qtd_notas : 0.0;
    }
}

int main() {
    int qtd_alunos;
    printf("Quantos alunos na turma? ");
    scanf("%d", &qtd_alunos);

    Aluno *alunos = (Aluno *)malloc(qtd_alunos * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    cadastrar_alunos(alunos, qtd_alunos);
    calcular_medias(alunos, qtd_alunos);

    printf("\nMédias dos alunos:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        printf("Aluno: %s | Média: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    // Libera memória
    for (int i = 0; i < qtd_alunos; i++) {
        free(alunos[i].notas);
    }
    free(alunos);

    return 0;
}
