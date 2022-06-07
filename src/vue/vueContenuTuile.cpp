#include "vueContenuTuile.h"
#include "ui_vueContenuTuile.h"

VueContenuTuile::VueContenuTuile(TypesTuiles type, bool bouc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile),
    typeTuile(type),
    bouclier(bouc)
{
    ui->setupUi(this);
    setNomCouleurSansM();
}

VueContenuTuile::VueContenuTuile(TypesTuiles type, bool bouc,int id, bool meeple, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile),
    typeTuile(type),
    bouclier(bouc),
    idJoueurMeeple(id),
    meeple(meeple)
{
    ui->setupUi(this);
    setNomCouleurAvecM(this-> idJoueurMeeple);
}


VueContenuTuile::~VueContenuTuile(){
    delete ui;
}


VueContenuTuile &VueContenuTuile::operator=(const VueContenuTuile &c){
    ui = c.ui;
    typeTuile = c.typeTuile;
    bouclier = c.bouclier;
    meeple = c.meeple;
    idJoueurMeeple = c.idJoueurMeeple;
    return *this;
}


void VueContenuTuile::setNomCouleurAvecM(const int& id){
    QString affichage;
    QString meeple = "\nM" + QString::number(id);
    switch (this->getTypeTuile()) {
    case route:
        affichage = "RO";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: brown;");
        break;
    case abbaye:
        affichage = "AB";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: yellow;");
        break;
    case ville:
        affichage = "VI";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        if (this->getBouclier() == true){
            ui->nomTypeTuile->setStyleSheet("text-decoration: underline;font-weight: bold;color :red;");
        }

        this->setStyleSheet("background-color: orange;");
        break;
    case champs:
        affichage = "CH";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        ui->nomTypeTuile->setStyleSheet("background-color: green;");
        break;
    case rivière:
        affichage = "RI";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: blue;");
        break;
    case auberge:
        affichage = "AU";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: purple;");
        break;
    case cathédrale:
        affichage = "CA";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: golden;");
        break;
    case jardin:
        affichage = "JA";
        affichage += meeple;
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: yellow;");
        break;
    default:
        affichage = "PAS DE TYPE";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: brown;");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);


}



void VueContenuTuile::setNomCouleurSansM(){
    QString affichage;
    switch (this->getTypeTuile()) {
    case route:
        affichage = "RO";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: brown;");
        break;
    case abbaye:
        affichage = "AB";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: yellow;");
        break;
    case ville:
        affichage = "VI";
        ui->nomTypeTuile->setText(affichage);
        if (this->getBouclier() == true){
            ui->nomTypeTuile->setStyleSheet("text-decoration: underline;font-weight: bold;color :red;");
        }

        this->setStyleSheet("background-color: orange;");
        break;
    case champs:
        affichage = "CH";
        ui->nomTypeTuile->setText(affichage);
        ui->nomTypeTuile->setStyleSheet("background-color: green;");
        break;
    case rivière:
        affichage = "RI";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: blue;");
        break;
    case auberge:
        affichage = "AU";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: purple;");
        break;
    case cathédrale:
        affichage = "CA";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: golden;");
        break;
    case jardin:
        affichage = "JA";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: yellow;");
        break;
    default:
        affichage = "PAS DE TYPE";
        ui->nomTypeTuile->setText(affichage);
        this->setStyleSheet("background-color: brown;");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);
}

