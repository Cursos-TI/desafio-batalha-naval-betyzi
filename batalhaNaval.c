#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {


    //Aprimorei o codigo para a adicionar as habilidades especiais: forma de cone, forma de cruz e forma de lozango
    //Passos de 1 a 4 para facilitar a compreensão

    //**********************************************************
    //1. Criar o tabuleiro 10x10 e inicializar tudo com 0 (água) 
    //**********************************************************
    int tabuleiro[10][10] = {0};
  

    //**********************************
    // 2. Posicionar 4 navios tamanho 3
    // Dois navios: um horizontal e um vertical 
    // Dois navios diagonais 
    //**********************************

    // ---------Navio 1 - Horizontal na linha 1, coluna 1 a 3---------
    int navio1_linha = 1, navio1_coluna = 1;
    for(int i = 0; i < 3; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = 3;
    }
    
    // ---------Navio 2 - Vertical na linha 3 a 5, coluna 5---------
    int navio2_linha = 3, navio2_coluna = 5;
    for(int i = 0; i < 3; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = 3;
    }
    
    //---------Navio 3 - Diagonal crescente na linha 6 a 8, coluna 2 a 4---------
    int navio3_linha = 6, navio3_coluna = 2;
    for(int i = 0; i < 3; i++) {
        tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
    }
    
    //---------Navio 4 - Diagonal decrescente na linha 8 a 6, coluna 7 a 5---------
    int navio4_linha = 8, navio4_coluna = 7;
    for(int i = 0; i < 3; i++) {
        tabuleiro[navio4_linha - i][navio4_coluna - i] = 3;
    }
    
    //---------------------------------------------------------------
    // 3. Definir e aplicar habilidades especiais com áreas de efeito
    //---------------------------------------------------------------


    //************************************************* 
    // Habilidade 1: CONE (5x5), ponto de origem [0][4]
    //************************************************* 
    int cone[5][5] = {0};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(j >= 2 - i && j <= 2 + i) {  // formato de cone
                cone[i][j] = 1;
            }
        }
    }
    int cone_linha = 0, cone_coluna = 4;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(cone[i][j] == 1) {
                int linha = cone_linha + i - 2;  // centralizando matriz de 5x5
                int coluna = cone_coluna + j - 2;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;  // área afetada pela habilidade
                }
            }
        }
    }

    //************************************************* 
    // Habilidade 2: CRUZ (5x5), ponto de origem [5][5]
    //************************************************* 
    int cruz[5][5] = {0};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 2 || j == 2) { // linha central ou coluna central forma cruz
                cruz[i][j] = 1;
            }
        }
    }
    int cruz_linha = 5, cruz_coluna = 5;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(cruz[i][j] == 1) {
                int linha = cruz_linha + i - 2;
                int coluna = cruz_coluna + j - 2;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
    
    //*****************************************************
    // Habilidade 3: OCTAEDRO (5x5), ponto de origem [8][8]
    //*****************************************************
    int octaedro[5][5] = {0};
    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            int val_i = (i >= 0) ? i : -i;
            int val_j = (j >= 0) ? j : -j;
            if(val_i + val_j <= 2) {  // forma losango
                int linha = 8 + i;
                int coluna = 8 + j;
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    octaedro[i+2][j+2] = 1;
                }
            }
        }
    }
    int octaedro_linha = 8, octaedro_coluna = 8;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(octaedro[i][j] == 1) {
                int linha = octaedro_linha + i - 2;
                int coluna = octaedro_coluna + j - 2;
                if(tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    //****************************************
    // 4. Exibir o tabuleiro
    // 0 = água, 3 = navio, 5 = área de efeito
    //****************************************
    printf("  A B C D E F G H I J\n"); // colunas com letras
    for(int i = 0; i < 10; i++) {
        printf("%d ", i+1);  // linhas com números
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("Novo commit4");

    return 0;
}
