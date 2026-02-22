#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABIL 5

/* valores distintos para cada habilidade */
#define VAL_CONE   1
#define VAL_CRUZ   4
#define VAL_OCTA   6


static void zerarMatriz(int tamanho, int mat[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            mat[i][j] = 0;
        }
    }
}


static void construirCone(int tamanho, int mat[tamanho][tamanho], int val) {
    zerarMatriz(tamanho, mat);
    int centro = tamanho / 2;

    for (int r = 0; r < tamanho; ++r) {
        /* metade da largura do cone nesta linha */
        int meio = (r <= centro) ? r : centro;
        for (int c = 0; c < tamanho; ++c) {
            if (c >= centro - meio && c <= centro + meio) {
                mat[r][c] = val;
            }
        }
    }
}


static void construirCruz(int tamanho, int mat[tamanho][tamanho], int val) {
    zerarMatriz(tamanho, mat);
    int centro = tamanho / 2;

    for (int r = 0; r < tamanho; ++r) {
        for (int c = 0; c < tamanho; ++c) {
            if (r == centro || c == centro) {
                mat[r][c] = val;
            }
        }
    }
}


static void construirOctaedro(int tamanho, int mat[tamanho][tamanho], int val) {
    zerarMatriz(tamanho, mat);
    int centro = tamanho / 2;

    for (int r = 0; r < tamanho; ++r) {
        for (int c = 0; c < tamanho; ++c) {
            int dist = abs(r - centro) + abs(c - centro);
            if (dist <= centro) {
                mat[r][c] = val;
            }
        }
    }
}


static void sobrepor(int tab[TAM_TABULEIRO][TAM_TABULEIRO], int tamanho,
                    int mat[tamanho][tamanho], int origR, int origC) {
    int meio = tamanho / 2;

    for (int r = 0; r < tamanho; ++r) {
        for (int c = 0; c < tamanho; ++c) {
            if (mat[r][c] == 0)
                continue;

            int br = origR + (r - meio);
            int bc = origC + (c - meio);
            if (br >= 0 && br < TAM_TABULEIRO && bc >= 0 && bc < TAM_TABULEIRO) {
                tab[br][bc] = mat[r][c];
            }
        }
    }
}

static void imprimirMatriz(int linhas, int colunas, int mat[linhas][colunas]) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int cone[TAM_HABIL][TAM_HABIL];
    int cruz[TAM_HABIL][TAM_HABIL];
    int octaedro[TAM_HABIL][TAM_HABIL];

    /* montar as matrizes de habilidade */
    construirCone(TAM_HABIL, cone, VAL_CONE);
    construirCruz(TAM_HABIL, cruz, VAL_CRUZ);
    construirOctaedro(TAM_HABIL, octaedro, VAL_OCTA);

    printf("Matriz de habilidade: Cone\n");
    imprimirMatriz(TAM_HABIL, TAM_HABIL, cone);
    putchar('\n');

    printf("Matriz de habilidade: Cruz\n");
    imprimirMatriz(TAM_HABIL, TAM_HABIL, cruz);
    putchar('\n');

    printf("Matriz de habilidade: Octaedro\n");
    imprimirMatriz(TAM_HABIL, TAM_HABIL, octaedro);
    putchar('\n');

    /* pontos de origem no tabuleiro (linha, coluna) */
    int originConeR = 2, originConeC = 3;
    int originCrossR = 5, originCrossC = 5;
    int originOctaR  = 7, originOctaC  = 1;

    /* sobrepor as três habilidades no tabuleiro de 10x10 */
    sobrepor(tabuleiro, TAM_HABIL, cone, originConeR, originConeC);
    sobrepor(tabuleiro, TAM_HABIL, cruz, originCrossR, originCrossC);
    sobrepor(tabuleiro, TAM_HABIL, octaedro, originOctaR, originOctaC);

    printf("\nTabuleiro final (valores mostram habilidade aplicada)\n");
    imprimirMatriz(TAM_TABULEIRO, TAM_TABULEIRO, tabuleiro);

    return 0;
}
