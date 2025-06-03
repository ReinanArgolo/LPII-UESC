#include <stdio.h>
#include <stdlib.h>

#define MAX_OBSERVERS 10

// Tipo para a função observer
typedef void (*Observer)(const char* mensagem);

// Estrutura do sujeito observável
struct SensorTemperatura {
    Observer observers[MAX_OBSERVERS];
    int num_observers;
    float temperatura;
};

// Registra um novo observer
void registrar_observer(struct SensorTemperatura* sensor, Observer observer) {
    if(sensor->num_observers < MAX_OBSERVERS) {
        sensor->observers[sensor->num_observers++] = observer;
    }
}

// Notifica todos os observers
void notificar_observers(struct SensorTemperatura* sensor, const char* mensagem) {
    for(int i = 0; i < sensor->num_observers; i++) {
        sensor->observers[i](mensagem);
    }
}

// Atualiza a temperatura e notifica se mudou significativamente
void atualizar_temperatura(struct SensorTemperatura* sensor, float nova_temp) {
    if(abs(sensor->temperatura - nova_temp) >= 1.0) {
        sensor->temperatura = nova_temp;

        char mensagem[50];
        snprintf(mensagem, 50, "Nova temperatura: %.1f°C", nova_temp);
        notificar_observers(sensor, mensagem);
    }
}

// Observers concretos
void log_console(const char* mensagem) {
    printf("[LOG] %s\n", mensagem);
}

void alerta_email(const char* mensagem) {
    printf("Enviando e-mail: ALERTA - %s\n", mensagem);
}

void atualizar_display(const char* mensagem) {
    printf("DISPLAY: %s\n", mensagem);
}

int main() {
    struct SensorTemperatura sensor = { .num_observers = 0, .temperatura = 20.0 };

    // Registra os observers
    registrar_observer(&sensor, log_console);
    registrar_observer(&sensor, alerta_email);
    registrar_observer(&sensor, atualizar_display);

    // Simula mudanças de temperatura
    atualizar_temperatura(&sensor, 20.5f); // Não notifica (mudança < 1°C)
    atualizar_temperatura(&sensor, 22.0f); // Notifica todos os observers
    atualizar_temperatura(&sensor, 21.8f); // Não notifica
    atualizar_temperatura(&sensor, 19.0f); // Notifica

    return 0;
}
