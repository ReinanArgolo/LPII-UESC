#define NOME_MAX 60
#define TAM_MAX 15

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void ordena (char **p,int n){
    char *temp;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1; j<n;j++){
            if(strcmp(p[i], p[j])>0){
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}

int main(void) {
    char nomes[NOME_MAX][TAM_MAX];
    char *p[30]; /* Matriz de ponteiros */
    int n, i;
    for(n=0;;n++){
        printf("Digite nome ou [ENTER] para fim; ");
        gets(nomes[n]);
        // scanf(" %[^\n]*c", nomes[n]);
        if(strlen (nomes[n])==0) break;
        p[n] = nomes[n];
        printf("\n\nLista original; \n*");
        for (i=0;i<n;i++){
            printf("%s\n", p[i]);
        }
    return 0;
    }
}