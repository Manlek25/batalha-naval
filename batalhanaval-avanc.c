#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define ORIGEM_HABILIDADE 2 // Ponto central da matriz 5x5

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    // Exemplo: coloca alguns navios
    // tabuleiro[2][2] = 3;
    // tabuleiro[3][3] = 3;
    // tabuleiro[4][4] = 3;
}

void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

// Cone apontando para baixo
void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j - ORIGEM_HABILIDADE && i >= ORIGEM_HABILIDADE - j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cruz (vertical e horizontal)
void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == ORIGEM_HABILIDADE || j == ORIGEM_HABILIDADE)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Octaedro (losango)
void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - ORIGEM_HABILIDADE) + abs(j - ORIGEM_HABILIDADE) <= ORIGEM_HABILIDADE)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int matriz[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int linhaTab = origem_linha - ORIGEM_HABILIDADE + i;
                int colunaTab = origem_coluna - ORIGEM_HABILIDADE + j;

                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
    int escolha;

    inicializarTabuleiro(tabuleiro);

    printf("Escolha uma habilidade:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: criarMatrizCone(habilidade); break;
        case 2: criarMatrizCruz(habilidade); break;
        case 3: criarMatrizOctaedro(habilidade); break;
        default: printf("Opção inválida.\n"); return 1;
    }

    int linha, coluna;
    printf("Digite a linha e coluna de origem (0 a 9): ");
    scanf("%d %d", &linha, &coluna);

    aplicarHabilidade(tabuleiro, habilidade, linha, coluna);

    printf("\nTabuleiro com habilidade aplicada:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
