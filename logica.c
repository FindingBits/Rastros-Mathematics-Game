//
// Created by João Guedes on 10/03/2020.
//

#include "dados.h"
#include <stdio.h>
#include <string.h>
int podeJogar(ESTADO *e, COORDENADA c){
    if(/* branca */c.coluna+1==1 || c.coluna-1==1 || c.linha+1==1 || c.linha-1==1){
        printf("\nDeteta Branca");
        return 0;
    }else if(/* preta */ c.linha+1==2 || c.linha-1==2 || c.coluna+1==2 || c.coluna-1==2){
        printf("\nDeteta Preta");
        return 0;
    }else return 1;
}

int jogar(ESTADO *e, COORDENADA c){
    printf("Foi tentada uma jogada nas coordenadas: \nLinha:%d\nColuna:%d",c.linha,c.coluna);
    if((c.linha>=0 && c.linha<8) && (c.coluna>=0 && c.coluna<8) && (e->tab[c.linha][c.coluna]==0) && podeJogar(e,c)){
        e->tab[c.linha][c.coluna] = 1; //branca
        e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = 2; //preta
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
