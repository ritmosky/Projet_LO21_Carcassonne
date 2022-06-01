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
        ui->nomTypeTuile->setText("ROUTE");
        ui->nomTypeTuile->setStyleSheet("background-color: brown;");
        break;
    case abbaye:
        ui->nomTypeTuile->setText("ABBAYE");
        ui->nomTypeTuile->setStyleSheet("background-color: yellow;");
        break;
    case ville:
        ui->nomTypeTuile->setText("VILLE");
        ui->nomTypeTuile->setStyleSheet("background-color: orange;");
        break;
    case champs:
        ui->nomTypeTuile->setText("CHAMP");
        ui->nomTypeTuile->setStyleSheet("background-color: green;");
        break;
    case rivière:
        ui->nomTypeTuile->setText("RIVIERE");
        ui->nomTypeTuile->setStyleSheet("background-color: blue;");
        break;
    case auberge:
        ui->nomTypeTuile->setText("AUBERGE");
        ui->nomTypeTuile->setStyleSheet("background-color: purple;");
        break;
    case cathédrale:
        ui->nomTypeTuile->setText("CATHEDRALE");
        ui->nomTypeTuile->setStyleSheet("background-color: golden;");
        break;
    case jardin:
        ui->nomTypeTuile->setText("JARDIN");
        ui->nomTypeTuile->setStyleSheet("background-color: yellow;");
        break;
    default:
        ui->nomTypeTuile->setText("PAS DE TYPE");
        ui->nomTypeTuile->setStyleSheet("background-color: brown;");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);


}





