#include <stdio.h>
#include <stdlib.h>

int main() {

    // ── 1. TABULEIRO 10x10 (0 = agua) ───────────────────────
    int tabuleiro[10][10] = {0};

    // ── 2. NAVIOS (valor 3) ──────────────────────────────────

    // Navio 1 - Vertical: coluna 3, linhas 0 a 4
    for (int i = 0; i < 5; i++)
        tabuleiro[i][3] = 3;

    // Navio 2 - Horizontal: linha 2, colunas 1 a 5
    for (int i = 0; i < 5; i++)
        tabuleiro[2][1 + i] = 3;

    // ── 3. MATRIZES DE HABILIDADE 5x5 ───────────────────────
    int cone[5][5]     = {0};
    int cruz[5][5]     = {0};
    int octaedro[5][5] = {0};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // CONE: aponta para baixo - linha i afeta colunas (2-i) ate (2+i)
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;

            // CRUZ: linha central (i==2) OU coluna central (j==2)
            if (i == 2 || j == 2)
                cruz[i][j] = 1;

            // OCTAEDRO (losango): distancia de Manhattan <= 2
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
        }
    }

    // ── 4. INTEGRAR HABILIDADES AO TABULEIRO ────────────────
    // Cone     (valor 1): origem na linha 7, coluna 2
    // Cruz     (valor 2): origem na linha 5, coluna 6
    // Octaedro (valor 2): origem na linha 5, coluna 6

    int origens[3][2] = {{7, 2}, {5, 6}, {5, 6}};
    int valores[3]    = {1, 2, 2};

    int habs[3][5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            habs[0][i][j] = cone[i][j];
            habs[1][i][j] = cruz[i][j];
            habs[2][i][j] = octaedro[i][j];
        }

    // Sobrepor cada habilidade ao tabuleiro
    for (int h = 0; h < 3; h++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                // Calcular posicao no tabuleiro centralizada na origem
                int tl = origens[h][0] + i - 2;
                int tc = origens[h][1] + j - 2;

                // Validar limites e nao sobrescrever navios
                if (habs[h][i][j] == 1 && tl >= 0 && tl < 10 && tc >= 0 && tc < 10)
                    if (tabuleiro[tl][tc] == 0)
                        tabuleiro[tl][tc] = valores[h];
            }
        }
    }

    // ── 5. EXIBIR TABULEIRO ──────────────────────────────────
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}