#include <stdio.h>

#define TAMANHO 10

int main() {
    // Tabuleiro representado por uma matriz
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Definição do navio vertical (3 posições)
    int x_vertical = 2, y_vertical = 4; // ponto inicial
    int tamanho_vertical = 3;

    // Definição do navio horizontal (4 posições)
    int x_horizontal = 6, y_horizontal = 1; // ponto inicial
    int tamanho_horizontal = 4;

    // Posicionando o navio vertical
    for (int i = 0; i < tamanho_vertical; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 1;
        printf("Navio vertical: (%d, %d)\n", x_vertical + i, y_vertical);
    }

    printf("\n");

    // Posicionando o navio horizontal
    for (int j = 0; j < tamanho_horizontal; j++) {
        tabuleiro[x_horizontal][y_horizontal + j] = 1;
        printf("Navio horizontal: (%d, %d)\n", x_horizontal, y_horizontal + j);
    }

    return 0;
}