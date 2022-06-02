#include "vueContenuTuile.h"
#include "ui_vueContenuTuile.h"

VueContenuTuile::VueContenuTuile(TypesTuiles type, bool bouc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile),
    typeTuile(type),
    bouclier(bouc)
{
    ui->setupUi(this);
//    this->resize(75,75);
//    ui->nomTypeTuile->resize(75,75);
    setNomCouleur();
}

VueContenuTuile::~VueContenuTuile()
{
    delete ui;
}


void VueContenuTuile::setNomCouleur(){
    switch (this->getTypeTuile()) {
    case route:
        ui->nomTypeTuile->setText("RO");
        this->setStyleSheet("background-color: brown;");
        break;
    case abbaye:
        ui->nomTypeTuile->setText("AB");
        this->setStyleSheet("background-color: yellow;");
        break;
    case ville:
        ui->nomTypeTuile->setText("VI");
        if (this->getBouclier() == true){
            ui->nomTypeTuile->setStyleSheet("text-decoration: underline;font-weight: bold;color :red;");
        }

        this->setStyleSheet("background-color: orange;");
        break;
    case champs:
        ui->nomTypeTuile->setText("CH");
        ui->nomTypeTuile->setStyleSheet("background-color: green;");
        break;
    case rivière:
        ui->nomTypeTuile->setText("RI");
        this->setStyleSheet("background-color: blue;");
        break;
    case auberge:
        ui->nomTypeTuile->setText("AU");
        this->setStyleSheet("background-color: purple;");
        break;
    case cathédrale:
        ui->nomTypeTuile->setText("CA");
        this->setStyleSheet("background-color: golden;");
        break;
    case jardin:
        ui->nomTypeTuile->setText("JA");
        this->setStyleSheet("background-color: yellow;");
        break;
    default:
        ui->nomTypeTuile->setText("PAS DE TYPE");
        this->setStyleSheet("background-color: brown;");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);


}





