//to test
// Created by Miguel on 12/03/2020.
//
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
    CASA tab[8][8]; // 64 celulas do tabuleiro, indice e casas do jogo
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas; // valor inicial = 0 jogadas
    int jogador_atual; // valor inicial = 1
} ESTADO;
#ifndef JOGO_HEADER_H
#define JOGO_HEADER_H

#endif //JOGO_HEADER_H

void mostrar_tabuleiro (ESTADO *e);
void entrada();
int interpretador(ESTADO *e);
void fim(int x);
int jogar(ESTADO *estado, COORDENADA c);
ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
int obter_estado_casa(ESTADO *e, COORDENADA c);

