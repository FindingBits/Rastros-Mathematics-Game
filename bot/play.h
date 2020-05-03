//
// Created by Guedes on 03/05/2020.
//

#ifndef BOT_PLAY_H
#define BOT_PLAY_H
typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32]; //32 pares de coordenadas
typedef struct {
    CASA tab[9][9]; // indice e casas do jogo expandidos
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas; // valor inicial = 0 jogadas
    int jogador_atual;
}ESTADO;

int jogar(ESTADO *estado, COORDENADA c);
int podeJogar(ESTADO *e, COORDENADA c);
#endif //BOT_PLAY_H
