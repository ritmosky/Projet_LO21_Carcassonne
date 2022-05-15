#ifndef _MODEJEU_H
#define _MODEJEU_H

#include <iostream>
#include <string>
#include <vector>
#include "pioche.h"
#include "joueur.h"
#include "plateau.h"


class ModeJeu{

    public:
    
        virtual bool validationPlacementT(Tuile t);
        virtual bool validationPlacementM(Meeple m);

};


class Standard : public ModeJeu{
    public:
        ModeJeu();
        ~ModeJeu();
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};


class Riviere:public ModeJeu{
    public:
        ModeJeu();
        ~ModeJeu();
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};


class AubergesEtCathedrales:public ModeJeu{
    public:
        ModeJeu();
        ~ModeJeu();
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};

class Paysan: public ModeJeu{
    public:
        ModeJeu();
        ~ModeJeu();
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};




#endif