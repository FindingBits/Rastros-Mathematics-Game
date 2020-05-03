typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32]; //32 pares de coordenadas
typedef struct {
    CASA tab[9][9]; // indice e casas do jogo expandidos
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas; // valor inicial = 0 jogadas
    int jogador_atual;
    int passouBordas;
}ESTADO;
    // valor inicial = 1
typedef struct LISTA { 
    int data; 
    struct LISTA *next; 
}node; // definiçao de LISTA
#ifndef GUIAO5_DADOS_H
#define GUIAO5_DADOS_H

#endif //GUIAO5_DADOS_H
ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
int obter_estado_casa(ESTADO *e, COORDENADA c);
COORDENADA obter_ultima_jogada(ESTADO *e);
int minimax(int profundidade, int caminho, int linha, int coluna, int tab[9][9],ESTADO *e);

