#include "vueContenuTuile.h"
#include "ui_vueContenuTuile.h"

VueContenuTuile::VueContenuTuile(int type, int numPlacement,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueContenuTuile),
    typeTuile(type),
    numPlacement(numPlacement)
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
    case 1:
        this->setStyleSheet("background-color: brown;font-size: 70pt;");
        break;
    case 2:
        this->setStyleSheet("background-color: yellow;font-size: 70pt;");
        break;
    case 3:
        this->setStyleSheet("background-color: orange;font-size: 70pt;");
        break;
    case 4:
        this->setStyleSheet("background-color: green;font-size: 70pt;");
        break;
    case 5:
        this->setStyleSheet("background-color: blue;font-size: 70pt;");
        break;
    default:
        this->setStyleSheet("background-color: black;font-size: 70pt;");
        break;
    }
}


void VueContenuTuile::setNom(){
    switch (this->getTypeTuile()) {
    case 1:
        ui->nomTypeTuile->setText("ROUTE");
        break;
    case 2:
        ui->nomTypeTuile->setText("ABBAYE");
        break;
    case 3:
        ui->nomTypeTuile->setText("VILLE");
        break;
    case 4:
        ui->nomTypeTuile->setText("CHAMP");
        break;
    case 5:
        ui->nomTypeTuile->setText("RIVIERE");
        break;
    default:
        ui->nomTypeTuile->setText("PAS DE TYPE");
        break;
    }
    ui->nomTypeTuile->setAlignment(Qt::AlignCenter);


}





