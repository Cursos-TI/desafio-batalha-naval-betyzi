#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

//Para este nível aprimorei para para adionar barcos (3) em posições diagonais além de vertical e horizontal

    //Criando o tabuleiro 10x10
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Colocando o navio horizontal (tamanho 3)
    // Começa na linha 2 (índice 1), coluna C (índice 2)
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Colocando o navio vertical (tamanho 3)
    // Começa na linha 5 (índice 4), coluna G (índice 6)
    tabuleiro[4][6] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;

    // Agora o primeiro navio diagonal ↘ (tamanho 3)
    // Começa na linha 1 (índice 0), coluna A (índice 0)
    tabuleiro[0][0] = 3;
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;

    // Por fim, o segundo navio diagonal ↙ (tamanho 3)
    // Começa na linha 1 (índice 0), coluna J (índice 9)
    tabuleiro[0][9] = 3;
    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;

    // Exibindo o tabuleiro com letras (A-J) e números (1-10) tudo junto 
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("Novo commit2");

    return 0;
}
