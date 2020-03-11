#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
int main() {
    int x;
    entrada();
    ESTADO *e = inicializar_estado();
    interpretador(e);
    while(?){
        jogar(?);
    }
    fim(x);
    return 0;
}
