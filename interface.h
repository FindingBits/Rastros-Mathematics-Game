//
// Created by João Carvalho on 10/03/2020.
//

#ifndef JOGO_INTERFACE_H
#define JOGO_INTERFACE_H

#endif //JOGO_INTERFACE_H
// Estruturas de dados (devem ser colocadas no módulo correto da camada dos dados)
typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna,linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;


void mostrar_tabuleiro (ESTADO *e);
void entrada();
void pedir_entrada();
int interpretador(ESTADO *e);
void fim(int x);
