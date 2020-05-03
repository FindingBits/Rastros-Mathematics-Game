//
// Created by Guedes on 03/05/2020.
//

#include "play.h"
#include <stdlib.h>
int podeJogar(ESTADO *e, COORDENADA c){
    if(e->tab[c.linha][c.coluna]=='#') return 0;
    if(e->tab[c.linha][c.coluna]!='.') return 0;
    if((abs(e->ultima_jogada.linha-c.linha)==1)||(abs(e->ultima_jogada.coluna-c.coluna)==1)){
        if(e->tab[c.linha][c.coluna]==0){
            return 1;
        }
    }else return 0;
}
int jogar(ESTADO *e, COORDENADA c){
    if((c.linha>0 && c.linha<=9) && (c.coluna>0 && c.coluna<=9)){
        if(e->jogador_atual==1){
            e->tab[c.linha][c.coluna] = 1;
        }else if (e->jogador_atual==2){
            e->tab[c.linha][c.coluna] = 2;
        }else return 1;
        e->num_jogadas += 1;
        if(podeJogar(e,c)){
            if(e->jogador_atual ==1 ){
                e->jogador_atual = 2;
            }else{
                e->jogador_atual=1;
            }
        }
    }else{
        return 0;
    }
    return 1;
}
