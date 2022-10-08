#ifndef __GCONIO_H
#define __GCONIO_H

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void clrscr (void);
void delay (unsigned long milliseconds);
void textbackground (int newcolor);
void textcolor (int newcolor);
void gotoxy (int x, int y);


enum COLORS {
    BLACK        = 0,
    BLUE         = FOREGROUND_BLUE,
    GREEN        = FOREGROUND_GREEN,
    CYAN         = FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED          = FOREGROUND_RED,
    MAGENTA      = FOREGROUND_RED | FOREGROUND_BLUE,
    BROWN        = FOREGROUND_RED | FOREGROUND_GREEN,
    LIGHTGRAY    = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKGRAY     = FOREGROUND_INTENSITY,
    LIGHTBLUE    = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHTGREEN   = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHTCYAN    = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHTRED     = FOREGROUND_RED | FOREGROUND_INTENSITY,
    LIGHTMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    YELLOW       = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    WHITE        = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
};
WORD __gconio_h_ansi_fg = WHITE;
WORD __gconio_h_ansi_bg = BLACK << 4;

/**** FUNCTIONS ****************************/

void delay (unsigned long milliseconds)
{
    unsigned long tstart, tnow;
    milliseconds *= CLK_TCK/1000;
    tstart = clock();
    while ((tnow = clock() - tstart) < milliseconds) { }
}



void clrscr (void)
{
    system("cls");
}


void gotoxy (int x, int y)
{
    x--;
    y--;
    COORD cxy = { x , y };
    CONSOLE_SCREEN_BUFFER_INFO conScrBufInfo;
    if (GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &conScrBufInfo))
        cxy.Y = y + conScrBufInfo.srWindow.Top;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), cxy);
}

void textcolor (int newcolor)
{
    __gconio_h_ansi_fg = newcolor;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (__gconio_h_ansi_fg | __gconio_h_ansi_bg));
}

void textbackground (int newcolor)
{
    __gconio_h_ansi_bg = newcolor << 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (__gconio_h_ansi_fg | __gconio_h_ansi_bg));
}


#endif /* __GCONIO_H */


