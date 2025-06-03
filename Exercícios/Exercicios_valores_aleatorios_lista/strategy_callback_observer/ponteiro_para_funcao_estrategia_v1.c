#include <stdio.h>

// Estratégias de pagamento
float pagamento_cartao_credito(float valor) {
    printf("Processando cartão de crédito...\n");
    return valor * 1.02f; // 2% de taxa
}

float pagamento_boleto(float valor) {
    printf("Emitindo boleto...\n");
    return valor * 0.95f; // 5% de desconto
}

float pagamento_pix(float valor) {
    printf("Processando PIX...\n");
    return valor; // Sem taxas
}

// Contexto que usa a estratégia
void processar_pagamento(float valor, float (*metodo_pagamento)(float)) {
    float valor_final = metodo_pagamento(valor);
    printf("Valor final: R$ %.2f\n", valor_final);
}

int main() {
    float compra = 100.0f;

    printf("Pagamento com cartão:\n");
    processar_pagamento(compra, pagamento_cartao_credito);

    printf("\nPagamento com boleto:\n");
    processar_pagamento(compra, pagamento_boleto);

    printf("\nPagamento com PIX:\n");
    processar_pagamento(compra, pagamento_pix);

    return 0;
}
