//
// Created by Miguel on 10/03/2020.
//

#include <stdio.h>

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




#ifndef ALGORITMIA_DADOS_H
#define ALGORITMIA_DADOS_H

#endif //ALGORITMIA_DADOS_H

int jogador_atual();
