#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente ou verticalmente
bool posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'h') {
        if (coluna + tamanho > TAMANHO_TABULEIRO) {
            return false; // Navio sai dos limites do tabuleiro
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) {
                return false; // Sobreposição de navios
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'v') {
        if (linha + tamanho > TAMANHO_TABULEIRO) {
            return false; // Navio sai dos limites do tabuleiro
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return false; // Sobreposição de navios
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        return false; // Direção inválida
    }
    return true;
}

// Função para posicionar um navio na diagonal
bool posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'd') {
        if (linha + tamanho > TAMANHO_TABULEIRO || coluna + tamanho > TAMANHO_TABULEIRO) {
            return false; // Navio sai dos limites do tabuleiro
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + i] == NAVIO) {
                return false; // Sobreposição de navios
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (direcao == 'e') {
        if (linha + tamanho > TAMANHO_TABULEIRO || coluna - tamanho < -1) {
            return false; // Navio sai dos limites do tabuleiro
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna - i] == NAVIO) {
                return false; // Sobreposição de navios
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    } else {
        return false; // Direção inválida
    }
    return true;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios horizontais/verticais
    if (!posicionarNavio(tabuleiro, 2, 2, 3, 'h')) {
        printf("Erro ao posicionar navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, 5, 1, 4, 'v')) {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Posicionar navios diagonais
    if (!posicionarNavioDiagonal(tabuleiro, 0, 0, 3, 'd')) {
        printf("Erro ao posicionar navio diagonal.\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, 0, 9, 3, 'e')) {
        printf("Erro ao posicionar navio diagonal.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}