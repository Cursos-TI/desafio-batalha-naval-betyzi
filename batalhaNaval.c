#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

// Neste nivel apenas criei o tabuleiro 10x10, com navios ja posicionados no tabuleiro (a água é representada por "0" e os navios por "3")

    // Tamanho do tabuleiro e dos navios diretamente no código
    int tabuleiro[10][10];  // Tabuleiro 10x10
    int navio_horizontal[3] = {3, 3, 3}; // Navio horizontal com 3 partes
    int navio_vertical[3] = {3, 3, 3};   // Navio vertical com 3 partes

    // Primeiro inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Depois colocamos as coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    //Agora algumas verificações para evitar erros

    // Aqui verificamos se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    }

    // Aqui vrificamos se o navio vertical cabe no tabuleiro e se não há sobreposição
    if (linha_vertical + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    }

    // Por fim exibimos o tabuleiro
    printf("Tabuleiro de Batalha Naval - Nível Novato 🚢\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("Novo commit");
    
    return 0;
}
