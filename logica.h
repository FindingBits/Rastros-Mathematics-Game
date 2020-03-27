//
// Created by João Guedes on 10/03/2020.
//
/**
@file logica.h
Definição do estado e das funções que o manipulam
*/
#ifndef GUIAO5_LOGICA_H
#define GUIAO5_LOGICA_H
/**
\brief Função para jogar no tabuleiro
*/
int jogar(ESTADO *estado, COORDENADA c);
/**
\brief Função para saber se pode jogar no tabuleiro na posição escolhida
*/
int podeJogar(ESTADO *e);
/**
\brief Função para atualizar jogadas
*/
int updateJogadas(ESTADO *e, COORDENADA c);
#endif //GUIAO5_LOGICA_H