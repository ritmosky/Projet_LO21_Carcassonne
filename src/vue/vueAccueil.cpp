#include "vueAccueil.h"
#include "ui_vueAccueil.h"
#include "vueFormNom.h"
#include <iostream>
using namespace std;


VueAccueil::VueAccueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VueAccueil)
{
    ui->setupUi(this);
    ui->spinBox->setMaximum(4);
    ui->spinBox->setMinimum(2);
}


VueAccueil::~VueAccueil()
{
    delete ui;
}


void VueAccueil::setNbrJoueur(){
    this->nbJoueur = ui->spinBox->value();
}

void VueAccueil::on_pushButton_clicked()
{
    setNbrJoueur();
    int nJoueur = getNbrJoueur();
    cout<<"-------"<<nbJoueur<<endl;
    VueFormNom* fenetreFormNom = new VueFormNom(nJoueur);
    fenetreFormNom->show();
}



