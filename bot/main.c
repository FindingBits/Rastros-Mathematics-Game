#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "play.h"


ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    COORDENADA inicial;
    inicial.linha = 3;
    inicial.coluna = 4;
    e->ultima_jogada = inicial;
    for(int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            e->tab[i][j] = 0;
        }
    }
    e->tab[inicial.linha][inicial.coluna]='#';
    return e;
}
int main() {
    ESTADO *e = inicializar_estado();
    COORDENADA blank;
    blank.linha=e->ultima_jogada.linha;
    blank.coluna=e->ultima_jogada.coluna-1;
    if(7-blank.coluna>7-blank.linha){
        blank.coluna=blank.coluna+1;
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){}}
    }else if(7-blank.coluna<7-blank.linha){
        blank.linha=blank.linha+1;
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){{}}}
    }else/* igualdade*/{
        blank.coluna=blank.coluna-1;
        if(blank.coluna>0 && blank.linha>0){if(jogar(e,blank)){}else{blank.linha=blank.linha-1;}if(jogar(e,blank)){} }
    }
    return 0;
}
