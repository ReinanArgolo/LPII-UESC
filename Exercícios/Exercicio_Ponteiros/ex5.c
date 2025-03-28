#include <stdio.h>

int main(void) {
    int a = 6;
    float b = 7.2;
    double c = 5.8734789832469874;
    char d = 'a';

    int* ptr_int = &a;
    float* ptr_float = &b;
    double* ptr_double = &c;
    char* ptr_char = &d;

    printf("int = %d bytes\n", sizeof(*ptr_int));
    printf("float = %d bytes\n", sizeof(*ptr_float));
    printf("double = %d bytes\n", sizeof(*ptr_double));
    printf("char = %d bytes\n", sizeof(*ptr_char));

}