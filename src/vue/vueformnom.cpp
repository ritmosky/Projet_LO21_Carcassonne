#include "vueformnom.h"
#include "ui_vueFormNom.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

//#include "controller.h"


VueFormNom::VueFormNom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VueFormNom)
{

    ui->setupUi(this);

    ui->nom_vLayout = new QVBoxLayout;

    MainWindow m;
    m.IntNBjoueur();

    /*
    for (int i=1; i <= m.getResultat_(); i++){


        // création ds espaces de label et des LineEdit pour les noms dans la fenêtre en fonction du nombre de joueur "i"
        ui->L_prenom = new QLabel("Nom joueur n° ",this);
        this->m_listLabel.append(ui->L_prenom);
        QString str ="";
        str = QString::number(i);
        ui->L_prenom->setText("Nom joueur n° "+str);
        ui->nom_vLayout->addWidget(ui->L_prenom);
        ui->L_prenom->move(50,i*30);


        ui->m_prenom = new QLineEdit("",this);
        this->m_listLineEdit.append(ui->m_prenom);
        ui->nom_vLayout->addWidget(ui->m_prenom);
        ui->m_prenom->move(200, i*30);

        QFormLayout *formLayout = new QFormLayout;

        QVBoxLayout *layout1 = new QVBoxLayout;
        layout1->addLayout(formLayout);


    }
*/
}

VueFormNom::~VueFormNom(){
    delete ui;
}

void VueFormNom::on_pushButton_2_clicked()
{
    //Controller* ctr = new Controller(int ());

}

