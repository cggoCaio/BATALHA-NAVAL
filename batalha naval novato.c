#include <stdio.h>

int main() {

    // Tabuleiro 10x10 inicializado com 0 (agua)
    int tabuleiro[10][10] = {0};

    // ── Navios ──────────────────────────────────────────────
    // Navio 1 - Horizontal: linha 2, colunas 3,4,5
    int navio_h[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++)
        tabuleiro[2][3 + i] = navio_h[i];

    // Navio 2 - Vertical: linhas 5,6,7, coluna 7
    int navio_v[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][7] = navio_v[i];

    // Navio 3 - Diagonal principal (↘): linha 0 col 0, linha 1 col 1, linha 2 col 2
    int navio_d1[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++)
        tabuleiro[0 + i][0 + i] = navio_d1[i];

    // Navio 4 - Diagonal secundaria (↙): linha 0 col 9, linha 1 col 8, linha 2 col 7
    int navio_d2[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++)
        tabuleiro[0 + i][9 - i] = navio_d2[i];

    // ── Exibir tabuleiro ────────────────────────────────────
    printf("--- Batalha Naval ---\n\n");

    // Cabecalho com letras (colunas)
    printf("   ");
    for (int j = 0; j < 10; j++)
        printf("%c ", 'A' + j);
    printf("\n");

    // Linhas com numero + conteudo
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    printf("\n0 = Agua | 3 = Navio\n");

    return 0;
}