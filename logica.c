//
// Created by João Guedes on 10/03/2020.
//

#include "logica.h"
#include <stdio.h>

int jogar(ESTADO *estado, COORDENADA c){
    printf("Foi tentada uma jogada as coordenadas: \nLinha:%d\nColuna:%d",c.linha,c.coluna);
    if((c.linha>=0 && c.linha<8) && (c.coluna>=0 && c.coluna<8)){
        estado->num_jogadas+=1;
    }else{
        printf("Jogada invalida!");
        return 0;
    }
    return 1;
}
