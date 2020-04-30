//
// Created by João Carvalho on 10/03/2020.
//

/**
@file interface.h
Definição do estado e das funções que o manipulam
*/
#include "dados.h"
#include "logica.h"
#ifndef JOGO_INTERFACE_H
#define JOGO_INTERFACE_H

#endif //JOGO_INTERFACE_H

/**
\brief Tipo de interface para mostrar o tabuleiro
*/
void mostrar_tabuleiro (ESTADO *e);
/**
\brief Tipo de interface para mostrar o menu
*/
int entrada(ESTADO *e);
/**
\brief Tipo de interface para receber as coordenadas
*/
void pedir_entrada(ESTADO *e);
/**
\brief Tipo de interface que le as jogadas e mostra essas jogadas no tabuleiro
*/
int interpretador(ESTADO *e);
/**
\brief Tipo de interface para mostrar quem e o vencedor
*/
int fim(int x);
