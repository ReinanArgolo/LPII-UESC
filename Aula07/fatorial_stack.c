#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
    if(n==1) return 1;
    return n * fat(n-1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    system("clear");
    printf("Fatorial de %d: %d\n", n, fat(n));
}