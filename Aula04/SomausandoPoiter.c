#include <stdio.h>

int somar(int *, int *);

int main(void){

    int n1 =5, n2 = 7;

    printf("%d\n", somar(&n1, &n2));

    return 1;

}

int somar(int* num1, int* num2 ) {
    return *num1 + *num2;
}