#include "ui_mainwindow.h"
#include "vueformnom.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultat_= 0 ;

}
void MainWindow::IntNBjoueur(){

    QString contenu = ui->lineEditNBjoueur->text();
    QString contenuu = "9";
    this->resultat_ = contenu.toInt();
    cout<<"\n\n djfiuezfezhifhezifhiehe \ndefef =====" << resultat_ <<" FF "<<contenuu.toInt();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    VueFormNom *window = new VueFormNom();
    window->show();
}


