#include <bits/stdc++.h>
#include "algoritmos_cana.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

void limpar_tela(){
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

using namespace std;

#define N 8

int cavalgar(int x, int y, int passos, int tabuleiro[N][N], int movimento_x[], int movimento_y[]);


int Posicao_Valida(int x, int y, int tabuleiro[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && tabuleiro[x][y] == 0);
}


void Mostrar_Tabuleiro(int tabuleiro[N][N]){
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << tabuleiro[x][y] << " ";
        cout << endl;
    }
}


int cavalo()
{
    limpar_tela();
    int tabuleiro[N][N];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            tabuleiro[x][y] = 0;


    int movimento_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int movimento_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    tabuleiro[0][0] = 1;


    if (cavalgar(0, 0, 2, tabuleiro, movimento_x, movimento_y) == 0) {
        cout << "Solucao nao existe";
        return 0;
    }
    else
        Mostrar_Tabuleiro(tabuleiro);
    cout << "Sucesso!" << endl;
    return 1;
}


int cavalgar(int x, int y, int passos, int tabuleiro[N][N], int movimento_x[8], int movimento_y[8]){
    int i, proximo_x, proximo_y;
    if (passos == 65)
        return 1;


    for (i = 0; i < 8; i++) {
        proximo_x = x + movimento_x[i];
        proximo_y = y + movimento_y[i];
        limpar_tela();
        cout << "Verificando se a posicao " << proximo_x <<", " << proximo_y << " Esta certa"<< endl;
        Mostrar_Tabuleiro(tabuleiro);
        Sleep(2000);
        limpar_tela();
        if (Posicao_Valida(proximo_x, proximo_y, tabuleiro)) {
            tabuleiro[proximo_x][proximo_y] = passos;
            limpar_tela();
            cout << "Mudou o valor de tabuleiro["<<proximo_x<<"]["<<proximo_y<<"] para " << passos<< endl;
            Mostrar_Tabuleiro(tabuleiro);
            Sleep(2000);
            if (cavalgar(proximo_x, proximo_y, passos + 1, tabuleiro, movimento_x, movimento_y) == 1)
                return 1;
            else{
                cout << "Falha, retornando o valor de tabuleiro["<<proximo_x<<"]["<<proximo_y<<"] p/ 0" << endl;
                limpar_tela();
                Sleep(2000);
                tabuleiro[proximo_x][proximo_y] = 0;

            }
        }
    }
    return 0;
}
