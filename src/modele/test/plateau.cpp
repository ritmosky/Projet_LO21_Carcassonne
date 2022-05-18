#include "plateau.h"


void Plateau::ajouterTuiles(Tuile* tuile) {
    this->tuiles.push_back(tuile);
}

void Plateau::ajouterEspace(Espace* espace) {
    this->espaces.push_back(espace);
}