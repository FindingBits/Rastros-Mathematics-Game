//
// Created by João Carvalho on 10/03/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "logica.h"
#define BUF_SIZE 1024

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    } else if (strcmp(linha, "movs\n") == 0) {
        int i;
        printf("Movimentos:\n");
        for (i = 0; i < obter_numero_de_jogadas(e); i++) {
            if (e->jogador_atual == 1) {
                if (e->jogadas[i].jogador1.linha != 0) {
                    printf("Player1 (%d,%d)\n", (e->jogadas[i].jogador1.coluna),(e->jogadas[i].jogador1.linha + 1));

                } else if (e->jogadas[i].jogador2.linha != 0) {
                    printf("Player2 (%d,%d)\n", (e->jogadas[i].jogador2.coluna),(e->jogadas[i].jogador2.linha + 1));
                }
            } else if (e->jogador_atual == 2) {
                if (e->jogadas[i].jogador2.linha != 0) {
                    printf("Player2 (%d,%d)\n", (e->jogadas[i].jogador2.coluna),(e->jogadas[i].jogador2.linha + 1));
                } else if (e->jogadas[i].jogador1.linha != 0) {
                    printf("Player1 (%d,%d)\n", (e->jogadas[i].jogador1.coluna),(e->jogadas[i].jogador1.linha + 1));
                }
            }
        }
    } else if (strcmp(linha, "gr\n") == 0) {
        FILE *fp;
        fp = fopen("file.txt", "w+");
        fputs("\n- Utimo Tabuleiro -\n", fp);
        fputs("\n    a   b   c   d   e   f   g   h\n", fp);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8; j++) {
                //se estivermos na primeira casa da linha
                if (j == 8 && i == 0) {
                    fputs("2 | ", fp);
                } else if (j == 1 && i == 7) {
                    fputs("1 | ", fp);
                } else if (j == 0) fprintf(fp, "%d | ", i + 1);
                else if (j > 0 && e->tab[i][j] == 1) {
                    fputs("O | ", fp);
                } else if (j > 0 && e->tab[i][j] == 2) {
                    fputs("@ | ", fp);
                } else if (j > 0 && e->tab[i][j] == 35) {
                    fputs("# | ", fp);
                } else {
                    fputs("_ | ", fp);
                }
            }
            fputs("\n", fp);
        }
        fputs("\n", fp);
        fclose(fp);
    } else if (strcmp(linha, "ler\n") == 0) {
        char str1;
        FILE *fp;
        printf("\nConteudo do ficheiro:\n");
        fp = fopen("file.txt", "r");
        printf("\n");
        str1 = fgetc(fp);
        while (str1 != EOF) {
            printf("%c", str1);
            str1 = fgetc(fp);
        }
        printf("\n\n");
        fclose(fp);
        return 1;
    } else if (strstr(linha, "pos") !=NULL) {
        // POS
        int nome,new[10];
        int i=0,j=0;
        for(j=0;j!='\n';j++){
            if(linha[j]!='0' && linha[j]!='1' && linha[j]!='2' && linha[j]!='3' && linha[j]!='4' && linha[j]!='5' && linha[j]!='6' && linha[j]!='7' && linha[j]!='8' && linha[j]!='9'){
            linha[j]='+';
            }else {
                new[i]=linha[j];
                i++;
            }
        }
        new[++i]='\0';
        sscanf((const char *) new, "%d", &nome);
        if(nome>=0 && nome<obter_numero_de_jogadas(e)) {
            e->num_jogadas = (nome*nome);
            COORDENADA inicial;
            inicial.linha = 3;
            inicial.coluna = 4;
            for(i=0;i<8;i++) {
                for (j=0;j<8;j++) {
                    e->tab[i][j] = 0;
                }
            }
            e->tab[inicial.linha][inicial.coluna]='#';
            int c=0;
            for(int i=0;i<8;i++) {
                for (int j=0;j<8;j++) {
                    if(c>=(e->num_jogadas*e->num_jogadas)) break;
                    else if(i==(e->jogadas[c].jogador1.linha) && j==e->jogadas[c].jogador1.coluna && e->jogadas[c].jogador1.linha!=0 && e->jogadas[c].jogador1.coluna!=0){
                        e->tab[i][j]=1;
                        e->ultima_jogada.linha=i;
                        e->ultima_jogada.coluna=j;
                        //printf(" (1) Atualizou casa: i:%d j:%d |",i,j);
                        e->jogador_atual=2;
                        c++;
                    }
                    else if(i==(e->jogadas[c].jogador2.linha) && j==e->jogadas[c].jogador2.coluna && e->jogadas[c].jogador2.linha!=0 && e->jogadas[c].jogador2.coluna!=0){
                        e->tab[i][j]=2;
                        e->ultima_jogada.linha=i;
                        e->ultima_jogada.coluna=j;
                        //printf(" (2) Atualizou casa: i:%d j:%d |",i,j);
                        e->jogador_atual=1;
                        c++;
                    }
                }
            }
            if(nome==0){
                e->ultima_jogada.linha=3;
                e->ultima_jogada.coluna=4;
            }
            mostrar_tabuleiro(e);
            pedir_entrada(e);

        }else printf("posicao invalida digite uma posicao entre 0 e %d\n",e->num_jogadas);
    }else if(strcmp(linha, "jog\n") == 0) {
        printf("entrou\n");
        jogarAuto(e);
        mostrar_tabuleiro(e);
    }else if(strcmp(linha, "jog2\n") == 0) {
        printf("entrou\n");
        jogarAutoAdv(e);
        mostrar_tabuleiro(e);
    }
    return 1;
}

int entrada(ESTADO *e) {
    int x, y,z;
    printf("Bem vindo ao jogo rastos\n\n\n");
    printf("1-Jogar  2-Informacao  3-Sair\n");
    printf("opcao:");
    scanf("%d",&x);
    if (x == 1) {
        printf("1-jogador numero um   2-jogador numero dois\n");
        printf("Escolha o seu numero de jogador:");
        scanf("%d",&y);
        if (y == 1) {
            printf("escolheu o jogador 1\n");
            printf("o outro jogador e o numero 2\n");
            e->jogador_atual=1;
        }
        else if (y == 2) {
            printf("escolheu o jogador 2\n");
            printf("o outro jogador e o numero 1\n");
            e->jogador_atual=2;
        }
        else{
            printf("invalido\n");
            entrada(e);
        }
    }
    else if (x == 2) {
        printf("created by Joao Carvalho, Joao Guedes, Miguel Tavares in 2020.\n");
        printf("Este jogo foi realiazado no ambito da disciplina de laboratorios de algoritmia.\n\n");
        printf("1-voltar ao menu   2-sair do jogo\n");
        printf("opcao:");
        scanf("%d",&z);
        if(z==1){
            entrada(e);
        }
        else if(z==2) {
            printf("\nObrigado por ter jogado!");
            return 0;
        }
        else{
            printf("invalido!\n");
            entrada(e);
        }
    }
    else if (x == 3) {
        printf("\nObrigado por ter jogado!\n");
        return 0;
    }
    else{
        printf("\nEsse valor nao e valido.\nTente novamente.\n");
        entrada(e);
    }
    return 1;
}


void mostrar_tabuleiro (ESTADO *e) {
    int win=0;
    putchar('\n');
    printf( "    a   b   c   d   e   f   g   h\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<=8;j++){
            //se estivermos na primeira casa da linha
            if(j==8 && i==0){
                printf( "%d | ", 2);
                if(e->tab[i][j]==1 || e->tab[i][j]==2) win=1;
            }else if(j==1 && i==7){
                printf( "%d | ", 1);
                if(e->tab[i][j]==1 || e->tab[i][j]==2) win=2;
            }

            else if(j==0) printf("%d | ",i+1);
            else if(j>0 && e->tab[i][j] == 1){
                printf( "%c | ", 'O');
            }
            else if(j>0 && e->tab[i][j] == 2){
                printf( "%c | ", '@');
            }else if(j>0 && e->tab[i][j] == 35){
                printf( "%c | ", '#');
            }else{
                printf( "%c | ", '_');
            }
        }
        putchar('\n');
    }
    putchar('\n');
    if(win){ fim(win);}
}



int fim(int x){
    if(x==1){
        printf("vencedor:jogador 1");
    }
    else if(x==2){
        printf("vencedor:jogador 2");
    }
    exit(0);
    return 0;
}

void pedir_entrada(ESTADO *e) {
    int trash=0;
    printf("# %d PL%d (%d)>", (e->num_jogadas + 1), e->jogador_atual, e->num_jogadas);
    scanf("%d", &trash);
    interpretador(e);
}
