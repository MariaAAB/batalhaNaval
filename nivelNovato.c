#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define TAM_NAVIO 3
int main() {
    int tabuleiro [LINHAS][COLUNAS] = {{0}};

    int navio1[TAM_NAVIO] = {3, 3, 3};
    int navio2[TAM_NAVIO] = {3, 3, 3};
    int navio3[TAM_NAVIO] = {3, 3, 3};
    int navio4[TAM_NAVIO] = {3, 3, 3};


    int inicio_navio1_lin = 2, inicio_navio1_col = 2; // linha 2, coluna 2
    int inicio_navio2_lin = 5, inicio_navio2_col = 5; // linha 5, coluna 5
    int inicio_navio3_lin = 7, inicio_navio3_col = 2; // linha 7, coluna 2
    int inicio_navio4_lin = 2, inicio_navio4_col = 7; // linha 2, coluna 7

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[inicio_navio1_lin][inicio_navio1_col + i] = navio1[i];
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[inicio_navio2_lin + i][inicio_navio2_col] = navio2[i];
    }
    
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[inicio_navio3_lin + i][inicio_navio3_col + i] = navio3[i];
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[inicio_navio4_lin + i][inicio_navio4_col + i] = navio4[i];
    }

    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}