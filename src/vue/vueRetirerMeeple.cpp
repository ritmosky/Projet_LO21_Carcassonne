#include "vueRetirerMeeple.h"
#include "ui_vueRetirerMeeple.h"
#include "QtWidgets/qpushbutton.h"
#include "vueTuile.h"
#include "modele/tuile.h"



VueRetirerMeeple::VueRetirerMeeple(VuePartie* part, QWidget *parent):
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
    cout << "\n##### Il y a un Espace complet\n";
    // ---------- Retrait du MEEPLE // ---------- //
    VueOuRetirerMeeple* affichage = new VueOuRetirerMeeple(partie,nullptr);
    affichage->show();
}


void VueRetirerMeeple::on_non_clicked(){
    cout << "\n##### Il n\'y a aucun Espace complet -> aucun meeple à retirer\n";
}
