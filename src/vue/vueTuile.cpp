#include "vueTuile.h"
#include "vueContenuTuile.h"
#include "ui_vueTuile.h"

VueTuile::VueTuile(Tuile tuile ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueTuile)
{
    ui->setupUi(this);
    setContenuTuile(tuile);
}

VueTuile::~VueTuile()
{
    delete ui;
}


void VueTuile::setContenuTuile(Tuile tuile){
    for (int i = 0; i<9; i++){

    }
    ui->grilleContenuTuile->addWidget(
                // Premier paramètre : le Widget vueContenuTuile
                // Second paramètre : la ligne
                // 3ème paramètre : la colonne
                );
}
