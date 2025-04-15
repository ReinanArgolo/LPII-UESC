#include <stdio.h>

void imprimeTabuleiro(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %c ", tabuleiro[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("-----------\n");
    }
}

int verificaGanhador(char tabuleiro[3][3]){
    // Verifica linhas e colunas
    for(int i = 0; i < 3; i++){
        // Linhas
        if(tabuleiro[i][0] == tabuleiro[i][1] && 
           tabuleiro[i][1] == tabuleiro[i][2]){
            if(tabuleiro[i][0] == 'X') return 1;
            if(tabuleiro[i][0] == 'O') return 2;
        }
        // Colunas
        if(tabuleiro[0][i] == tabuleiro[1][i] && 
           tabuleiro[1][i] == tabuleiro[2][i]){
            if(tabuleiro[0][i] == 'X') return 1;
            if(tabuleiro[0][i] == 'O') return 2;
        }
    }
    // Diagonais
    if(tabuleiro[0][0] == tabuleiro[1][1] && 
       tabuleiro[1][1] == tabuleiro[2][2]){
        if(tabuleiro[0][0] == 'X') return 1;
        if(tabuleiro[0][0] == 'O') return 2;
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && 
       tabuleiro[1][1] == tabuleiro[2][0]){
        if(tabuleiro[0][2] == 'X') return 1;
        if(tabuleiro[0][2] == 'O') return 2;
    }
    // Sem ganhador
    return 0;
}

int main(void){
    char tabuleiro[3][3] = {
        {'O', 'X', 'X'},
        {'O', 'O', ' '},
        {' ', ' ', 'O'}
    };

    imprimeTabuleiro(tabuleiro);

    int resultado = verificaGanhador(tabuleiro);
    if(resultado == 1)  printf("Jogador X venceu!\n");
    else if(resultado == 2) printf("Jogador O venceu!\n");
    else printf("Ninguém venceu ainda.\n");

    return 0;
}