#include "algoritmos_cana.h"
#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include <vector>
#include "ui_mainwindow.h"

using namespace std;


void Mostrar_Lista(vector<int> v, int n){
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << ", ";
    }
}

