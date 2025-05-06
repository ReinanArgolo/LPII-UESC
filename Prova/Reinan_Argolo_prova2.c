#include <stdio.h>
#define QTDALUNOS 3

// Define o tipo estruturado aluno, contendo nome, idade, sexo e Coeficiente de rendimento
typedef struct {
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

    printf("Digite o sexo: ");
    scanf(" %9[^\n]s", aluno.sexo);

    printf("Digite o CR: ");
    scanf(" %f", &aluno.cr); 


    printf("\n"); // fins de estilização

    // retorna a estrutura criada
    return aluno;
}


// Alteração pós-prova: Remover o ponteiro do ponteiro de Temp;

void ordena_Alunos(Aluno** ptr_alunos) {
    Aluno* temp;

    // itera sob o vetor, acessando seu valores
    for(int i = 0; i < QTDALUNOS-1; i++) {
        // itera novamente sob o vetor, essa ieração ocorrerá por todo o vetor enquanto a anterior permaneçe estática até esta ser finalizada
        for(int j = i+1; j < QTDALUNOS; j++) {

            // Compara o valor da primeira iteração com todos os valores do vetor, se ele for maior, ele assume a posição do menor, que por sua vez assume a posição do maior
            if((*(ptr_alunos+i))->cr > (*(ptr_alunos+j))->cr) {

                //Armazena o conteúdo do maior
                temp = *(ptr_alunos+i);
                // sobrescreve o valor de i por j
                *(ptr_alunos+i) = *(ptr_alunos+j);
                // sobrescreve o valor de j por temp (Outrora i)
                *(ptr_alunos+j) = temp;
            }
        }
    }
}


// Recebe dados de um aluno por raprâmentro e imprime-o
void prn_Aluno (Aluno aluno) {
    printf("Nome: %-20s | Idade: %6d | Sexo: %s | CR: %.2f\n", aluno.nome, aluno.idade, aluno.sexo, aluno.cr);
    // printf("\n"); // adiciona quebra de linha para fins de estlização

}

int main(void) {
    
    //define vetor de com 3 posições (definido no header), com 3 estruturas
    Aluno Taluno[QTDALUNOS];
    Aluno* ptr_alunos[QTDALUNOS];

    // itera sobre a função lê aluno 3x, e armazena em cada posição do vetor.
    for(int i = 0; i < QTDALUNOS; i++) {
        printf("Cadastro Aluno %d: \n", i+1);
        *(Taluno+i)= le_aluno();
        *(ptr_alunos+i) = (Taluno+i);
    }

    

    // imprime dados antes de serem ordenados
    printf("=== DADOS ORIGINAIS ===\n");

    for(int i = 0; i < QTDALUNOS; i++) {
        prn_Aluno(**(ptr_alunos+i));
    }

    printf("\n");
    printf("=== ORDENADOS POR CR ===\n");
    // Ordena o vetor
    ordena_Alunos(ptr_alunos);
    // imprime dados depois de serem ordenador
    for(int i = 0; i < QTDALUNOS; i++) {
        prn_Aluno(**(ptr_alunos+i));
    }

    return 0;
}