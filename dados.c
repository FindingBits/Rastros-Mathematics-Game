#include <stdio.h>

int jogador_atual(){

    return 0;
}

int main(int argc, char **argv){
    jogador_atual();
    int player=0;
    int turn;
    int noturns;

    for(noturns=0;noturns<15;noturns++)
    {
        for(turn=0;turn<15;turn++)
        {
            for(turn=0;turn<2;turn++) {

                player = !player;
                printf("Turn nº%d.player: %d\n", noturns, player);
            }
        }
    }
    return 0;
}