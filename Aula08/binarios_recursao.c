#include <stdio.h>

void calcular_binario(int n) {

    if(n < 0) return;
    
    int div = n/2;
    
    int resto =  n%2;
    if(div  != 0) calcular_binario(div);
    printf("%d", resto);
    
}


int main(void) {

    int n;

    printf("Escreva um valor para converter para binário: \n");
    scanf("%d", &n);

    calcular_binario(n);
    printf("\n");

    return 0;

}