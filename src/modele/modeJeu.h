#ifndef _MODEJEU_H
#define _MODEJEU_H

#include <iostream>
#include <string>
#include <vector>
#include "tuile.h"
#include "meeple.h"
#include "espace.h"
#include  "plateau.h"


/* Pour le placement des tuiles, seul l'extension rivière est différente

Pour le placement des meeples:
-Standard: on peut placer partout sauf sur dans les champs (faite)

-Auberge et cathédrales : on ne peut pas placer sur une auberge ou une cathédrale (faite)

-Riviere : On ne peut pas placer de meeple sur une tuile de type rivière (faite)

-Paysan : couche (récuperer que à la fin de la partie) ou pas couche

-Abbe :L’abbé ne peut être posé que sur une abbaye ou un jardin,
-tandis que le meeple selon les règles habituelles peut être posé sur
n’importe quelle section de tuile (mais pas sur le jardin).



 */

using namespace std;



class ModeJeu{

    public:
        virtual bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau) = 0;
        virtual bool validationPlacementM(const TypesTuiles& tp,Meeple *m,Espace *e) = 0;
        virtual void affichage() = 0;

};

// ------------------------- EXTENSION STANDARD --------------------------------------

class Standard : public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){

         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }

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
        bool validationPlacementM(const TypesTuiles& tp,Meeple *m ,Espace *e){

            if(e==NULL){
                return false;
            }

            if(!e->isFree() || tp==TypesTuiles::champs){
                return false;
            }
            return true;
        }

        void affichage(){
            cout<<"******************************Standard****************************************"<<endl;
        }
};



// ------------------------- EXTENSION RIVIERE --------------------------------------

class Riviere : public ModeJeu{

    public:
bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){

                if((newTuile.getContenu(0)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(1)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(2)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(3)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(4)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(5)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(6)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(7)!=TypesTuiles::rivière) &&
                 (newTuile.getContenu(8)!=TypesTuiles::rivière)){ return true; }


         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }

        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
                if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)
                || (newTuile.getContenu(1)!=TypesTuiles::rivière)
                || (plateau->existeTuile(x,y-1)->getContenu(5)!=TypesTuiles::rivière)
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
                if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)
                || (newTuile.getContenu(5)!=TypesTuiles::rivière)
                || (plateau->existeTuile(x,y+1)->getContenu(1)!=TypesTuiles::rivière)
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
                || (newTuile.getContenu(7)!=TypesTuiles::rivière)
                || (plateau->existeTuile(x-1,y)->getContenu(3)!=TypesTuiles::rivière)
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
                if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)
                || (newTuile.getContenu(3)!=TypesTuiles::rivière)
                || (plateau->existeTuile(x+1,y)->getContenu(7)!=TypesTuiles::rivière)
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

    bool validationPlacementM(const TypesTuiles& tp,Meeple *m ,Espace *e){
        if(e==NULL){
            return false;
        }
        if(!e->isFree() || tp==TypesTuiles::rivière){

            return false;
        }
        return true;
    }

    void affichage(){
        cout << " Riviere " << endl;
    }
};

//EXTENSION AUBERGES ET CATHEDRALES

class AubergesEtCathedrales:public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){



         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }

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
        // un meeple ne peut pas occuper une auberge ou une cathédrale
        bool validationPlacementM(const TypesTuiles& tp,Meeple *m ,Espace *e){
            if(e==NULL){
                return false;
            }

            if(!e->isFree() || tp==TypesTuiles::auberge || tp==TypesTuiles::cathédrale){
                return false;
            }
            return true;
        }

        void affichage(){
            cout<<"AubergesEtCathedrales"<<endl;
        }
};


// ------------------------- EXTENSION PAYSAN --------------------------------------

class Paysan: public ModeJeu{
    public:
        bool validationPlacementT(Tuile newTuile,int x,int y,Plateau *plateau){


         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }


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
        bool validationPlacementM(const TypesTuiles& tp,Meeple *m ,Espace *e){
            if(e==NULL){
                return false;
            }
            if(!e->isFree()) {
                return false;
            }
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

         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }

 
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

       bool validationPlacementM(const TypesTuiles& tp,Meeple *m ,Espace *e){
           if(e==NULL){
               return false;
           }

            //Si un meeple est déjà présent sur l'espace
            if(!e->isFree()){
                return false;
            }

            //L’abbé ne peut être posé que sur une abbaye ou un jardin
            if(m->getType().getNom()==NomMeeple::abbe){
                if(tp==TypesTuiles::abbaye || tp==TypesTuiles::jardin){
                    return true;
                }
                else{
                    return false;
                }
            }
            //le meeple peut être posé sur n'importe ou sauf sur le jardin
            else{
                if(tp==TypesTuiles::jardin){
                    return false;
                }
                else{
                    return true;
                }
            }
            return true;
        }
        void affichage(){
            cout<<"Abbe"<<endl;
        }
};

#endif
