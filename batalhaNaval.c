#include <stdio.h>

#define TAMANHO 10

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // ===== Navio Vertical (tamanho 4) =====
    int x_vertical = 1, y_vertical = 2;
    int tamanho_vertical = 4;

    for (int i = 0; i < tamanho_vertical; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 3;
    }

    // ===== Navio Horizontal (tamanho 5) =====
    int x_horizontal = 7, y_horizontal = 1;
    int tamanho_horizontal = 5;

    for (int j = 0; j < tamanho_horizontal; j++) {
        tabuleiro[x_horizontal][y_horizontal + j] = 3;
    }

    // ===== Navio Diagonal para baixo-direita (tamanho 3) =====
    int x_diag1 = 0, y_diag1 = 0;
    int tamanho_diag1 = 3;

    for (int k = 0; k < tamanho_diag1; k++) {
        tabuleiro[x_diag1 + k][y_diag1 + k] = 3;
    }

    // ===== Navio Diagonal para cima-direita (tamanho 4) =====
    int x_diag2 = 9, y_diag2 = 0;
    int tamanho_diag2 = 4;

    for (int k = 0; k < tamanho_diag2; k++) {
        tabuleiro[x_diag2 - k][y_diag2 + k] = 3;
    }

    // ===== Exibir tabuleiro completo =====
    printf("=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}