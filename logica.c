//
// Created by João Guedes on 10/03/2020.
//
int passouCasaMeio=0;
#include "dados.h"
#include <stdio.h>
#include <string.h>
int podeJogar(ESTADO *e, COORDENADA c){
    printf("\nNavegador: %c, l+1: %d, l-1: %d, c+1: %d, c-1: %d\n",e->tab[c.linha][c.coluna],e->tab[c.linha+1][c.coluna],e->tab[c.linha-1][c.coluna],e->tab[c.linha][c.coluna+1],e->tab[c.linha][c.coluna-1]);
    if(/* branca */(e->tab[c.linha+1][c.coluna]==1 || e->tab[c.linha-1][c.coluna]==1 || e->tab[c.linha][c.coluna+1]==1 || e->tab[c.linha][c.coluna-1]==1 || e->tab[c.linha+1][c.coluna]=='#' || e->tab[c.linha-1][c.coluna]=='#' || e->tab[c.linha][c.coluna+1]=='#' || e->tab[c.linha][c.coluna-1]=='#')){
        //printf("\naqui\n");
        if((e->tab[c.linha+1][c.coluna]=='#' || e->tab[c.linha-1][c.coluna]=='#' || e->tab[c.linha][c.coluna+1]=='#' || e->tab[c.linha][c.coluna-1]=='#')&& passouCasaMeio>0){ return 0; }
        passouCasaMeio++;
        if(e->tab[c.linha][c.coluna]==0){
            //printf("\naqui 2\n");
            printf("\nDeteta Branca");
            return 1;
        }
    }else if(/* preta */(e->tab[c.linha+1][c.coluna]==2 || e->tab[c.linha-1][c.coluna]==2 || e->tab[c.linha][c.coluna+1]==2 || e->tab[c.linha][c.coluna-1]==2 || e->tab[c.linha+1][c.coluna]=='#' || e->tab[c.linha-1][c.coluna]=='#' || e->tab[c.linha][c.coluna+1]=='#' || e->tab[c.linha][c.coluna-1]=='#') /*|| diagonais (c.linha+1==2 && c.coluna+1==2) ||(c.linha-1==2 && c.coluna-1==2) ||(c.linha-1==2 && c.coluna+1==2)||(c.linha+1==2 && c.coluna-1==2)*/){
        //printf("\naqui\n");
        if((e->tab[c.linha+1][c.coluna]=='#' || e->tab[c.linha-1][c.coluna]=='#' || e->tab[c.linha][c.coluna+1]=='#' || e->tab[c.linha][c.coluna-1]=='#')&& passouCasaMeio>0){ return 0; }
        passouCasaMeio++;
        if( e->tab[c.linha][c.coluna]==0){
            //printf("\naqui 2\n");
            printf("\nDeteta Preta");
            return 1;
        }
    }else return 0;
}

int jogar(ESTADO *e, COORDENADA c){
    c.coluna=c.coluna+1;
    printf("Foi tentada uma jogada nas coordenadas: \nLinha:%d\nColuna:%d",c.linha,c.coluna);
    if((c.linha>=0 && c.linha<8) && (c.coluna>=0 && c.coluna<8)  && podeJogar(e,c)){
        if(e->jogador_atual==1){
            e->tab[c.linha][c.coluna] = 1;
        }else if (e->jogador_atual==2){
            e->tab[c.linha][c.coluna] = 2;
        }else return 1;
        e->num_jogadas += 1;
        // troca jogador
        if(e->jogador_atual ==1 ){
            e->jogador_atual = 2;
        }else{
            e->jogador_atual=1;
        }
    }else{
        printf("\nJogada invalida!");
        return 0;
    }
    return 1;
}
