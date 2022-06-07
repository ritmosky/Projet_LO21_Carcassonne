#include "vueRetirerMeeple.h"
#include "ui_vueRetirerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



VueRetirerMeeple::VueRetirerMeeple(QWidget *parent, VuePartie* part):
    QDialog(parent),
    ui(new Ui::VueRetirerMeeple),
    partie(part)
{
    ui->setupUi(this);
}


VueRetirerMeeple::~VueRetirerMeeple(){
    delete ui;
}



void VueRetirerMeeple::on_oui_clicked(){
    cout << "\n Il y a un Espace complet";
    // ---------- Retrait du MEEPLE // ---------- //
    VueOuRetirerMeeple* affichage = new VueOuRetirerMeeple(nullptr,partie);
    affichage->show();
}


void VueRetirerMeeple::on_non_clicked(){
    cout << "\n Il n\'y a aucun Espace complet";
}

