#include <stdio.h>
#include <math.h>   // para abs()

#define N 10   // tamanho do tabuleiro
#define H 5    // tamanho das habilidades

// Exibir tabuleiro 10x10
void exibirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[N][N] = {0};

    // ===== Navios (nível Aventureiro) =====
    // Vertical
    for (int i = 0; i < 4; i++) tabuleiro[1 + i][2] = 3;
    // Horizontal
    for (int j = 0; j < 5; j++) tabuleiro[7][1 + j] = 3;
    // Diagonal para baixo-direita
    for (int k = 0; k < 3; k++) tabuleiro[0 + k][0 + k] = 3;
    // Diagonal para cima-direita
    for (int k = 0; k < 4; k++) tabuleiro[9 - k][0 + k] = 3;

    // ===== Cone aplicado no centro (4,4) =====
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= (H/2 - i) && j <= (H/2 + i) && i <= H/2) {
                int x = 4 + i;
                int y = 4 + j;
                if (x < N && y < N && tabuleiro[x][y] == 0) tabuleiro[x][y] = 1;
            }
        }
    }

    // ===== Cruz aplicada no centro (2,7) =====
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) {
                int x = 2 + i;
                int y = 7 + j - 2; 
                if (x < N && y < N && tabuleiro[x][y] == 0) tabuleiro[x][y] = 1;
            }
        }
    }

    // ===== Octaedro aplicado no canto (5,0) =====
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H/2) + abs(j - H/2) <= H/2) {
                int x = 5 + i - 2;
                int y = 0 + j;
                if (x >= 0 && x < N && y < N && tabuleiro[x][y] == 0) tabuleiro[x][y] = 1;
            }
        }
    }

    // ===== Mostrar tabuleiro final =====
    printf("=== Tabuleiro com Navios (3) e Habilidades (1) ===\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}