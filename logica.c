//
// Created by João Guedes on 10/03/2020.
//

#include "interface.h"
#include "logica.h"
#include <stdio.h>
#include <string.h>

int jogar(ESTADO *estado, COORDENADA c){
    printf("Foi tentada uma jogada as coordenadas: \nLinha:%d\nColuna:%d",c.linha,c.coluna);
    if((c.linha>=0 && c.linha<8) && (c.coluna>=0 && c.coluna<8) && estado->tab[c.linha][c.coluna]!=PRETA && estado->tab[c.linha][c.coluna]!='.'){
        estado->tab[c.linha][c.coluna]=PRETA;
        //strcpy(estado->jogadas[estado->num_jogadas],"PRETA");
        estado->num_jogadas+=1;
        if(estado->jogador_atual==1) estado->jogador_atual=2;
        else estado->jogador_atual=1;
    }else{
        printf("Jogada invalida!");
        return 0;
    }
    return 1;
}
