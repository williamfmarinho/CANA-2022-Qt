#include "algoritmos_cana.h"
#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;



int pesquisar_forca_bruta(int *v, int n, int j){
    cout << "Elemento nao encontrado" << endl;
    return -1;
}




int pesquisar_tentativa_erro (int *v, int n, int j){
    if (n < 0 || v[n] == j)
            return n;
        else
            pesquisar_tentativa_erro(v, n-1, j);
}
