#include <stdio.h>
#include <string.h>
#include "interface.h"

int main() {
    ESTADO *e = inicializar_estado();
    if (entrada(e)) {
        mostrar_tabuleiro(e);
        pedir_entrada(e);
        while(1) {
            printf("# %d PL%d (%d)>",(e->num_jogadas+1),e->jogador_atual,e->num_jogadas);
            interpretador(e);
        }
    }else{
        return 0;
    }
}
