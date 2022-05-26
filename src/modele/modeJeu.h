#ifndef _MODEJEU_H
#define _MODEJEU_H

#include <iostream>
#include <string>
#include <vector>
#include "tuile.h"
#include "Meeple.h"
#include "espace.h"
#include  "plateau.h"


/* Pour le placement des tuiles 
Auberges et cathédrales : pareil que standard
Paysans : pareil que standard
Abbe : pareil que standard
riviere : Vous ne pouvez pas faire tourner une rivière deux fois de
 suite dans la même direction (un demi-tour immédiat)
 */

using namespace std;



class ModeJeu{

    public:
        virtual bool validationPlacementT(Tuile t ) = 0;
        virtual bool validationPlacementM(Meeple m,Espace e) = 0;
        virtual void affichage() = 0;

};

// ------------------------- EXTENSION STANDARD --------------------------------------

class Standard : public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){
        if(plateau->existeTuile(x,y-1)){
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }
        

        //Voisin du bas
        
        if(plateau->existeTuile(x,y+1)){
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }
     
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }
        
        return true;

    }
        bool validationPlacementM(Meeple m ,Espace e){
            return true;
        }
        void affichage(){
            cout<<"Standard"<<endl;
        }
};



// ------------------------- EXTENSION RIVIERE --------------------------------------

class Riviere:public ModeJeu{
    public:
bool validationPlacementRiviere(Tuile newTuile,int x,int y,Plateau *plateau){

        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            cout << " JE PASSE ICI " << endl;
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5) 
            || (newTuile.getContenu(1)==plateau->existeTuile(x,y-1)->getContenu(5) 
                && newTuile.getContenu(3)==plateau->existeTuile(x,y-1)->getContenu(3)
                && newTuile.getContenu(3)==TypesTuiles::rivière
                && newTuile.getContenu(1)==TypesTuiles::rivière)
            || (newTuile.getContenu(1)==plateau->existeTuile(x,y-1)->getContenu(5)
                && newTuile.getContenu(7)==plateau->existeTuile(x,y-1)->getContenu(7)
                && newTuile.getContenu(7)==TypesTuiles::rivière
                && newTuile.getContenu(1)==TypesTuiles::rivière)){
                return false;
            }
        }  

        //Voisin du bas
        
        if(plateau->existeTuile(x,y+1)){
            cout << " JE PASSE ICI " << endl;
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)
            || (newTuile.getContenu(5)==plateau->existeTuile(x,y+1)->getContenu(1)
                && newTuile.getContenu(3)==plateau->existeTuile(x,y+1)->getContenu(3) 
                && newTuile.getContenu(5)==TypesTuiles::rivière
                && newTuile.getContenu(7)==TypesTuiles::rivière)
            || (newTuile.getContenu(5)==plateau->existeTuile(x,y+1)->getContenu(1)
                && newTuile.getContenu(7)==plateau->existeTuile(x,y+1)->getContenu(7)
                && newTuile.getContenu(5)==TypesTuiles::rivière
                && newTuile.getContenu(3)==TypesTuiles::rivière)){
                return false;
            }
        }
     
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)
            || (newTuile.getContenu(7)==plateau->existeTuile(x-1,y)->getContenu(3)
                && newTuile.getContenu(1)==plateau->existeTuile(x-1,y)->getContenu(1)
                && newTuile.getContenu(7)==TypesTuiles::rivière
                && newTuile.getContenu(1)==TypesTuiles::rivière)
            || (newTuile.getContenu(7)==plateau->existeTuile(x-1,y)->getContenu(3)
                && newTuile.getContenu(5)==plateau->existeTuile(x-1,y)->getContenu(5)
                && newTuile.getContenu(5)==TypesTuiles::rivière
                && newTuile.getContenu(7)==TypesTuiles::rivière)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            cout << " JE PASSE ICI " << endl;
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)
            || (newTuile.getContenu(3)==plateau->existeTuile(x+1,y)->getContenu(7)
                && newTuile.getContenu(1)==plateau->existeTuile(x+1,y)->getContenu(1)
                && newTuile.getContenu(3)==TypesTuiles::rivière
                && newTuile.getContenu(1)==TypesTuiles::rivière)
            || (newTuile.getContenu(3)==plateau->existeTuile(x+1,y)->getContenu(7)
                && newTuile.getContenu(5)==plateau->existeTuile(x+1,y)->getContenu(5)
                && newTuile.getContenu(3)==TypesTuiles::rivière
                && newTuile.getContenu(5)==TypesTuiles::rivière)){
                return false;
            }
        }
        
        return true;

    }
};

//EXTENSION AUBERGES ET CATHEDRALES

class AubergesEtCathedrales:public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){
        if(plateau->existeTuile(x,y-1)){
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }
        
        //Voisin du bas
        
        if(plateau->existeTuile(x,y+1)){
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }
     
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }
        
        return true;

    }
        bool validationPlacementM(Meeple m ,Espace e){
            return true;
        }
        void affichage(){
            cout<<"AubergesEtCathedrales"<<endl;
        }
};


// ------------------------- EXTENSION PAYSAN --------------------------------------

class Paysan: public ModeJeu{
    public:
        bool validationPlacement(Tuile newTuile,int x,int y,Plateau *plateau){
        if(plateau->existeTuile(x,y-1)){
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }
        

        //Voisin du bas
        
        if(plateau->existeTuile(x,y+1)){
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }
     
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }
        
        return true;

    }
        bool validationPlacementM(Meeple m ,Espace e){
            return true;
        }
        void affichage(){
            cout<<"Paysan"<<endl;
        }
};



// ------------------------- EXTENSION ABBE --------------------------------------


class Abbe : public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){
        if(plateau->existeTuile(x,y-1)){
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }
        

        //Voisin du bas
        
        if(plateau->existeTuile(x,y+1)){
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }
     
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }
        
        return true;

    }
        bool validationPlacementM(Meeple m ,Espace e){
            return true;
        }
        void affichage(){
            cout<<"Abbe"<<endl;
        }
};

#endif