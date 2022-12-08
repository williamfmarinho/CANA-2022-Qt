#include "algoritmos_cana.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
using namespace std;

//int lista_fibonacci[500];

//void Fibonacci_top_down_auxiliar(){
//    int tamanho = (sizeof(lista_fibonacci) / sizeof(lista_fibonacci[0]));
//    for (int x = 0; x<=tamanho; x++)
//        lista_fibonacci[x] = -1;
//}






int MainWindow::Fibonacci_2n(int n){
    int f = 0;
    if (n <= 1)
        return n;

    for (int x = 1; x <= 2; x++){
        f = f + Fibonacci_2n(n-x);
    }
    ui->plainTextEdit->appendPlainText("Valor atual N: " + QString::number(n) + ", F:" + QString::number(f));
    cout << "Valor atual N: " << n << ", F: " << f << endl;
    if (ui->progressBar->value() < f)
        ui->progressBar->setValue(f);
    return f;
}
