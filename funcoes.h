 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include <ctype.h>
#include <fstream> //arquivo
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7

struct player{
   char nome1[30];
   int pontos1 = 0;
   char nome2[30];
   int pontos2 = 0;

};

void IniciarFunc(int tabuleiro[LIN][COL]);
void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL], player& j1, player& j2);
void CalcVitoria();
void Checar(char& continuar);
void Checar(int& escolha, int contar[], int jogador);
int Checar();
int Jogador(int jogador, player j1, player j2);
void TelaInicial ();
void ImprimirTabuleiro(int tabuleiro[LIN][COL]);
int MexerQuadrado(int jogador);
void MontarTabuleiro(int tabuleiro[LIN][COL], int jogador);
void Menu();
void LigGrande();
void jogo(char* arquivo);
void NomeJogador(player& j1, player& j2);
void Arquivo(char* arquivo, player j1, player j2);
void DadoArq(char* arquivo);


//====================Iniciar a matriz com 0=========================================
void IniciarFunc(int tabuleiro[LIN][COL]){
    /*percorre toda a matriz tabuleiro e atribui o valor 0 para todos os espacos*/

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            tabuleiro[i][j] = 0;
        }
    }

}
//=============checar se tem algum vencedor=========================================
void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL], player& pl){

    for (int i = LIN - 1; i >= 0; i--) {
        for (int j = COL - 1; j >= 0; j--) {//percorre todo a matriz
            int jog = 1;
            do{

//===============================horizontal==================================

                if(j - 3 >= 0){//checa os valores da esquerda da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j-1] == jog && tabuleiro[i][j-2] == jog && tabuleiro[i][j-3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < COL){//checa os valores da direita da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j+1] == jog && tabuleiro[i][j+2] == jog && tabuleiro[i][j+3] == jog){
                        vitoria = jog;
                    }
                }

//==============================vertical=======================================

                if(i - 3 >= 0){//checa os valores de cima da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j] == jog && tabuleiro[i-2][j] == jog && tabuleiro[i-3][j] == jog){
                        vitoria = jog;
                    }
                }

                if(i + 3 < LIN){//checa os valores de baixo da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j] == jog && tabuleiro[i+2][j] == jog && tabuleiro[i+3][j] == jog){
                        vitoria = jog;
                    }
                }

//=============================diagonal=========================================

                if(j + 3 < COL && i - 3 >= 0){//checa os valores da diagonal da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j+1] == jog && tabuleiro[i-2][j+2] == jog && tabuleiro[i-3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < COL && i + 3 < LIN){//checa os valores da diagonal da posicao
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j+1] == jog && tabuleiro[i+2][j+2] == jog && tabuleiro[i+3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                jog++;//passa apara o priximo jogador para checar se ele ganhou
            }while(jog <= 2);
        }
    }

    if(vitoria != 0){
        gotoxy(1,1);
        cout << "                               ";

        gotoxy(35, 3);
        if(vitoria == 1){//imprime na tela o nome do jogador 1
            textbackground(BLUE);
            pl.pontos1++;
            cout << "Jogador: " << pl.nome1 << " WINS";
        }else if(vitoria == 2){//imprime na tela o nome do jogador 1
            textbackground(GREEN);
            pl.pontos2++;
            cout << "Jogador: " << pl.nome2 << " WINS";
        }

        textbackground(WHITE);
        gotoxy(54,1);
        cout << "                                         ";
    }

}
//=====================ver se continua=========================================
void Checar(char& continuar){

    gotoxy(34,24);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "Deseja continuar? s/n";
    do {//pede para o jogador informar se deseja continuar o jogo (s) ou se deseja parar (n)
        continuar = tolower(getch());
    }while(continuar != 's' && continuar != 'n');

    gotoxy(35, 3);
    cout << "                            ";
    gotoxy(34,24);
    cout << "                            ";
    gotoxy(1,25);
}
//============ver se a coluna e valida ou esta disponivel=========================================
void Checar(int& escolha, int contar[], int jogador){

    int aux;

    do{

        escolha = MexerQuadrado(jogador);//recebe a posicao escolhida pelo jogador

        if(contar[escolha-1] == 6){//checar se a linha escolhida pelo jogador esta cheia
            gotoxy(1, 2);
            textbackground(WHITE);
            textcolor(BLACK);
            cout << "Coluna invalida";

            if(jogador == 1){
                textbackground(BLUE);
            }else if(jogador == 2){
                textbackground(GREEN);
            }

            aux = 0;
        }else{//se nao estiver cheia ele aumenta um numero em um vetor correspondente a cada linha (ele fica cheio quando o valor chega a 6)
            contar[escolha-1]++;
            aux = 1;
        }

    }while(escolha > COL || escolha < 1 || aux == 0);

}
//=========================chechar se a opcar escolhida e valida================
int Checar(){

    char op;

    do{//pede a opcao escolhida no menu (1 - jogo, 2 - historico, 3 - sair)
        op = getch();
    }while(op != '1' && op != '2' && op != '0');

    return op;

}
//================trocar de jogador por rodada=========================================
int Jogador(int jogador, player pl){

    gotoxy(1,1);

    if(jogador == 1){//troca do jogador 1 para o jogador 2 e imprime o nome dele na respectiva cor
        jogador++;
        textbackground(GREEN);
        textcolor(BLACK);
        cout << "Jogador: " << pl.nome2;
        textbackground(WHITE);
        cout << "                                  ";
        textbackground(GREEN);
    }else if (jogador == 2){//troca do jogador 2 para o jogador 1 e imprime o nome dele na respectiva cor
        jogador--;
        textbackground(BLUE);
        textcolor(WHITE);
        cout << "Jogador: " << pl.nome1;
        textbackground(WHITE);
        cout << "                                  ";
        textbackground(BLUE);
    }

    return jogador;
}
//========================tela inicial do programa=========================================
void TelaInicial(){

    LigGrande();

    gotoxy(26,16);
    cout << "Pressione qualquer tecla para continuar";
    getch();

    gotoxy(12, 16);
    printf("CARREGANDO");

    gotoxy(40,18);
    printf("          ");

    gotoxy(79,24);
    printf("        ");
    textbackground(BLACK);
    gotoxy(24, 16);
    printf("                                                        ");

    textbackground(RED);
    gotoxy(24, 16);

    for (int c = 16; c <= 25; c++){//fazer a parte grafica do carregamento
        printf(" ");
        Sleep(150);
    }
    for (int c = 26; c <= 66; c++){
        printf(" ");
        Sleep(70);
    }
    for (int c = 67; c <= 71; c++){
        printf(" ");
       Sleep(250);
    }

    textbackground(WHITE);
    system("cls");
    gotoxy(1,1);

}
//=================imprimir o tabuleiro na tela=========================================
void ImprimirTabuleiro(int tabuleiro[LIN][COL]){

    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(55, 1);
    cout << "Usar A, D ou SETAS para movimentar";

    int linha = 6, coluna = 22, colunas = 1;
    int lin = 0, col = 0;

    textbackground(RED);
    gotoxy(20,5);

    for (int l = 5; l <= MAX_LIN - 1; l++){//imprime um quadrado vermelho
        for (int c = 6; c <= MAX_COL-34; c++){
            printf(" ");
        }
        gotoxy(20 ,l);
    }

    do{
        linha = 6;
        lin = 0;
        do{

            if(tabuleiro[lin][col] == 0){//ninguem nessa coluna/linha o fundo fica branco
                textbackground(WHITE);
            }else if(tabuleiro[lin][col] == 1){//jogador 1 nessa coluna/linha o fundo fica azul
                textbackground(BLUE);
            }else if(tabuleiro[lin][col] == 2){//jogador 2 nessa coluna/linha o fundo fica verde
                textbackground(GREEN);
            }

            gotoxy(coluna,linha);

            for (int i = linha; i < linha + 2; i++) {//imprime um quadrado menor com a respectiva cor
                for (int j = coluna; j < coluna + 4; j++) {
                    gotoxy(j,i);
                    cout << " ";
                }
            }
            linha += 3;//vai para a posicao do procimo quadrado
            lin ++;

        }while(linha < 24);
        coluna += 7;
        colunas ++;
        col++;
    }while(coluna < 79 && colunas <= 7);
}
//==================mexer o quadrado superior=====================
int MexerQuadrado(int jogador){

    int coluna = 1;
    int l = 2 , c = 22;
    int tecla;

    gotoxy(c , l);
    cout << "    ";
    l++;
    gotoxy(c , l);
    cout << "    ";

    do{

            l = 2;

            tecla =getch();

            if(jogador == 1){
                textbackground(BLUE);
            }else if(jogador == 2){
                textbackground(GREEN);
            }

            if(coluna < COL){
                if(tecla == 100 || tecla == 77){//=======ir para a direita========
                    c += 7;
                    coluna++;

                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c -= 7;
                    l = 2;

                    textbackground(WHITE);
                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c += 7;
                    gotoxy(c , l);
                }
            }

            if(coluna > 1){
                if(tecla == 97 || tecla == 75){//=======ir para a esquerda========
                    c -= 7;
                    coluna--;

                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c += 7;
                    l = 2;

                    textbackground(WHITE);
                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c -= 7;
                    gotoxy(c , l);
                }
            }

   }while(tecla != 32 && tecla != 13 && tecla != 80 && tecla != 115);

    textbackground(WHITE);
    gotoxy(c , l);
    cout << "    ";
    l++;
    gotoxy(c , l);
    cout << "    ";

    gotoxy(1, 2);
    cout << "               ";

    return coluna;
}
//==================coloca o numero equivalente ao jogador na coluna escolhida=====================
void MontarTabuleiro(int tabuleiro[LIN][COL], int jogador, int escolha){

    for (int i = LIN - 1; i >= 0; i--) {//percorre o tabuleiro de cima para baixo, indo na coluna escolhida e colonado o valor no espaco mais em baixo disponivel
        if(tabuleiro[i][escolha - 1] == 0){
            tabuleiro[i][escolha - 1] = jogador;
            break;
        }
    }

}
//==================imprime na tela quando der empate=====================
void CalcVitoria(){

    gotoxy(1,1);
    textbackground(WHITE);
    cout << "          ";
    textbackground(RED);
    textcolor(BLACK);
    gotoxy(35, 3);
    cout << "Tivemos um empate!";
    textbackground(WHITE);
    gotoxy(54,1);
    cout << "                                         ";

}
//==================Menu=====================
void Menu(char& op){

    LigGrande();

    gotoxy(45,16);
    cout << "1-Jogar";
    gotoxy(43,18);
    cout << "2-Historico";
    gotoxy(82, 24);
    cout << "0-Sair";
    op = Checar();
    system("cls");

}
//==================imprimir Lig4 grande===================
void LigGrande(){

    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(1,1);

    for (int i = 1; i <= MAX_LIN; i++){
        for (int c = 1; c <= MAX_COL; c++){
            printf(" ");
        }
        printf("\n");
    }

    gotoxy(30, 4);
    cout << "  _      _____ _____   _  _    ";
    gotoxy(30, 5);
    cout << " | |    |_   _/ ____| | || |   ";
    gotoxy(30, 6);
    cout << " | |      | || |  __  | || |_  ";
    gotoxy(30, 7);
    cout << " | |      | || | |_ | |__   _| ";
    gotoxy(30, 8);
    cout << " | |____ _| || |__| |    | |   ";
    gotoxy(30, 9);
    cout << " |______|_____\\_____|    |_|   ";

}
//===========================coletar o nome dos jogadores=======================
void NomeJogador(player& pl){

    LigGrande();
    gotoxy(26,16);
    cout << "Nome do jogador 1:                                                                  ";
    gotoxy(45,16);
    fgets(pl.nome1, 30, stdin);//recebe o nome do jogador 1
    pl.nome1[strlen(pl.nome1) - 1] = '\0';
    gotoxy(26,16);
    cout << "Nome do jogador 2:                                                                  ";
    gotoxy(45,16);
    fgets(pl.nome2, 30, stdin);//recebe o nome do jogador 2
    pl.nome2[strlen(pl.nome2) - 1] = '\0';
    system("cls");

}
//==================escrever os dados no arquivo=====================
void Arquivo(char* arquivo, player pl){

    fstream his(arquivo, ios :: app);

        his.write((const char*) (&pl) ,sizeof (player));

    his.close();

}
//=================ler os dados do arquivo=================
void DadoArq(char* arquivo){

    player pl;
    string s;
    system("cls");
    int i = 3, cont = -1;
    gotoxy(2, 1);
    cout << setiosflags(ios :: left)
        <<  setw(30) << "Jogador 1"
        <<  setw(6) << "Pontos"
        << "   X    "
        <<  setw(30) << "Jogador 2"
        <<  setw(6) << "Pontos" << endl;

    fstream tam(arquivo, ios :: in);

        if(!tam){
            gotoxy(31,13);
            cout << "Nenhum historico disponivel";
        }
        else{
            tam.read((char*)(&pl), sizeof(player));

            while (!tam.eof()){//percorre o arquivo contando quantas linhas existem nele
                cont++;
                tam.read((char*)(&pl), sizeof(player));
            }

            if(cont > 10){
                cont = 10;
            }
        }
    tam.close();

    fstream his(arquivo, ios :: in);
        while(cont>=0){//percorre o arquivo de baixo para cima, imprimindo na tela os dados dos jogadores (do mais recente para o mais antigo)

            his.seekp(cont * sizeof(player), ios_base::beg);
            his.read((char*)(&pl), sizeof(player));

            gotoxy(2, i);
            cout << setiosflags(ios :: left)
                    <<  setw(30) << pl.nome1
                    << resetiosflags(ios :: left)
                    <<  setw(6) << pl.pontos1
                    << setiosflags(ios :: left)
                    << "   X    "
                    <<  setw(30) << pl.nome2
                    << resetiosflags(ios :: left)
                    <<  setw(6) << pl.pontos2 << "\n";
                    i += 2;

            cont--;
        }

    his.close();

    gotoxy(63, 25);
    cout << "Qualquer tecla para voltar";
    getch();

}


//==================jogo==================
void jogo(char* arquivo){

    player pl;
    int tabuleiro [LIN][COL];
    int escolha, jogador = 2;
    char continuar;
    NomeJogador(pl);

     do{

                int contar[] = {0, 0, 0, 0, 0, 0, 0};
                int vitoria = 0;
                IniciarFunc(tabuleiro);
                ImprimirTabuleiro(tabuleiro);
                int cont = 0;

                do{

                    cont++;

                    jogador = Jogador(jogador, pl);

                    Checar(escolha, contar, jogador);

                    MontarTabuleiro(tabuleiro, jogador, escolha);

                    CalcVitoria(vitoria, tabuleiro, pl);

                    ImprimirTabuleiro(tabuleiro);

                    if(cont == 42 && vitoria == 0){//checa se o tabuleiro esta cheio e nao tem nenhum vencedor (empate)
                        CalcVitoria();
                        break;
                    }

                }while(vitoria == 0);

                Checar(continuar);

            }while(continuar == 's');

            Arquivo(arquivo, pl);


}

