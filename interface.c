//
// Created by João Carvalho on 10/03/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "logica.h"
#define BUF_SIZE 1024

int interpretador(ESTADO *e) {
            char linha[BUF_SIZE];
            char col[2], lin[2];
            if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
            if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
                COORDENADA coord = {*col - 'a', *lin - '1'};
                jogar(e, coord);
                mostrar_tabuleiro(e);
            }
            else if(strlen(linha) == 5 ){
                int i;
                printf("Movimentos:\n");
                for(i=0;i<obter_numero_de_jogadas(e);i++) {
                    if (e->jogador_atual = 1) {
                        if (e->jogadas[i].jogador1.linha != 0 && e->jogadas[i].jogador1.linha != 0) {
                            printf("##Player1 (%d,%d)\n", (e->jogadas[i].jogador1.linha+1),
                                   (e->jogadas[i].jogador1.coluna));
                        } else if (e->jogadas[i].jogador2.linha != 0 && e->jogadas[i].jogador2.linha != 0) {
                            printf("##Player2 (%d,%d)\n", (e->jogadas[i].jogador2.linha+1),
                                   (e->jogadas[i].jogador2.coluna));
                        }
                    } else if (e->jogador_atual = 2) {
                        if (e->jogadas[i].jogador2.linha != 0 && e->jogadas[i].jogador2.linha != 0) {
                            printf("##Player2 (%d,%d)\n", (e->jogadas[i].jogador2.linha+1),
                                   (e->jogadas[i].jogador2.coluna));
                        } else if (e->jogadas[i].jogador1.linha != 0 && e->jogadas[i].jogador1.linha != 0) {
                            printf("##Player1 (%d,%d)\n", (e->jogadas[i].jogador1.linha+1),
                                   (e->jogadas[i].jogador1.coluna));
                        }
                    }
                }
            }
            else if(strcmp(linha,"gr")==0){

            }
            else if(strcmp(linha,"ler")==0){

            }
            return 1;
    }

int entrada(ESTADO *e) {
    int x, y,z;
    printf("Bem vindo ao jogo rastos\n\n\n");
    printf("1-Jogar  2-Informacao  3-Sair\n");
    printf("opcao:");
    scanf("%d",&x);
    if (x == 1) {
        printf("1-jogador numero um   2-jogador numero dois\n");
        printf("Escolha o seu numero de jogador:");
        scanf("%d",&y);
        if (y == 1) {
            printf("escolheu o jogador 1\n");
            printf("o outro jogador e o numero 2\n");
            e->jogador_atual=1;
        }
        else if (y == 2) {
            printf("escolheu o jogador 2\n");
            printf("o outro jogador e o numero 1\n");
            e->jogador_atual=2;
        }
        else{
            printf("invalido\n");
            entrada(e);
        }
    }
    else if (x == 2) {
        printf("created by Joao Carvalho, Joao Guedes, Miguel Tavares in 2020.\n");
        printf("Este jogo foi realiazado no ambito da disciplina de laboratorios de algoritmia.\n\n");
        printf("1-voltar ao menu   2-sair do jogo\n");
        printf("opcao:");
        scanf("%d",&z);
        if(z==1){
            entrada(e);
        }
        else if(z==2) {
            printf("\nObrigado por ter jogado!");
            return 0;
        }
        else{
            printf("invalido!\n");
            entrada(e);
        }
    }
    else if (x == 3) {
        printf("\nObrigado por ter jogado!\n");
        return 0;
    }
    else{
        printf("\nEsse valor nao e valido.\nTente novamente.\n");
        entrada(e);
    }
    return 1;
}


void mostrar_tabuleiro (ESTADO *e) {
    int win=0;
    putchar('\n');
    printf( "    a   b   c   d   e   f   g   h\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<=8;j++){
            //se estivermos na primeira casa da linha
            if(j==8 && i==0){
                printf( "%d | ", 2);
                if(e->tab[i][j]==1) win=1;
            }else if(j==1 && i==7){
                printf( "%d | ", 1);
                if(e->tab[i][j]==2) win=2;
            }

            else if(j==0) printf("%d | ",i+1);
            else if(j>0 && e->tab[i][j] == 1){
                printf( "%c | ", 'O');
            }
            else if(j>0 && e->tab[i][j] == 2){
                printf( "%c | ", '@');
            }else if(j>0 && e->tab[i][j] == 35){
                printf( "%c | ", '#');
            }else{
                printf( "%c | ", '_');
            }
        }
        putchar('\n');
    }
    putchar('\n');
    if(win){ fim(win);}
}



int fim(int x){
    if(x==1){
        printf("vencedor:jogador 1");
    }
    else if(x==2){
        printf("vencedor:jogador 2");
    }
    exit(0);
    return 0;
}

void pedir_entrada(ESTADO *e) {
    printf("# %d PL%d (%d)>", (e->num_jogadas + 1), e->jogador_atual, e->num_jogadas);
    scanf("%d", &e);
    interpretador(e);
}
