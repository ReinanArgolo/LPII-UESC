#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 512
#define MAX_FIELD_LEN 200

typedef struct {
    char nome[MAX_FIELD_LEN];
    char cargo[MAX_FIELD_LEN];
    char pais_local[MAX_FIELD_LEN];
    int idade;
    char pais_origem[MAX_FIELD_LEN];
} CardealInfo;

// Função para ajudar a parsear campos, tratando campos vazios
char* parse_field(char** line_ptr, const char* delimiter) {
    char* token = strsep(line_ptr, delimiter);
    if (token == NULL) return ""; // Should not happen if format is correct
    // Remove leading/trailing whitespace if any (optional)
    // while (isspace((unsigned char)*token)) token++;
    // char* end = token + strlen(token) - 1;
    // while (end > token && isspace((unsigned char)*end)) end--;
    // *(end + 1) = '\0';
    return token;
}

int main() {
    FILE *file = NULL;
    
    // Tenta abrir o arquivo com caminho relativo simples (sem ./)
    file = fopen("lista.csv", "r");
    
    // Se falhar, tenta com o caminho relativo ./dados/
    if (file == NULL) {
        file = fopen("./dados/lista.csv", "r");
    }

    // Se falhar, tenta com o caminho relativo ../dados/ (considerando execução de subdiretório)
    if (file == NULL) {
        file = fopen("../dados/lista.csv", "r");
    }
    
    // Se ainda falhar, pergunta ao usuário
    if (file == NULL) {
        char filepath[MAX_LINE_LEN] = "./lista.csv";
        printf("Não foi possível abrir o arquivo automaticamente.\n");
        printf("Digite o caminho completo para o arquivo CSV: ");
        
        char input[MAX_LINE_LEN];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove quebra de linha
            input[strcspn(input, "\n")] = 0;
            strcpy(filepath, input);
            
            file = fopen(filepath, "r");
            if (file == NULL) {
                printf("Erro ao abrir o arquivo '%s': ", filepath);
                perror("");
                return 1;
            }
        }
    }
    
    // Se ainda não conseguiu abrir
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo 'lista.csv'.\n");
        printf("Verifique se o arquivo existe no diretório correto.\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    CardealInfo cardeais[200]; // Array para armazenar os dados, ajuste o tamanho
    int count = 0;

    // Ignorar a linha do cabeçalho
    if (fgets(line, sizeof(line), file) == NULL) {
        fprintf(stderr, "Arquivo vazio ou erro ao ler cabeçalho.\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL && count < 200) {
        // Remover a nova linha do final, se houver
        line[strcspn(line, "\n")] = 0;

        char* line_ptr = line; // strsep modifica o ponteiro
        char* nome_str = parse_field(&line_ptr, ";");
        char* cargo_str = parse_field(&line_ptr, ";");
        char* pais_local_str = parse_field(&line_ptr, ";");
        char* idade_str_field = parse_field(&line_ptr, ";");
        char* pais_origem_str = parse_field(&line_ptr, ";"); // O resto da linha

        strncpy(cardeais[count].nome, nome_str, MAX_FIELD_LEN - 1);
        cardeais[count].nome[MAX_FIELD_LEN - 1] = '\0';

        strncpy(cardeais[count].cargo, cargo_str, MAX_FIELD_LEN - 1);
        cardeais[count].cargo[MAX_FIELD_LEN - 1] = '\0';

        strncpy(cardeais[count].pais_local, pais_local_str, MAX_FIELD_LEN - 1);
        cardeais[count].pais_local[MAX_FIELD_LEN - 1] = '\0';
        
        cardeais[count].idade = atoi(idade_str_field); // atoi retorna 0 se não puder converter

        strncpy(cardeais[count].pais_origem, pais_origem_str, MAX_FIELD_LEN - 1);
        cardeais[count].pais_origem[MAX_FIELD_LEN - 1] = '\0';
        
        count++;
    }

    fclose(file);

    // Exemplo: Imprimir os dados lidos
    for (int i = 0; i < count; i++) {
        printf("Nome: %s\n", cardeais[i].nome);
        printf("Cargo: %s\n", cardeais[i].cargo);
        printf("País/Local: %s\n", cardeais[i].pais_local);
        printf("Idade: %d\n", cardeais[i].idade);
        printf("País de Origem: %s\n\n", cardeais[i].pais_origem);
    }

    printf("Total de registros lidos: %d\n", count);

    return 0;
}