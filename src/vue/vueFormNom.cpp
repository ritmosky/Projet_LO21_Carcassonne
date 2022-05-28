#include "vueFormNom.h"
#include "vuePartie.h"
#include "ui_vueFormNom.h"
#include "../modele/controller.h"
#include <vector>
#include <iostream>


VueFormNom::VueFormNom(int& nJoueur, std::vector<int> listeNumExt, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VueFormNom),
    nbrJoueur(nJoueur),
    listeNumE(listeNumExt)
{
    ui->setupUi(this);


    ui->nom_vLayout = new QVBoxLayout;

    for (int i=1; i <= this->getNbrJoueur(); i++){
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

}

VueFormNom::~VueFormNom()
{
    delete ui;
}

void VueFormNom::on_pushButton_2_clicked()
{
    std::vector<std::string> listeNomJ(this->getNbrJoueur());
    for (int i = 0; i < this->getNbrJoueur(); i++){
        QString input = this->m_listLineEdit[i]->text(); // transformation de chaque input dans le QLineEdit en QString
        listeNomJ[i] = input.toStdString(); // on ajoute dans listeNomJ input transformé en std::string
    }

    Controller* ctr = new Controller(getNbrJoueur(), listeNomJ, this->listeNumE);
    VuePartie* partie = new VuePartie(ctr);
    partie->show();
}
