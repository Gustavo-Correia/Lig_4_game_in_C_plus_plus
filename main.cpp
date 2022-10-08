#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include "gconio.h"
#include "funcoes.h"
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7



int main(void) {//=============================Main=========================================

    system("mode con:cols=89 lines=25");//deixar o cmd do tamanho da tela do jogo

    TelaInicial();//imprimir a tela inicial e carregar o jogo
    char op;
    char* arquivo = "historico.dat";

    do{
        Menu(op);//escolhar quais das 3 opcoes o jogador deseja jogar

        if(op == '0'){//opcao sair
            return 0;
        }

        if(op == '1'){//opcao jogar
           jogo(arquivo);
        }
        else if(op == '2'){//opcao ver historico
            DadoArq(arquivo);
        }

    }while(op != '0');

    return 0;
}
