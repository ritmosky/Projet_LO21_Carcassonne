#ifndef PROJET_LO21_CARCASSONNE_PLATEAU_H
#define PROJET_LO21_CARCASSONNE_PLATEAU_H
#include<vector>
#include <iostream>

class Plateau{
private:
    std::vector<Tuile> tuiles;
    std::vector<Espace> espaces;
    int nbrEspaces;
    int nbrTuiles;

public:
    Plateau(int nbE, int nbT) : tuiles(nbT), espaces(nbE), nbrEspaces(nbE), nbrTuiles(nbT){}

    int getNbrEspaces() const{return nbrEspaces;}
    int getNbrTuiles() const{return nbrTuiles;}

    void setNbrTuiles(const int &nbrT) {this->nbrTuiles = nbrT;}
    void setNbrEspaces(const int &nbrE) {this->nbrEspaces = nbrE;}

    void ajouterTuiles(const Tuile& tuile);
    void ajouterEspace(const Espace& espace);
};


#endif //PROJET_LO21_CARCASSONNE_PLATEAU_H
