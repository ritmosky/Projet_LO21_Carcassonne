#include "plateau.h"


void Plateau::ajouterTuiles(const Tuile* tuile) {
    this->tuiles.push_back(tuile);
}

void Plateau::ajouterEspace(const Espace* espace) {
    this->espaces.push_back(espace);
}