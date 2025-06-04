#include <stdio.h>

const int TAMANHO_TABULEIRO = 10;
const int TAMANHO_NAVIO = 3;

// Função para verificar se há colisão e se o navio cabe no tabuleiro
int verificaColisao(int tabuleiro[10][10], int linha, int coluna, int direcaoLinha, int direcaoColuna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        int l = linha + i * direcaoLinha;
        int c = coluna + i * direcaoColuna;
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
        {
            return 0; // fora dos limites
        }
        if (tabuleiro[l][c] != 0)
        {
            return 0; // colisão detectada
        }
    }
    return 1; // tudo certo
}

// Função para posicionar o navio
void posicionaNavio(int tabuleiro[10][10], int linha, int coluna, int direcaoLinha, int direcaoColuna)
{
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        int l = linha + i * direcaoLinha;
        int c = coluna + i * direcaoColuna;
        tabuleiro[l][c] = 3;
    }
}

int main()
{
    int tabuleiro[10][10] = {{0}};

    // Tentativas de posicionamento de navios
    if (verificaColisao(tabuleiro, 2, 4, 0, 1)) // horizontal →
        posicionaNavio(tabuleiro, 2, 4, 0, 1);
    else
        printf("⚠️ Não foi possível posicionar navio horizontal\n");

    if (verificaColisao(tabuleiro, 5, 7, 1, 0)) // vertical ↓
        posicionaNavio(tabuleiro, 5, 7, 1, 0);
    else
        printf("⚠️ Não foi possível posicionar navio vertical\n");

    if (verificaColisao(tabuleiro, 1, 1, 1, 1)) // diagonal ↘
        posicionaNavio(tabuleiro, 1, 1, 1, 1);
    else
        printf("⚠️ Não foi possível posicionar navio diagonal ↘\n");

    if (verificaColisao(tabuleiro, 0, 3, 1, -1)) // diagonal ↙
        posicionaNavio(tabuleiro, 0, 3, 1, -1);
    else
        printf("⚠️ Não foi possível posicionar navio diagonal ↙\n");

    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
