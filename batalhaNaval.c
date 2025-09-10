#include <stdio.h>

#define TAMANHO 5

// Função para exibir matriz
void exibirMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int cone[TAMANHO][TAMANHO] = {0};
    int cruz[TAMANHO][TAMANHO] = {0};
    int octaedro[TAMANHO][TAMANHO] = {0};

    // ===== Cone =====
    // Forma de pirâmide invertida
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (j >= (TAMANHO/2 - i) && j <= (TAMANHO/2 + i) && i <= TAMANHO/2) {
                cone[i][j] = 1;
            }
        }
    }

    // ===== Cruz =====
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (i == TAMANHO/2 || j == TAMANHO/2) {
                cruz[i][j] = 1;
            }
        }
    }

    // ===== Octaedro =====
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            // distância de Manhattan até o centro
            if (abs(i - TAMANHO/2) + abs(j - TAMANHO/2) <= TAMANHO/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ===== Exibir resultados =====
    printf("=== Habilidade Cone ===\n");
    exibirMatriz(cone);

    printf("=== Habilidade Cruz ===\n");
    exibirMatriz(cruz);

    printf("=== Habilidade Octaedro ===\n");
    exibirMatriz(octaedro);

    return 0;
}