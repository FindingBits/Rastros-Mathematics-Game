#include <stdio.h>
#include <stdlib.h>
#include "header.h"


ESTADO *inicializar_estado(){
    // Função que deve ser completada e colocada na camada de dados
        ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
        e->jogador_atual = 1;
        e->num_jogadas = 0;
        for(int i=0;i<8;i++) {
            for (int j = 0; j < 8; j++) {
                e->tab[i][j] = 0;
            }
        }
// Falta a resto da inicialização.
        return e;
    }

int obter_jogador_atual(ESTADO *estado){
	
	
	return estado->jogador_atual;


}

int obter_numero_de_jogadas(ESTADO *estado){

	return estado->num_jogadas;
}

int obter_estado_casa(ESTADO *e, COORDENADA c){

	return e->tab[c.linha][c.coluna];

}
