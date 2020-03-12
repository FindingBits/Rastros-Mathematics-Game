#include <stdio.h>
#include <string.h>
#include "interface.h"

int main()
{
    ESTADO *e = inicializar_estado();

    interpretador(e);


    return 0;
}
