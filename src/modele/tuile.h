//
//  Tuiles.h
//  Caracassonne
//
//  Created by Massil on 07/05/2022.
//

#ifndef Tuiles_h
#define Tuiles_h

#include <stdio.h>
#include <vector>
#include<iostream>


using namespace std;

// Definition enum TypesTuiles
enum TypesTuiles {
    route,
    abbaye,
    ville,
    champs,
    rivière,
    auberge,
    cathédrale,
    jardin,
    droute
};



// Convertir Enum en String
static const char* TypesTuiles_str[] = { "Route", "Abbaye", "Ville", "Champs", "Rivière", "Auberge", "Cathédrale", "Jardin", "DoubleRoute" };


class ContenanceTuile{

private :
    friend class Pioche;

    int numPlacement;
    TypesTuiles type;
    bool bouclier;

public:
    ContenanceTuile(const TypesTuiles t, const int n): type(t), numPlacement(n), bouclier(false){;}
    ContenanceTuile() = default;
    inline const TypesTuiles& getType() const {return type;}
    inline const int getNumPlacement() const {return numPlacement;}
    const bool getBouclier() const { return bouclier; }
    void setBouclier();





};

class Tuile {

private:
    Tuile* voisin_haut;
    Tuile* voisin_bas;
    Tuile* voisin_gauche;
    Tuile* voisin_droite;
    int posX;
    int posY;
    vector<ContenanceTuile> contenance;


public :
    Tuile(const vector<ContenanceTuile>& c);
    inline const int getX() const {return posX;}
    inline const int getY() const {return posY;}
    const vector<ContenanceTuile> getContenance() const {return contenance; }
    const ContenanceTuile getContenance(int i) const {return contenance[i]; }
    const TypesTuiles& getContenu(int i) const { return contenance[i].getType() ; }
    void changerOrientation();

    Tuile& operator=(const Tuile&)= delete;




};

ostream& operator<<(ostream& f, const Tuile& T);
ostream& operator<<(ostream& f, const ContenanceTuile& T);


#endif /* Tuiles_h */