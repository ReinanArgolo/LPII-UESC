#include <stdio.h>
#include <unistd.h> // Para sleep()

// Tipo para a função de callback
typedef void (*DownloadCallback)(int progresso);

// Função que simula um download longo
void baixar_arquivo(DownloadCallback callback) {
    for(int i = 0; i <= 100; i += 10) {
        sleep(1); // Simula trabalho
        callback(i); // Chama o callback com o progresso
    }
}

// Callback que mostra progresso no console
void mostrar_progresso(int progresso) {
    printf("Progresso do download: %d%%\n", progresso);
}

// Outro callback possível
void mostrar_barra(int progresso) {
    printf("[");
    for(int i = 0; i < 100; i += 10) {
        printf(i < progresso ? "#" : " ");
    }
    printf("] %d%%\r", progresso);
    fflush(stdout); // Força a saída imediata
}

int main() {
    printf("Download com callback textual:\n");
   // baixar_arquivo(mostrar_progresso);

    printf("\nDownload com callback gráfico:\n");
    baixar_arquivo(mostrar_barra);
    printf("\n"); // Nova linha após a barra

    return 0;
}
