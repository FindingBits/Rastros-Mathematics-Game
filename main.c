#include <stdio.h>
#include <string.h>
#include "interface.h"

int main() {
    if (entrada()) {
        ESTADO *e = inicializar_estado();
        pedir_entrada();
        interpretador(e);
    }
    else {
        return 0;
    }
}
