//
// Created by João Guedes on 10/03/2020.
//
int passouCasaMeio=0;
#include "dados.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
int podeJogar(ESTADO *e, COORDENADA c){
    //printf("\nNavegador: %c, l+1: %d, l-1: %d, c+1: %d, c-1: %d\n",e->tab[c.linha][c.coluna],e->tab[c.linha+1][c.coluna],e->tab[c.linha-1][c.coluna],e->tab[c.linha][c.coluna+1],e->tab[c.linha][c.coluna-1]);
    if(e->tab[c.linha][c.coluna]=='#') return 0;
    if(e->tab[c.linha][c.coluna]==1 || e->tab[c.linha][c.coluna]==2){}else{if(e->tab[c.linha][c.coluna]!=0) return 0;}
    if(/* branca e preta (logica bivalente) */(abs(e->ultima_jogada.linha-c.linha)==1)||(abs(e->ultima_jogada.coluna-c.coluna)==1)){
        if(e->tab[c.linha][c.coluna]==0){
            printf("\nAutorizou jogada!");
            return 1;
        }
    }else return 0;
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
    if((c.linha>0 && c.linha<=9) && (c.coluna>0 && c.coluna<=9)  && podeJogar(e,c)){
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
    // jog 2 Minimax baseado no calculo de menor distancia possivel
    COORDENADA blank;
    blank.linha=e->ultima_jogada.linha;
    blank.coluna=e->ultima_jogada.coluna-1;
    if(7-blank.coluna>7-blank.linha){
        blank.coluna=blank.coluna+1;
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){{}}}
    }if(7-blank.coluna<7-blank.linha){
        blank.linha=blank.linha+1;
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){{}}}
    }else/* igualdade*/{
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){}else{blank.linha=blank.linha-1;}if(jogar(e,blank)){printf("Jogou!\n");}else{jogarAuto(e);} }
    }
}
