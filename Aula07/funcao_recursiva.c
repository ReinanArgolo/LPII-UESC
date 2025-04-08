#include <stdio.h>

void funcaoRecursiva (int chamarRecusivo) {
    printf("Chamada com: %d\n", chamarRecusivo);

    if(!chamarRecusivo){
        printf("Retornando do caso base\n");
        return;
    } else {
        funcaoRecursiva(chamarRecusivo - 1);
        printf("Retornando do RECURSIVO\n");
        return;
        
    }
}

int main() {
    printf("Chamando com 0\n");
    funcaoRecursiva(0);

    printf("Chamando com 1\n");
    funcaoRecursiva(1);

    printf("Chamando com 1\n");
    funcaoRecursiva(5);

    return 0;
}