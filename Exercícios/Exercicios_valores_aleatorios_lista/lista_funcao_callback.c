#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_OBSERVERS 10
#define NUM_TEMPERATURAS 10

typedef void (*Observer)(const char* mensagem);

typedef struct temper_lista {
    float temperatura;
    struct temper_lista* prox;
} temper_lista;

typedef struct SensorTemperatura {
    Observer observers[MAX_OBSERVERS];
    int num_observers;
    temper_lista* listas_temperaturas;
} SensorTemperatura;

float medir_temperatura(void);
temper_lista* alocar_lista(void);
void add_elemento(float temper, temper_lista** lista);
void registrar_observer(SensorTemperatura* sensor, Observer observer);
void notificar_observers(SensorTemperatura* sensor, const char* mensagem);
void atualizar_temperatura(SensorTemperatura* sensor, float nova_temp);
void log_console(const char* mensagem);
void alerta_email(const char* mensagem);
void atualizar_display(const char* mensagem);
void imprimir_temperaturas(temper_lista* lista);
float calcular_media_temperaturas(temper_lista* lista);
float encontrar_temperatura_maxima(temper_lista* lista);
float encontrar_temperatura_minima(temper_lista* lista);

int main(void) {
    srand(time(NULL));
    
    temper_lista* Head = NULL;
    SensorTemperatura DeteccoesTemperatura = {.listas_temperaturas = NULL, .num_observers = 0};
    
    registrar_observer(&DeteccoesTemperatura, log_console);
    registrar_observer(&DeteccoesTemperatura, alerta_email);
    registrar_observer(&DeteccoesTemperatura, atualizar_display);
    
    for (int i = 0; i < NUM_TEMPERATURAS; i++) {
        float temperatura_atual = medir_temperatura();
        
        if (DeteccoesTemperatura.listas_temperaturas == NULL) {
            add_elemento(temperatura_atual, &DeteccoesTemperatura.listas_temperaturas);
            
            char mensagem[50];
            snprintf(mensagem, 50, "Temperatura inicial: %.1f°C", temperatura_atual);
            notificar_observers(&DeteccoesTemperatura, mensagem);
        } else {
            atualizar_temperatura(&DeteccoesTemperatura, temperatura_atual);
        }
    }
    
    printf("\nTodas as temperaturas registradas:\n");
    imprimir_temperaturas(DeteccoesTemperatura.listas_temperaturas);
    
    float media = calcular_media_temperaturas(DeteccoesTemperatura.listas_temperaturas);
    float max = encontrar_temperatura_maxima(DeteccoesTemperatura.listas_temperaturas);
    float min = encontrar_temperatura_minima(DeteccoesTemperatura.listas_temperaturas);
    
    printf("\nEstatísticas:\n");
    printf("Temperatura média: %.1f°C\n", media);
    printf("Temperatura máxima: %.1f°C\n", max);
    printf("Temperatura mínima: %.1f°C\n", min);
    
    // Liberar memória (opcional)
    temper_lista *atual = DeteccoesTemperatura.listas_temperaturas;
    while (atual != NULL) {
        temper_lista *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    return 0;
}

float medir_temperatura(void) {
    return ((rand() % 501) / 10.0f) + 10.0f;  // Temperatura entre 10.0 e 60.0 °C
}

temper_lista* alocar_lista(void) {
    temper_lista* lista = (temper_lista*)malloc(sizeof(temper_lista));
    if (lista != NULL) {
        lista->prox = NULL;
    }
    return lista;
}

void add_elemento(float temper, temper_lista** lista) {
    temper_lista* novo = alocar_lista();
    
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    
    novo->temperatura = temper;
    novo->prox = NULL;
    
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    
    temper_lista* atual = *lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = novo;
}

void registrar_observer(SensorTemperatura* sensor, Observer observer) {
    if (sensor->num_observers < MAX_OBSERVERS) {
        sensor->observers[sensor->num_observers++] = observer;
    }
}

void notificar_observers(SensorTemperatura* sensor, const char* mensagem) {
    for (int i = 0; i < sensor->num_observers; i++) {
        sensor->observers[i](mensagem);
    }
}

void atualizar_temperatura(SensorTemperatura* sensor, float nova_temp) {
    if (sensor->listas_temperaturas == NULL) {
        add_elemento(nova_temp, &sensor->listas_temperaturas);
        char mensagem[50];
        snprintf(mensagem, 50, "Temperatura inicial: %.1f°C", nova_temp);
        notificar_observers(sensor, mensagem);
        return;
    }
    
    temper_lista* atual = sensor->listas_temperaturas;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    if (fabs(atual->temperatura - nova_temp) >= 1.0) {
        add_elemento(nova_temp, &sensor->listas_temperaturas);
        
        char mensagem[50];
        snprintf(mensagem, 50, "Nova temperatura: %.1f°C", nova_temp);
        notificar_observers(sensor, mensagem);
    }
}

void log_console(const char* mensagem) {
    printf("[LOG] %s\n", mensagem);
}

void alerta_email(const char* mensagem) {
    printf("Enviando e-mail: ALERTA - %s\n", mensagem);
}

void atualizar_display(const char* mensagem) {
    printf("DISPLAY: %s\n", mensagem);
}

void imprimir_temperaturas(temper_lista* lista) {
    temper_lista* atual = lista;
    int contador = 1;
    
    while (atual != NULL) {
        printf("Temperatura %d: %.1f°C\n", contador++, atual->temperatura);
        atual = atual->prox;
    }
}

float calcular_media_temperaturas(temper_lista* lista) {
    if (lista == NULL) {
        return 0.0f;
    }
    
    float soma = 0.0f;
    int contador = 0;
    temper_lista* atual = lista;
    
    while (atual != NULL) {
        soma += atual->temperatura;
        contador++;
        atual = atual->prox;
    }
    
    return soma / contador;
}

float encontrar_temperatura_maxima(temper_lista* lista) {
    if (lista == NULL) {
        return 0.0f;
    }
    
    float max = lista->temperatura;
    temper_lista* atual = lista->prox;
    
    while (atual != NULL) {
        if (atual->temperatura > max) {
            max = atual->temperatura;
        }
        atual = atual->prox;
    }
    
    return max;
}

float encontrar_temperatura_minima(temper_lista* lista) {
    if (lista == NULL) {
        return 0.0f;
    }
    
    float min = lista->temperatura;
    temper_lista* atual = lista->prox;
    
    while (atual != NULL) {
        if (atual->temperatura < min) {
            min = atual->temperatura;
        }
        atual = atual->prox;
    }
    
    return min;
}


