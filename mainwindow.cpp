#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmos_cana.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "windows.h"

using namespace std;

vector<int> lista2;
vector<int> lista_fibonacci;
int lista[] = {500, 40, 30, 650, 14, 70, 90, 1313, 100, 1, 8000, 13};
//int const tamanho = (sizeof(lista) / sizeof(lista[0]));
int tamanho = lista2.size();
//int videos[] = {100, 350, 500, 550, 750, 948, 1460, 1520, 1600, 1767, 1842, 1945, 1999, 2000, 2500, 4500, 6540};

vector<int> videos;
int quantidade_videos = videos.size();
int tamanho_pendrive = 8000;

int n_fibonacci = 12;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setMaximum(100);
    cout << "TAMANHO: "<< tamanho << endl;
    ui->plainTextEdit->clear();
    ui->listWidget->clear();
    ui->progressBar->setValue(0);
    int proxIndice, auxiliar;

    for (int indice = 0; indice < tamanho; indice++){
        int max = indice;
        for (proxIndice = indice+1; proxIndice < tamanho; proxIndice++){
            if (lista2[proxIndice] > lista2[max]){
                max = proxIndice;
            }
        }

        ui->plainTextEdit->insertPlainText("Passo: ");
        ui->plainTextEdit->insertPlainText(QString::number(indice+1));
        ui->plainTextEdit->insertPlainText(" Valor Máximo: ");
        ui->plainTextEdit->insertPlainText(QString::number(lista2[max]));
        ui->plainTextEdit->insertPlainText("  {");

        for (int i = 0; i < tamanho; i++){

            ui->plainTextEdit->insertPlainText(QString::number(lista2[i]) + ", ");
            cout << lista2[i] << ", ";
        }
        ui->plainTextEdit->insertPlainText("}");
        ui->plainTextEdit->appendPlainText("");

        //cout << "Passo: " << indice+1 << ", Max: " << v[max]<< endl;
        auxiliar = lista2[indice];
        lista2[indice] = lista2[max];
        lista2[max] = auxiliar;

        //ui->listWidget_3->addItem("Passo: " + QString::number(indice+1) + "Max: " + QString::number(lista2[max]));

        ui->progressBar->setValue(((indice+1)*100)/(tamanho));
        //Sleep(1000);
    }
    for (int i = 0; i < tamanho; i++){
        ui->listWidget->addItem(QString::number(lista2[i]));
    }
    cout << endl;
}

void Divisao_Conquista(vector<int>& v, int const esquerda, int const meio, int const direita){
    //! baseado em https://www.programiz.com/dsa/merge-sort
    auto const tamanhoEsquerda = meio - esquerda + 1;
    auto const tamanhoDireita = direita - meio;

    //! Criar arrays temporarios
    auto *arrayEsquerdo = new int[tamanhoEsquerda],
         *arrayDireito = new int[tamanhoDireita];

    //! Preenchendo os arrays com os dados
    for (auto i = 0; i < tamanhoEsquerda; i++)
        arrayEsquerdo[i] = v[esquerda + i];
    for (auto j = 0; j < tamanhoDireita; j++)
        arrayDireito[j] = v[meio + 1 + j];

    //! Começando as comparações dos 2 arrays
    auto comecoEsquerda = 0; // Indice inicial do array esquerdo
    auto comecoDireita = 0; // Indice inicial do array direito
    int indiceCombinado = esquerda; // Indice inicial do array combinado

    while (comecoEsquerda < tamanhoEsquerda && comecoDireita < tamanhoDireita) {
        if (arrayEsquerdo[comecoEsquerda] >= arrayDireito[comecoDireita]) {
            v[indiceCombinado] = arrayEsquerdo[comecoEsquerda];
            comecoEsquerda++;
        }
        else {
            v[indiceCombinado] = arrayDireito[comecoDireita];
            comecoDireita++;
        }
        indiceCombinado++;
    }

    //! Copia o resto do array esquerdo pro principal
    while (comecoEsquerda < tamanhoEsquerda) {
        v[indiceCombinado] = arrayEsquerdo[comecoEsquerda];
        comecoEsquerda++;
        indiceCombinado++;
    }

    //! Copia o resto do array direito pro principal
    while (comecoDireita < tamanhoDireita) {
        v[indiceCombinado] = arrayDireito[comecoDireita];
        comecoDireita++;
        indiceCombinado++;
    }
    delete[] arrayEsquerdo;
    delete[] arrayDireito;
}

void MainWindow::Ordenar_Divisao_Conquista(vector<int>& v, int const comeco, int const fim){
    // "Comeco" eh pro array esquerdo e "fim" eh pro direito
    if (comeco >= fim)
        return; // Retorna de forma recursiva

    int meio = comeco + (fim - comeco) / 2;



    if (comeco != 0)
        ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->insertPlainText("[Array 1]                           [Array 2]");
    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->insertPlainText("{");
    for (int indice = comeco; indice <= meio; indice++){
        cout << " ," << v[indice];
        ui->plainTextEdit->insertPlainText(QString::number(v[indice]) + ", ");
    }
    ui->plainTextEdit->insertPlainText("}");
    ui->plainTextEdit->insertPlainText(".............................");
    cout << ".................................";
    ui->plainTextEdit->insertPlainText("{");
    for (int indice = meio + 1; indice <= fim; indice++){
        cout << " ," << v[indice];
        ui->plainTextEdit->insertPlainText(QString::number(v[indice]) + ", ");
    }
    ui->plainTextEdit->insertPlainText("}");
    ui->plainTextEdit->appendPlainText("");




    Ordenar_Divisao_Conquista(v, comeco, meio);


    cout << endl;


    Ordenar_Divisao_Conquista(v, meio + 1, fim);
    if (ui->progressBar->value() < fim/2)
        ui->progressBar->setValue(fim/2);

    Divisao_Conquista(v, comeco, meio, fim);
    if (ui->progressBar->value() < fim*0.90)
        ui->progressBar->setValue(fim*0.90);



    ui->listWidget->clear();

    for (int i = 0; i < fim; i++){
        lista2[i] = v[i];
        ui->listWidget->addItem(QString::number(lista2[i]));
    }
    Mostrar_Lista(v, fim);
    ui->progressBar->setValue(fim);
}

// ORDENAR PELO MERGE SORT
void MainWindow::on_pushButton_2_clicked()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(tamanho-1);
    ui->listWidget->clear();
    Ordenar_Divisao_Conquista(lista2, 0, tamanho - 1);
}



void MainWindow::Ordenar_WilliamSort(vector <int>& v, int indice, int n){

    cout << endl;
    //Mostra a lista de números atuais

    if (indice < 0)
        indice = 0;

    int progresso = (indice*100/n);
    if (progresso > ui->progressBar->value())
        ui->progressBar->setValue(indice*100/n);


    cout << endl;
    //Mostra a lista de números atuais

    ui->plainTextEdit->insertPlainText("{");
    for (int i = 0; i < n; i++)
            ui->plainTextEdit->insertPlainText(QString::number(v[i]) + ", ");

    ui->plainTextEdit->insertPlainText("} ");
    ui->plainTextEdit->insertPlainText("Indice atual: " + QString::number(indice));
    ui->plainTextEdit->appendPlainText("");



    for (int i = 0; i < n; i++)
            cout << v[i] << ", ";
    cout << "Indice atual: " << indice << endl;
    //Condição de saida recursiva, quando chegar no fim da fila
    if (indice>=n-1)
       return;
    int proximo = indice + 1;
    //int maior_valor = indice;
    //Verifica se o valor atual é menor que o proximo, se for, troca e chama recursivo pro anterior
        if (v[indice] < v[proximo]){
            //maior_valor = proximo;
            int auxiliar = v[indice];
            v[indice] = v[proximo];
            v[proximo] = auxiliar;
            Ordenar_WilliamSort(v, indice-1, n);
        }
    //Se não, só chama pro proximo
        else
            Ordenar_WilliamSort(v, proximo, n);
}

void MainWindow::on_Resetar_clicked(){
}

// ORDENAR POR ????
void MainWindow::on_pushButton_3_clicked()
{
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    ui->listWidget->clear();
    Ordenar_WilliamSort(lista2, 0, tamanho);
        for (int i = 0; i < tamanho; i++){
            ui->listWidget->addItem(QString::number(lista2[i]));
            cout << "*, " << lista2[i];
        }
    ui->progressBar->setValue(100);
}

// ADICONAR NA LISTA
void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget_4->clear();
    ui->listWidget_2->addItem(ui->lineEdit->text());
    lista2.push_back(ui->lineEdit->text().toInt());
    videos.push_back(ui->lineEdit->text().toInt());
    ui->lineEdit->clear();
    tamanho = lista2.size();
    ui->listWidget_4->addItem(QString::number(tamanho));
}

// ADICIONAR NA LISTA ALEATORIO
void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget_4->clear();
    for (int i = 0; i < 20; i++){
        lista2.push_back(rand() % 1000 + 1);
    ui->listWidget_2->addItem(QString::number(lista2.back()));
    }
    tamanho = lista2.size();
    ui->listWidget_4->addItem(QString::number(tamanho));
}

// RESETAR
void MainWindow::on_pushButton_6_clicked()
{
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    lista2.clear();
    videos.clear();
    tamanho_pendrive = 0;
    lista_fibonacci.clear();

    quantidade_videos = 0;
    tamanho = 0;

    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
    ui->listWidget->clear();
    ui->listWidget_4->clear();
    ui->plainTextEdit->clear();

}

// FIBONACCI 2N
void MainWindow::on_fibonacci_2n_clicked()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum((pow(1.61803398875,ui->lineEdit->text().toInt())-pow(-0.61803398875,ui->lineEdit->text().toInt()))/sqrt(5));
    ui->plainTextEdit->clear();
    ui->listWidget_3->clear();
    ui->listWidget_3->addItem(QString::number(Fibonacci_2n(ui->lineEdit->text().toInt())));
}


int MainWindow::Fibonacci_top_down(int n){
        if (n <= 1)
            return n;

        if (lista_fibonacci[n] != -1){
            return lista_fibonacci[n];
        }

        lista_fibonacci[n] = Fibonacci_top_down(n-1) + Fibonacci_top_down(n-2);
        cout << "Valor atual N: " << n << ", F: " << lista_fibonacci[n] << endl;
        ui->plainTextEdit->appendPlainText("Vallor atual N: " + QString::number(n) + ", F: " + QString::number(lista_fibonacci[n]));
        ui->progressBar->setValue(n);
        return lista_fibonacci[n];
}

void MainWindow::on_fibonacci_top_down_clicked()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(ui->lineEdit->text().toInt());
    if (lista_fibonacci.size() < 2)
        for (int i=0; i <= (ui->lineEdit->text().toInt()); i++)
            lista_fibonacci.push_back(-1);
    ui->plainTextEdit->clear();
    ui->listWidget_3->clear();
    ui->listWidget_3->addItem(QString::number(Fibonacci_top_down(ui->lineEdit->text().toInt())));
    lista_fibonacci.clear();
}

int MainWindow::Fibonacci_bottom_up(int n){
    if (n<=1)
        return n;
    int a = 0;
    int b = 1;
    for (int x = 2; x<= n; x++){
        int auxiliar = a+b;
        a = b;
        b = auxiliar;
        cout << "Valor atual N: " << x << ", F: " << b << endl;
        if (ui->progressBar->value() < x)
            ui->progressBar->setValue(x);
        ui->plainTextEdit->appendPlainText("Vallor atual N: " + QString::number(x) + ", F: " + QString::number(b));
    }
    return b;
}



void MainWindow::on_fibonacci_bottom_up_clicked()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(ui->lineEdit->text().toInt());
    ui->listWidget_3->clear();
    ui->listWidget_3->addItem(QString::number(Fibonacci_bottom_up(ui->lineEdit->text().toInt())));
}

int MainWindow::Fibonacci_constante(int n){
    ui->progressBar->setValue(100);
    return ((pow(1.61803398875,n)-pow(-0.61803398875,n))/sqrt(5));
}

void MainWindow::on_fibonacci_constante_clicked()
{
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    ui->listWidget_3->clear();
    ui->listWidget_3->addItem(QString::number(Fibonacci_constante(ui->lineEdit->text().toInt())));
    ui->plainTextEdit->insertPlainText("?Que pasa¿");
}


void MainWindow::pendrive (std::vector<int>& v, int armazenamento){
    int n = v.size();
    ui->plainTextEdit->insertPlainText("Numero de videos: " + QString::number(n));
    cout << "Numero de videos: "<< n << endl;
    int videos_adicionados = 0;
    ui->plainTextEdit->appendPlainText("---------------Videos disponiveis------------------");
    ui->plainTextEdit->appendPlainText("");
    cout << "--------------Videos disponiveis--------------" << endl;
    for (int x = 0; x < n; x++){
        cout << " ,"<< v[x];
        ui->plainTextEdit->insertPlainText(", " + QString::number(v[x]));
    }
    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->appendPlainText("");
    cout << endl;
    cout << endl;
    for (int i = 0; i <n; i++){
        if (v[i] != 0 && v[i] >=400 && v[i] <= 2000 && v[i] <= armazenamento){
            armazenamento = armazenamento - v[i];
            ui->progressBar->setValue((i*100)/n);
            ui->plainTextEdit->appendPlainText("Adicionou o video de tamanho " + QString::number(v[i]) + "mb para o pendrive. Restante: " + QString::number(armazenamento) + "mb");
            cout << "Adicionou o video de tamanho " << v[i] << "mb para o pendrive. Restante: " << armazenamento <<"mb" << endl;
            v[i] = 0;
            videos_adicionados++;
        }
    }
    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->appendPlainText("");
    cout << endl;
    cout << endl;
    ui->plainTextEdit->appendPlainText("---------------Videos restantes------------------");
    ui->plainTextEdit->appendPlainText("");
    cout << "--------------Videos restantes--------------" << endl;
    for (int x = 0; x < n; x++){
        if (v[x] != 0){
        cout << " ,"<< v[x];
        ui->plainTextEdit->insertPlainText(", " + QString::number(v[x]));
        ui->listWidget->addItem(QString::number(v[x]));
        }
    }

    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->appendPlainText("");
    cout << endl;
    cout << endl;
    ui->plainTextEdit->appendPlainText("Armazenamento restante: " + QString::number(armazenamento));
    cout << "Armazenamento restante: " << armazenamento << "mb"<< endl;
    ui->plainTextEdit->appendPlainText("Videos adicionados: " + QString::number(videos_adicionados));
    cout << "Videos Adicionados: " << videos_adicionados << endl;

}


void MainWindow::on_pendrive_clicked()
{
    ui->progressBar->setMaximum(videos.size());
    ui->plainTextEdit->clear();
    tamanho_pendrive = ui->lineEdit->text().toInt();
    quantidade_videos = videos.size();
    cout << "Numero de videos: "<< quantidade_videos << endl;

    pendrive(videos, tamanho_pendrive);
    ui->progressBar->setValue(videos.size());
}


void MainWindow::on_pesquisa_forca_bruta_clicked()
{
    ui->plainTextEdit->clear();
    ui->progressBar->setValue(0);
    ui->listWidget_4->clear();
    for (int i = 0; i <= lista2.size(); i++){
        //cout << "Procurando" << ui->lineEdit->text() << " na posicao " << i << endl;
        ui->plainTextEdit->appendPlainText("Procurando " + QString::number(ui->lineEdit->text().toInt()) + "na posicao " + QString::number(i) );
        ui->progressBar->setValue(i*100/lista2.size());
        if (lista2[i] == ui->lineEdit->text().toInt()){
            ui->listWidget_4->addItem(QString::number(i));
            break;
        }
    }
    ui->progressBar->setValue(100);
}


int MainWindow::pesquisar_divisao_conquista (vector<int>& v, int i, int n, int j){
    ///pesquisa binaria, o vetor deve estar ordenado de forma decrescente antes!!
    ui->plainTextEdit->appendPlainText("Procurando " + QString::number(j)+"...");
    while (i != n){
        int metade = (i+n)/2;
        //cout << "Metade = " << metade << endl;
        //cout << "indice i atual: " << i << endl;
        //cout << "indice n atual: " << n << endl;
        if (j == v[metade])
            return metade;
        if (j <= v[metade]){
            i = metade + 1;
            cout << "" << j << " esta localizado na segunda metade da lista" << endl;
            ui->plainTextEdit->appendPlainText(QString::number(j) + " esta localizado na segunda metade");
        }
        else{
            n = metade;
            cout << "" << j << " esta localizado na primeira metade da lista" << endl;
            ui->plainTextEdit->appendPlainText(QString::number(j) + " esta localizado na primeira metade");
        }
    }
    if (j == v[i])
        return i;
    else
        cout << "Elemento nao encontrado" << endl;
    return -1;
}


void MainWindow::on_pesquisa_binaria_clicked()
{
    ui->progressBar->setValue(0);
    ui->plainTextEdit->clear();
    ui->listWidget_4->clear();
    ui->listWidget_4->addItem(QString::number(pesquisar_divisao_conquista(lista2, 0, lista2.size()-1, ui->lineEdit->text().toInt())));
    ui->progressBar->setValue(100);
}


int MainWindow::pesquisar_tentativa_erro (std::vector<int> &v, int n, int j){
    ui->plainTextEdit->appendPlainText("Procurando " + QString::number(j) + " na posicao " + QString::number(n));
    if (n < 0 || v[n] == j)
            return n;
        else
            pesquisar_tentativa_erro(v, n-1, j);
}

void MainWindow::on_pesquisa_3_clicked()
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(100);
    ui->plainTextEdit->clear();
    ui->listWidget_4->clear();
    ui->listWidget_4->addItem(QString::number(pesquisar_tentativa_erro (lista2, tamanho-1, ui->lineEdit->text().toInt())));
    ui->progressBar->setValue(100);
}

