#ifndef _MODEJEU_H
#define _MODEJEU_H

#include <iostream>
#include <string>
#include <vector>
#include "tuile.h"
#include "Meeple.h"
using namespace std;



class ModeJeu{

    public:
        ModeJeu(){
            cout<<"ModeJeu"<<endl;
        }
        virtual bool validationPlacementT(Tuile t);
        virtual bool validationPlacementM(Meeple m);

};


class Standard : public ModeJeu{
    public:
        Standard(){
            cout<<"Standard"<<endl;
        }
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};


class Riviere:public ModeJeu{
    public:
        Riviere(){
            cout<<"Riviere"<<endl;
        }
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};


class AubergesEtCathedrales:public ModeJeu{
    public:
        AubergesEtCathedrales(){
            cout<<"AubergesEtCathedrales"<<endl;
        }
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};

class Paysan: public ModeJeu{
    public:
        Paysan(){
            cout<<"Paysan"<<endl;
        }
        bool validationPlacementT(Tuile t);
        bool validationPlacementM(Meeple m);
};




#endif