#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

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

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanhoHabilidade = 5;
    int offset = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
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

    // Matrizes de habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibir tabuleiro com habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}