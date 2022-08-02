#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7

void iniciarfunc(int tabuleiro[LIN][COL]);
void calcvitoria(int& vitoria, int tabuleiro[LIN][COL]);

int main(void) {

    system("mode con:cols=89 lines=25");//deixar o cmd do tamanho da tela do jogo

    int tabuleiro [LIN][COL];
    int escolha;
    int jogador = 1;
    int vitoria = 0;

    iniciarfunc(tabuleiro);

    do{
    cout << "Jogador: " << jogador << "\n";
    cout << "Qual coluna deseja jogar?\n";
    cin >> escolha;

    for (int i = LIN; i >= 0; i--) {
        if(tabuleiro[i][escolha - 1] == 0){
            tabuleiro[i][escolha - 1] = jogador;
            break;
        }
    }

    if(jogador == 1){
        jogador++;
    }else if (jogador == 2){
        jogador--;
    }

    calcvitoria(vitoria, tabuleiro);

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    }while(vitoria == 0);
    cout << "vitoriaaaaaaa " << vitoria;





/*
    cout << "  _      _____ _____   _  _    \n";
    cout << " | |    |_   _/ ____| | || |   \n";
    cout << " | |      | || |  __  | || |_  \n";
    cout << " | |      | || | |_ | |__   _| \n";
    cout << " | |____ _| || |__| |    | |   \n";
    cout << " |______|_____\\_____|    |_|   \n";
*/




    return 0;
}


void iniciarfunc(int tabuleiro[LIN][COL]){

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            tabuleiro[i][j] = 0;
        }
    }

}

void calcvitoria(int& vitoria, int tabuleiro[LIN][COL]){

    int jog = 1;

    for (int i = LIN; i >= 0; i--) {
        for (int j = COL; j >= 0; j--) {
            int jog = 1;
            do{

//===============================horizontal==================================

                if(j - 3 > 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j-1] == jog && tabuleiro[i][j-2] == jog && tabuleiro[i][j-3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < 7){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j+1] == jog && tabuleiro[i][j+2] == jog && tabuleiro[i][j+3] == jog){
                        vitoria = jog;
                    }
                }

//==============================vertical=======================================

                if(i - 3 > 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j] == jog && tabuleiro[i-2][j] == jog && tabuleiro[i-3][j] == jog){
                        vitoria = jog;
                    }
                }

                if(i + 3 < 6){
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j] == jog && tabuleiro[i+2][j] == jog && tabuleiro[i+3][j] == jog){
                        vitoria = jog;
                    }
                }

//=============================diagonal=========================================

                if(j - 3 > 0 && i - 3 < 6){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j-1] == jog && tabuleiro[i-2][j-2] == jog && tabuleiro[i-3][j-3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < 7 && i - 3 < 6){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j+1] == jog && tabuleiro[i-2][j+2] == jog && tabuleiro[i-3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                jog++;
            }while(jog <= 2);
        }
    }

}


/*
                 .eeeeeeeee
                .$$$$$$$$P"
               .$$$$$$$$P
              z$$$$$$$$P
             z$$$$$$$$"
            z$$$$$$$$"
           d$$$$$$$$"
          d$$$$$$$$"
        .d$$$$$$$P
       .$$$$$$$$P
      .$$$$$$$$$.........
     .$$$$$$$$$$$$$$$$$$"
    z$$$$$$$$$$$$$$$$$P"
   -**********$$$$$$$P
                     d$$$$$$"
                   .d$$$$$$"
                  .$$$$$$P"
                 z$$$$$$P
                d$$$$$$"
              .d$$$$$$"
             .$$$$$$$"
            z$$$$$$$beeeeee
           d$$$$$$$$$$$$$*
          ^""""""""$$$$$"
                  d$$$*
                 d$$$"
                d$$*
               d$P"
             .$$"
            .$P"
           .$"
          .P"
         ."
        /"

ZAMBA
*/
