#include <stdio.h>
#include <stdlib.h>
#define QTDALUN 5
#define QTDNOTAS 3

typedef struct {

    char nome[50];
    char matricula[8];
    float notas[QTDNOTAS];
    float media;

} Aluno;

float calcular_media(float notas[]){
    float sum=0.0f;

    for(int i = 0; i < QTDNOTAS; i++) sum += notas[i];

    return sum / QTDNOTAS;
}

void imprimir_maior_media(Aluno* aluno) {
    float maior = aluno[0].media;
    int index = 0; 
    for(int i = 0; i < QTDALUN; i++) {
        if(aluno[i].media > maior) {
            maior = aluno[i].media;
            index = i;
        }
    }

    printf("- - - ALUNO COM MAIOR MÉDIA - - -\n");
    printf("Nome: %s\n", aluno[index].nome);
    printf("Matítula: %s\n", aluno[index].matricula);
    printf("Média: %.2f\n", aluno[index].media);
    
}



int main(void) {

    Aluno alunos[QTDALUN];

    for(int i = 0; i< QTDALUN; i++) {

        system("clear");

        // pede o nome do aluno
        printf("Digite o nome do aluno %d: ", i);
        scanf(" %49[^\n]s", alunos[i].nome);

        printf("Digite a matricula do aluno %d: ", i);
        scanf(" %8[^\n]s", alunos[i].matricula);

        for (int j = 0; j < 3; j++) {
            printf("Digite a nota %d do aluno %d: ", j, i);
            scanf(" %f", &alunos[i].notas[j]);
        }

        alunos[i].media = calcular_media(alunos[i].notas);
        printf("Média: %.2f\n", alunos[i].media);
    }

    imprimir_maior_media(alunos);
    
}

