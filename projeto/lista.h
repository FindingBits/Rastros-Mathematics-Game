//
// Created by João Guedes on 19/04/2020.
//
#include "dados.h"
#ifndef JOGO_node_H
#define JOGO_node_H
#define NULL ( (void *) 0)
// Cria uma node vazia
node criar_node();
// Insere um valor na cabeça da node
node insere_cabeca(node * head, int valor);
// Devolve a cabeça da node
void *devolve_cabeca(node * head);
// Devolve a cauda da node
node proximo(node * head);
// Remove a cabeça da node (libertando o espaço ocupado) e devolve a cauda
node remove_cabeca(node ** head);
// Devolve verdareiro se a node é vazia
int node_esta_vazia(node * head);

#endif //JOGO_node_H
