#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n;
    printf("Digite o tanaho do vetor: ");
    scanf(" %d", &n);

    int* ptr = (void*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) scanf(" %d", (ptr+i));

    for(int i = 0; i < n; i++) printf(" %d", *(ptr+i));
    printf("\n");

    free(ptr);

    return 0;
}