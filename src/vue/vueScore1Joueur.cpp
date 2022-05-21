#include "vueScore1Joueur.h"
#include "ui_vueScore1Joueur.h"

VueScore1Joueur::VueScore1Joueur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueScore1Joueur)
{
    ui->setupUi(this);
    this->autoFillBackground();
}

VueScore1Joueur::~VueScore1Joueur()
{
    delete ui;
}

