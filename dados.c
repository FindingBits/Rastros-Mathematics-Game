#include <stdio.h>
#include "interface.h"
#include "logica.h"

ESTADO *inicializar_estado(){
	ESTADO * novo;
	

	//reset jogador atual
	novo->jogador_atual = 1;
			
	return novo;
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
