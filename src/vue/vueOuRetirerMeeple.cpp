#include "vueOuRetirerMeeple.h"
#include "ui_vueOuRetirerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



VueOuRetirerMeeple::VueOuRetirerMeeple(VuePartie* partie,QWidget *parent):
    QDialog(parent),
    ui(new Ui::VueOuRetirerMeeple),
    partie(partie)
{
    ui->setupUi(this);
}


VueOuRetirerMeeple::~VueOuRetirerMeeple(){
    delete ui;
}



void VueOuRetirerMeeple::on_OK_clicked(){
    cout << "\n##### je cible la tuile en ligne = " << ui->ligne->value();
    cout << " et en colonne = " << ui->col->value();
    partie->updateVueTuileRemoveM(ui->ligne->value(),ui->col->value());
}
