//
// Created by João Carvalho on 10/03/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <string.h>
#define BUF_SIZE 1024


void entrada(){
int x,y;
printf("Bem vindo ao jogo rastos\n\n\n");
printf("1-Jogar  2-Informacao\n");
printf("opcao:");
scanf("%d",&x);
if(x==1){
printf("1-jogador numero um   2-jogador numero dois   3-sair\n");
printf("Escolha o seu numero de jogador:");
scanf("%d",&y);
if(y==1){
printf("escolheu o jogador 1\n");
printf("o outro jogador e o numero 2\n");

}
else if(y==2){
printf("escolheu o jogador 2\n");
printf("o outro jogador e o numero 1\n");
}

}
else if(x==2){
printf("created by Joao Carvalho, Joao Guedes, Miguel Tavares in 2020.\n");
printf("Este jogo foi realiazado no ambito da disciplina de laboratorios de algoritmia.\n");

}
}


// Função que deve ser completada e colocada na camada da lógica do programa
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}
// Função que deve ser completada e colocada na camada de interface
void mostrar_tabuleiro (ESTADO *e) {
}
// Função que deve ser completada e colocada na camada de dados ESTADO
*inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    // Falta a resto da inicialização.
     return e;
}
// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
