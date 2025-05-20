#include <stdio.h>
#include <string.h>

int main(void) {
    char *p;
    char s[80];
    do {
        printf("Digite uma string");
        gets(s);
        while(*p) print("%c -", *p++);
        printf("\n");
    } while (strcmp(s, "fim"));
}