#include <stdio.h>
#include <string.h>
#include "interface.h"

void update_file(ESTADO *e){
    FILE *fp;
    fp=fopen("\\file.txt", "w+");
    fprintf(fp, "\n    a   b   c   d   e   f   g   h\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<=8;j++){
            //se estivermos na primeira casa da linha
            if(j==8 && i==0){
                fprintf(fp, "%d | ", 2);
            }else if(j==1 && i==7){
                fprintf(fp, "%d | ", 1);
            }
            else if(j==0) fprintf(fp,"%d | ",i+1);
            else if(j>0 && e->tab[i][j] == 1){
                fprintf(fp, "%c | ", 'O');
            }
            else if(j>0 && e->tab[i][j] == 2){
                fprintf(fp, "%c | ", '@');
            }else if(j>0 && e->tab[i][j] == 35){
                fprintf(fp, "%c | ", '#');
            }else{
                fprintf(fp, "%c | ", '_');
            }
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n");
    fclose(fp);
}
int main() {
    ESTADO *e = inicializar_estado();
    if (entrada(e)) {
        mostrar_tabuleiro(e);
        pedir_entrada(e);
        while(1) {
            printf("# %d PL%d (%d)>",(e->num_jogadas+1),e->jogador_atual,e->num_jogadas);
            interpretador(e);
            update_file(e);
        }
    }else{
        return 0;
    }
}
