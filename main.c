#include <stdio.h>
#include <string.h>
#include "interface.h"

int main() {
    if (entrada()) {
        ESTADO *e = inicializar_estado();
        mostrar_tabuleiro(e);
        pedir_entrada();
        while(1) {
            printf("coordenas disponiveis: coluna: a-h, linha: 0-7\n");
            printf("Insira as coordenadas:");
            interpretador(e);
        }
    }else{
        return 0;
    }
}
