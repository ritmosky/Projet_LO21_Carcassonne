
#ifndef meeple_h
#define meeple_h


#include <stdio.h>
#include <iostream>
#include "tuile.h"



using namespace std;



// Definition enum NomMeeple
enum NomMeeple {
    chevalier,
    paysan,
    abbe,
    voleur,
    rien
};



// Convertir Enum en String
static const char* NomMeeple_str[] = { "chevalier", "paysan", "abbe", "voleur" };



// CLASSE MÈRE
class TypeMeeple {

    private:

        NomMeeple nom;

    public:

        TypeMeeple(const NomMeeple& name=rien): nom(name){}  // constructeur

        inline const NomMeeple& getNom() const { return nom; }
        inline void setNom(const NomMeeple& name) { nom = name; }
};



ostream& operator<<(ostream& f, const TypeMeeple& Tm);




// CLASSE FILLE
class Meeple {

    private:

        ContenanceTuile* contenanceTuile;
        TypeMeeple type;
        int id_joueur;

    public:

        Meeple(): contenanceTuile(nullptr) {}

        Meeple(const Meeple&) = delete;
        Meeple& operator=(const Meeple&) = delete;

        inline bool isUsed() const { return contenanceTuile != nullptr; } // 1 si nullptr 0 sinon
        inline const TypeMeeple& getType() const { return type; }
        inline const int getIdJoueur() const { return id_joueur; }
        inline const ContenanceTuile* getContenanceTuile() const { return contenanceTuile; }

        inline void setType(const TypeMeeple& ty) { type = ty; };
        inline void setType(const NomMeeple& name) { type.setNom(name); };
        inline void setIdJoueur(int i) { id_joueur = i; }
        inline void setContenance(ContenanceTuile& ct) { contenanceTuile = &ct; }

};


ostream& operator<<(ostream& f, const Meeple& M);


#endif

