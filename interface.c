//
// Created by João Carvalho on 10/03/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "logica.h"
#define BUF_SIZE 1024

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    //menu
    if(entrada()){
        mostrar_tabuleiro(e);
        printf("coordenas disponiveis: coluna: a-h, linha: 0-7\n");
        printf("Insira as coordenadas:\n");

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

}

int entrada() {

    int x, y;
    char buff[15];

    printf("Bem vindo ao jogo rastos\n\n\n");
    printf("1-Jogar  2-Informacao 3-Sair\n");

    printf("opcao:");
    fgets(buff, 15, stdin);
    x = atoi(buff);

    if (x == 1) {

        printf("1-jogador numero um   2-jogador numero dois   3-sair\n");
        printf("Escolha o seu numero de jogador:");
        fgets(buff, 15, stdin);
        y = atoi(buff);

        //escolher jogador
        if (y == 1) {
            printf("escolheu o jogador 1\n");
            printf("o outro jogador e o numero 2\n");

        } else if (y == 2) {
            printf("escolheu o jogador 2\n");
            printf("o outro jogador e o numero 1\n");

        }else{
            printf("invalido\n");
            entrada();
        }

        //informação
    }else if (x == 2) {
        printf("created by Joao Carvalho, Joao Guedes, Miguel Tavares in 2020.\n");
        printf("Este jogo foi realiazado no ambito da disciplina de laboratorios de algoritmia.\n");
        return 0;
        //sair do jogo
    } else if (x == 3) {
        printf("\nSaida!\n");
        return 0;
    }else{
        printf("\nEsse valor nao e valido.\nTente novamente.\n");
        return 0;
    }
    return 1;
}


// Função que deve ser completada e colocada na camada de interface
void mostrar_tabuleiro (ESTADO *e) {
    putchar('\n');
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //se estivermos na primeira casa da linha
            if(j==0){
                printf( "%d| ", 7-i);

                if(e->tab[7-i][j] == 1){
                    printf( "%c | ", '@');
                }else if(e->tab[7-i][j] == 2){
                    printf( "%c | ", 'O');
                }else{
                    printf( "%c | ", '_');
                }
            }else{
                if(e->tab[7-i][j] == 1){
                    printf( "%c | ", '@');
                }else if(e->tab[7-i][j] == 2){
                    printf( "%c | ", 'O');
                }else{
                    printf( "%c | ", '_');
                }
            }
        }

        putchar('\n');
    }
    printf( "   a   b   c   d   e   f   g   h");
    putchar('\n');
}



void fim(int x){
    if(x==1){
        printf("vencedor:jogador 1");
    }
    else if(x==2){
        printf("vencedor:jogador 2");
    }

}
