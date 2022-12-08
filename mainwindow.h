#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int pesquisar_tentativa_erro (std::vector<int> &v, int n, int j);
    int pesquisar_divisao_conquista(std::vector<int>& v, int i, int n, int j);
    void pendrive (std::vector<int>& v, int armazenamento);
    int Fibonacci_constante(int n);
    int Fibonacci_2n(int n);
    int Fibonacci_bottom_up(int n);
    int Fibonacci_top_down(int n);
    void Ordenar_WilliamSort(std::vector<int>& v, int indice, int n);
    void Ordenar_Divisao_Conquista(std::vector<int>& v, int const comeco, int const fim);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_fibonacci_2n_clicked();

    void on_Resetar_clicked();

    void on_fibonacci_top_down_clicked();

    void on_fibonacci_bottom_up_clicked();

    void on_fibonacci_constante_clicked();

    void on_pendrive_clicked();

    void on_pesquisa_forca_bruta_clicked();

    void on_pesquisa_binaria_clicked();

    void on_pesquisa_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
