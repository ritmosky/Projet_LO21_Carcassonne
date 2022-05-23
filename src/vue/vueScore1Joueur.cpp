#include "vueScore1Joueur.h"
#include "ui_vueScore1Joueur.h"

VueScore1Joueur::VueScore1Joueur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueScore1Joueur)
{
    ui->setupUi(this);
    ui->nom->setText("test");
}

VueScore1Joueur::~VueScore1Joueur()
{
    delete ui;
}

