#include <stdio.h>
#include <string.h>
#include "interface.h"
int main() {
    entrada();
    pedir_entrada();
    ESTADO *e = inicializar_estado();
    interpretador(e);
    fim();
    return 0;
}
