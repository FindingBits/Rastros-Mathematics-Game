//
// Created by João Guedes on 10/03/2020.
//
#include "dados.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
int podeJogar(ESTADO *e, COORDENADA c){
    //printf("\nNavegador: %c, l+1: %d, l-1: %d, c+1: %d, c-1: %d\n",e->tab[c.linha][c.coluna],e->tab[c.linha+1][c.coluna],e->tab[c.linha-1][c.coluna],e->tab[c.linha][c.coluna+1],e->tab[c.linha][c.coluna-1]);
    if(e->tab[c.linha][c.coluna]=='#') return 0;
    if(e->tab[c.linha][c.coluna]!=0) return 0;
    if(((abs(e->ultima_jogada.linha-c.linha)==1)&&(abs(e->ultima_jogada.coluna-c.coluna)==1)) ||
    ((abs(e->ultima_jogada.linha-c.linha)==0)&&(abs(e->ultima_jogada.coluna-c.coluna)==1)) ||
    ((abs(e->ultima_jogada.linha-c.linha)==1)&&(abs(e->ultima_jogada.coluna-c.coluna)==0))){
        if(e->tab[c.linha][c.coluna]==0){
            printf("\nAutorizou jogada!");
            return 1;
        }
    }
    return 0;
}
int updateJogadas(ESTADO *e, COORDENADA c){
    COORDENADA toDo;
    COORDENADA blank;
    blank.linha=0;
    blank.coluna=0;
    toDo.linha=c.linha;
    toDo.coluna=c.coluna;
    e->ultima_jogada.linha=toDo.linha;
    e->ultima_jogada.coluna=toDo.coluna;
    if(e->jogador_atual==1){
        e->jogadas[e->num_jogadas].jogador1=toDo;
        e->jogadas[e->num_jogadas].jogador2=blank;
        return 1;
    }else if(e->jogador_atual==2){
        e->jogadas[e->num_jogadas].jogador1=blank;
        e->jogadas[e->num_jogadas].jogador2=toDo;
        return 1;
    }
    return 0;
}

int jogar(ESTADO *e, COORDENADA c){
    c.coluna=c.coluna+1;
    printf("Foi tentada uma jogada nas coordenadas: \nLinha:%d\nColuna:%d",c.linha,c.coluna);
    printf("\n%d\n",podeJogar(e,c));
    if((c.linha>=0 && c.linha<=9) && (c.coluna>=0 && c.coluna<=9)  && podeJogar(e,c)){
        if(e->jogador_atual==1){
            e->tab[c.linha][c.coluna] = 1;
        }else if (e->jogador_atual==2){
            e->tab[c.linha][c.coluna] = 2;
        }else return 1;
        if(updateJogadas(e,c)) printf("\nAtualizou jogada!\n");
        else printf("\nNão Atualizou jogada!\n");
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

void jogarAuto(ESTADO *e){
    // jog 1 algoritmo simples de escolha de posicao aleatoria forcada sem inteligencia
    COORDENADA blank;
    blank.linha=e->ultima_jogada.linha;
    blank.coluna=e->ultima_jogada.coluna-1;
    int r=0;
    while(1){
        if(r==0){
            blank.coluna=blank.coluna-1;
            if(blank.coluna>=0 && blank.linha>=0){if(jogar(e,blank)) break;}
        }else if(r==1){
            blank.linha=blank.linha+1;
            if(blank.coluna>=0 && blank.linha>=0){if(jogar(e,blank)) break;}
        }else if(r==2){
            blank.coluna=blank.coluna+1;
            if(blank.coluna>=0 && blank.linha>=0){if(jogar(e,blank)) break;}
        }else if(r==3){
            blank.linha=blank.linha-1;
            if(blank.coluna>=0 && blank.linha>=0){if(jogar(e,blank)) break;}
        }
        r++;
        if(r==5) {printf("Erro na jogada auto!\n");break;}
    }
}
void jogarAutoAdv(ESTADO *e){
    int ci,di,es,ba,i,j,tab[9][9];
    COORDENADA c;
    // inicio seria sempre na casa mae de partida
    // verifica desde o canto ate a casa mae para jogar
        //minimax(profundidade max,caminho,linha,coluna,copia da tabela);
        for(i=0;i<8;i++){
            for(j=1;j<9;j++){
                tab[i][j]=e->tab[i][j];
            }
        }
       ci= minimax(16,0,e->ultima_jogada.linha-1,e->ultima_jogada.coluna,tab,e);
       di= minimax(16,0,e->ultima_jogada.linha,e->ultima_jogada.coluna+1,tab,e);
       es= minimax(16,0,e->ultima_jogada.linha,e->ultima_jogada.coluna-1,tab,e);
       ba= minimax(16,0,e->ultima_jogada.linha+1,e->ultima_jogada.coluna,tab,e);
       printf("ci %d",ci);
    printf("di %d",di);
    printf("es %d",es);
    printf("ba %d",ba);
    if(ci!=-1 && ci<di && ci<es && ci<ba) {
        //cima
        c.coluna=e->ultima_jogada.coluna;
        c.linha=e->ultima_jogada.linha-1;
        jogar(e,c);
    }
    else if(di!=-1 && di<es && di<ba){
        //direita
        c.coluna=e->ultima_jogada.coluna+1;
        c.linha=e->ultima_jogada.linha;
        jogar(e,c);
    }
    else if(es!=-1 && es<ba){
        //esquerda
        c.coluna=e->ultima_jogada.coluna-1;
        c.linha=e->ultima_jogada.linha;
        jogar(e,c);
    }
    else {
        //baixo
        if(ba==-1) return;
        c.coluna=e->ultima_jogada.coluna-1;
        c.linha=e->ultima_jogada.linha+1;
        printf("c.coluna%d c.linha%d\n",c.coluna,c.linha);
        jogar(e,c);

    }
}

int minimax(int profundidade, int caminho, int linha, int coluna, int tab[9][9],ESTADO *e) {
        int ci,di,es,ba;
        if(profundidade==0) return -1;
        if(e->jogador_atual==1){
            if(linha==0 && coluna==8) return caminho;
        }
    if(e->jogador_atual==2){
        if(linha==7 && coluna==0) return caminho;
    }
        if(linha>7 || linha<0 || coluna>8 || coluna<0) return -1;
        if(tab[linha][coluna]!=0) return -1;
        tab[linha][coluna]=e->jogador_atual;
        ci= minimax(profundidade-1,caminho+1,e->ultima_jogada.linha-1,e->ultima_jogada.coluna,tab,e);
        di= minimax(profundidade-1,caminho+1,e->ultima_jogada.linha,e->ultima_jogada.coluna+1,tab,e);
        es= minimax(profundidade-1,caminho+1,e->ultima_jogada.linha,e->ultima_jogada.coluna-1,tab,e);
        ba= minimax(profundidade-1,caminho+1,e->ultima_jogada.linha+1,e->ultima_jogada.coluna,tab,e);
        if(ci!=-1 && ci<di && ci<es && ci<ba) return ci;
        else if(di!=-1 && di<es && di<ba) return di;
        else if(es!=-1 && es<ba) return es;
        else return ba;
}
