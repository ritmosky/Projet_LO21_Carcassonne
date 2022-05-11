#include "vuePartie.h"


VuePartie::VuePartie():QMainWindow()

{
    // Création de la fenêtre de NOM des joueur
    // Titre et taille de la fenêtre fixé.

    setWindowTitle("CARCASSONNE");
    setFixedSize(800,800);

     this->P_window = new QWidget(this);

}
VuePartie::~VuePartie()
{
}
