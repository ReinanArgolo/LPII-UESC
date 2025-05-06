#include <stdio.h>
#define QTDALUNOS 3

// Define o tipo estruturado aluno, contendo nome, idade, sexo e Coeficiente de rendimento
typedef struct
{
    char nome[50];
    int idade;
    char sexo[10];
    float cr;

} Aluno;

// Cria a função sem parâmetros e com retorno que solicita entrada do usuário com os dados do aluno
Aluno le_aluno(void) {
    
    // declara a estrutura a ser preenchida
    Aluno aluno;
    
    printf("Digite o nome: ");
    scanf(" %49[^\n]s", aluno.nome);

    printf("Digite a idade: ");
    scanf(" %d", &aluno.idade);
    while (aluno.idade <= 0) scanf(" %d", &aluno.idade);

    printf("Digite o sexo: ");
    scanf(" %9[^\n]s", aluno.sexo);

    printf("Digite o CR: ");
    scanf(" %f", &aluno.cr);
    while (aluno.idade < 0) scanf(" %d", &aluno.cr);


    printf("\n"); // fins de estilização

    // retorna a estrutura criada
    return aluno;
}

void ordena_Alunos(Aluno alunos[]) {
    Aluno temp;

    // itera sob o vetor, acessando seu valores
    for(int i = 0; i < QTDALUNOS-1; i++) {
        // itera novamente sob o vetor, essa ieração ocorrerá por todo o vetor enquanto a anterior permaneçe estática até esta ser finalizada
        for(int j = i+1; j < QTDALUNOS; j++) {

            // Compara o valor da primeira iteração com todos os valores do vetor, se ele for maior, ele assume a posição do menor, que por sua vez assume a posição do maior
            if(alunos[i].cr > alunos[j].cr) {

                //Armazena o conteúdo do maior
                temp = alunos[i];

                // sobrescreve o valor de i por j
                alunos[i] = alunos[j];

                // sobrescreve o valor de j por temp (Outrora i)
                alunos[j] = temp;
            }
        }
    }
}


// Recebe dados de um aluno por raprâmentro e imprime-o
void prn_Aluno (Aluno aluno) {

    printf("--Dados do Aluno--\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Sexo: %s\n", aluno.sexo );
    printf("CR: %.2f\n", aluno.cr);

    printf("\n"); // adiciona quebra de linha para fins de estlização

}

int main(void) {
    
    //define vetor de com 3 posições (definido no header), com 3 estruturas
    Aluno alunos[QTDALUNOS];

    // itera sobre a função lê aluno 3x, e armazena em cada posição do vetor.
    for(int i = 0; i < QTDALUNOS; i++) {
        printf("Cadastro Aluno %d: \n", i+1);
        alunos[i] = le_aluno();

        
    }

    // imprime dados antes de serem ordenados
    printf("=== ANTES DA ORDENAÇÃO ===\n");

    for(int i = 0; i < QTDALUNOS; i++) {
        prn_Aluno(alunos[i]);
    }

    // ordena o vetor
    printf("=== DEPOIS DA ORDENAÇÃO ===\n");
    ordena_Alunos(alunos);

    // imprime dados depois de serem ordenados
    for(int i = 0; i < QTDALUNOS; i++) {
        prn_Aluno(alunos[i]);
    }
}