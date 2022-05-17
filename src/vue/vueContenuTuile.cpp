#include "vueContenuTuile.h"
#include "ui_vueContenuTuile.h"

VueContenuTuile::VueContenuTuile(TypesTuiles type,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile),
    typeTuile(type)
{
    ui->setupUi(this);
    setCouleur();
    setNom();
}

VueContenuTuile::~VueContenuTuile()
{
    delete ui;
}


void VueContenuTuile::setCouleur(){
    switch (this->getTypeTuile()) {
    case route:
        this->setStyleSheet("background-color: brown;font-size: 70pt;");
        break;
    case abbaye:
        this->setStyleSheet("background-color: yellow;font-size: 70pt;");
        break;
    case ville:
        this->setStyleSheet("background-color: orange;font-size: 70pt;");
        break;
    case champs:
        this->setStyleSheet("background-color: green;font-size: 70pt;");
        break;
    case rivière:
        this->setStyleSheet("background-color: blue;font-size: 70pt;");
        break;
    case auberge:
        this->setStyleSheet("background-color: purple;font-size: 70pt;");
        break;
    case cathédrale:
        this->setStyleSheet("background-color: golden;font-size: 70pt;");
        break;
    case jardin:
        this->setStyleSheet("background-color: yellow;font-size: 70pt;");
        break;
    default:
        this->setStyleSheet("background-color: black;font-size: 70pt;");
        break;
    }
}


void VueContenuTuile::setNom(){
    switch (this->getTypeTuile()) {
    case route:
        ui->nomTypeTuile->setText("ROUTE");
        break;
    case abbaye:
        ui->nomTypeTuile->setText("ABBAYE");
        break;
    case ville:
        ui->nomTypeTuile->setText("VILLE");
        break;
    case champs:
        ui->nomTypeTuile->setText("CHAMP");
        break;
    case rivière:
        ui->nomTypeTuile->setText("RIVIERE");
        break;
    case auberge:
        ui->nomTypeTuile->setText("AUBERGE");
        break;
    case cathédrale:
        ui->nomTypeTuile->setText("CATHEDRALE");
        break;
    case jardin:
        ui->nomTypeTuile->setText("JARDIN");
        break;
    default:
        ui->nomTypeTuile->setText("PAS DE TYPE");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);


}





