#include <stdio.h>
#include <stdlib.h>
#include "dados.h"


ESTADO *inicializar_estado(){
    // Função que deve ser completada e colocada na camada de dados
        ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
        e->jogador_atual = 1;
        e->num_jogadas = 0;
        COORDENADA inicial;
        inicial.linha = 3;
        inicial.coluna = 4;
        e->passouBordas=0;
        e->ultima_jogada = inicial;
        for(int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                e->tab[i][j] = 0;
            }
        }
        e->tab[inicial.linha][inicial.coluna]='#';
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

// Cria uma lista vazia
struct LISTA criar_lista();
// Insere um valor na cabeça da lista
struct LISTA insere_cabeca(struct LISTA L, void *valor);
// Devolve a cabeça da lista
void *devolve_cabeca(struct LISTA L);
// Devolve a cauda da lista
struct LISTA proximo(struct LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
struct LISTA remove_cabeca(struct LISTA L);
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(struct LISTA L);