#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    printf("batalha naval!");
}
    
// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se o navio pode ser posicionado sem sair dos limites e sem sobreposição
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Fora dos limites ou sobreposição
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = 3;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
