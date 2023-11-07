#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[31];
    char posicao;
    int forca;
} Jogador;

void ler_time(Jogador time[11]) {
    char linha[100];
    char nomeJogador[31];
    char posicao;
    int forca;

    for (int i = 0; i < 11; i++) {
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%[^;];%c;%d", nomeJogador, &posicao, &forca);

        strcpy(time[i].nome, nomeJogador);
        time[i].posicao = posicao;
        time[i].forca = forca;
    }
}

double calcular_pontuacao(Jogador time[11]) {
    int pontuacao = 0;
    for (int i = 0; i < 11; i++) {
        switch (time[i].posicao) {
            case 'G':
                pontuacao += 8 * time[i].forca;
                break;
            case 'L':
                pontuacao += 10 * time[i].forca;
                break;
            case 'Z':
                pontuacao += 5 * time[i].forca;
                break;
            case 'V':
                pontuacao += 8 * time[i].forca;
                break;
            case 'M':
                pontuacao += 11 * time[i].forca;
                break;
            case 'A':
                pontuacao += 12 * time[i].forca;
                break;
        }
    }
    return pontuacao / 100.0;
}

void imprimir_resultado(char nomeTime1[31], double pontuacaoTime1, char nomeTime2[31], double pontuacaoTime2) {
    printf("%s: %.2lf de forca\n", nomeTime1, pontuacaoTime1);
    printf("%s: %.2lf de forca\n", nomeTime2, pontuacaoTime2);

    if (pontuacaoTime1 > pontuacaoTime2) {
        printf("%s eh mais forte\n", nomeTime1);
    } else  {
        printf("%s eh mais forte\n", nomeTime2);
    } 
}

int main() {
    Jogador time1[11];
    Jogador time2[11];
    char nomeTime1[31];
    char nomeTime2[31];

    fgets(nomeTime1, sizeof(nomeTime1), stdin);
    nomeTime1[strcspn(nomeTime1, "\n")] = '\0';
    ler_time(time1);

    fgets(nomeTime2, sizeof(nomeTime2), stdin);
    nomeTime2[strcspn(nomeTime2, "\n")] = '\0';
    ler_time(time2);

    double pontuacaoTime1 = calcular_pontuacao(time1);
    double pontuacaoTime2 = calcular_pontuacao(time2);

    imprimir_resultado(nomeTime1, pontuacaoTime1, nomeTime2, pontuacaoTime2);

    return 0;
}
