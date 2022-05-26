#include "vueScore1Joueur.h"
#include "ui_vueScore1Joueur.h"
#include <QString>

VueScore1Joueur::VueScore1Joueur(std::string nomJ, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueScore1Joueur),
    nom(nomJ)
{
    ui->setupUi(this);
    ui->nom->setText(QString::fromStdString(nomJ));
}

VueScore1Joueur::~VueScore1Joueur()
{
    delete ui;
}





void VueScore1Joueur::on_ajouterPoints_clicked()
{
    ui->affichageScore->display(ui->affichageScore->intValue()+1);
}


void VueScore1Joueur::on_retirerPoints_clicked()
{
    ui->affichageScore->display(ui->affichageScore->intValue()-1);
}

