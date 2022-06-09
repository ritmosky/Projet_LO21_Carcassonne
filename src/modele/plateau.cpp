#include "plateau.h"


void Plateau::ajouterTuiles(Tuile* tuile) {
    this->tuiles.push_back(tuile);
}
void Plateau::ajouterEspace(Espace* esp) {
    this->espaces.push_back(esp);
}

void Plateau::supprimerEspace(Espace* esp) {
    for (auto it = espaces.begin(); it != espaces.end(); it++){
        if( *it == esp){
            espaces.erase(it);
            break;
        }
    }
}
Plateau::~Plateau(){
        
        for (auto tuile : tuiles)
        {
            delete tuile;
        }
        for (auto esp : espaces)
        {
            delete esp;
        }
    }

