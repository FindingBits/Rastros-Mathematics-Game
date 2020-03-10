//
// Created by João Guedes on 10/03/2020.
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
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;
#ifndef GUIAO5_LOGICA_H
#define GUIAO5_LOGICA_H

#endif //GUIAO5_LOGICA_H
int jogar(ESTADO *estado, COORDENADA c);
