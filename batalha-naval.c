#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Define as coordenadas iniciais e orientações dos navios
    int navio1_linha = 2, navio1_coluna = 3, navio1_orientacao = 0; // Horizontal
    int navio2_linha = 6, navio2_coluna = 1, navio2_orientacao = 1; // Vertical

    // Posiciona o primeiro navio (horizontal)
    if (navio1_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    } else {
        printf("Navio 1 fora dos limites do tabuleiro.\n");
    }

    // Posiciona o segundo navio (vertical)
    if (navio2_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
        }
    } else {
        printf("Navio 2 fora dos limites do tabuleiro.\n");
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}