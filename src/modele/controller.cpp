#include "modeJeu.h"
#include "controller.h"
#define NBRE_MEEPLE_MAX 7




    Controller::Controller(int nj):nbJoueurs(nj){
        tour = 0;
        plateau = new Plateau(0);
        pioche = new Pioche(extensions);
    }

    Controller::Controller(int nj,vector<string> listeNomJoueur,vector<int> listeNumExtensions):nbJoueurs(nj),extensions(listeNumExtensions){
        tour = 0;
        for(int i=0;i<nbJoueurs;i++){
            listeJoueurs.push_back(new Joueur(i,NBRE_MEEPLE_MAX,""));
            listeJoueurs[i]->addName(listeNomJoueur[i]);
            }
        plateau = new Plateau(0);
        pioche = new Pioche(extensions);
    }

    void Controller::placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y){
        Tuile *t = plateau->existeTuile(x,y);
        ContenanceTuile contenance = t->getContenance(i);
        m->setContenance(contenance);
        m->setIdJoueur(j->getId());
        m->setType(tm);
        cout << *m << endl;
        j->removeMeeple();
    }

    void Controller::placementTuile(Tuile *newTuile,int x,int y){
        newTuile->setPosX(x);
        newTuile->setPosY(y);
        plateau->ajouterTuiles(newTuile);
        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            newTuile->setVoisinHaut(plateau->existeTuile(x,y-1));
            plateau->existeTuile(x,y-1)->setVoisinBas(newTuile);
        }
        //Voisin du bas
        if(plateau->existeTuile(x,y+1)){
            newTuile->setVoisinBas(plateau->existeTuile(x,y+1));
            plateau->existeTuile(x,y+1)->setVoisinHaut(newTuile);
        }
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            newTuile->setVoisinGauche(plateau->existeTuile(x-1,y));
            plateau->existeTuile(x-1,y)->setVoisinDroite(newTuile);
        }
        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            newTuile->setVoisinDroite(plateau->existeTuile(x+1,y));
            plateau->existeTuile(x+1,y)->setVoisinGauche(newTuile);
        }
    }

    bool Controller::placementTuileAutorise(Tuile newTuile){
        //Parcourir toutes les tuiles du plateau présent dans un vecteur de tuiles
        for(Tuile *tuile : plateau->getTuiles()){
            //Voisin du haut
            if(tuile->getVoisinHaut() == NULL){
                //On considère les 4 rotations de la tuile
                for(int rotation=0;rotation<4; rotation++){
                    //On regarde si la tuile est compatible
                    if(estCompatible(newTuile,tuile->getX(),tuile->getY()-1)){
                        //On peut la placer
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin du bas
            if(tuile->getVoisinBas() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile,tuile->getX(),tuile->getY()+1)){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de gauche)
            if(tuile->getVoisinGauche() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile,tuile->getX()-1,tuile->getY())){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de droite
            if(tuile->getVoisinDroite() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getX()+1,tuile->getY())){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
        }

    return false;
    }

     bool Controller::estCompatible(Tuile newTuile,int x,int y){

         //s'il aucun voisin

         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }
         
          //Si on clique sur la meme tuile
         std::vector<Tuile*> tuiles = plateau->getTuiles();
         for(Tuile* t : tuiles){
            if(t->getX()==x && t->getY()==y){
                return false;
            }
         }

         cout << "****************************" << endl;
        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            cout << " voisin haut "<< endl;
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }


        //Voisin du bas
        if(plateau->existeTuile(x,y+1)){
                        cout << " voisin bas" << endl;
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }

        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
                        cout << " voisin gauche "<< endl;
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
                        cout << " voisin droite "<< endl;
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }

        return true;

    }

     //Tour suivant
    void Controller::nextTour(){
        if(pioche->estVide()==true){
            cout << " FINISHED ";
           return ;
        }
        else{
            tour++;
        }
    }


/* ************************************* TEST**************************************************** */

         // test placement tuile avec plateau
        bool Controller::placementTuileAutorise(Tuile newTuile,Plateau *plateau){
        //Parcourir toutes les tuiles du plateau
        for(Tuile *tuiles5 : plateau->getTuiles()){
            if(tuiles5->getVoisinHaut() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile,tuiles5->getX(),tuiles5->getY()-1,plateau)){
                        cout << " PLACEMENT DU HAUT AUTORISE " << endl;
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
               cout << " voisin du haut fait" << endl;

            //Voisin du bas
            if(tuiles5->getVoisinBas() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuiles5->getX(),tuiles5->getY()+1,plateau)){
                        cout << " PLACEMENT DU BAS AUTORISE " << endl;
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
            cout << " voisin du bas fait" << endl;

            //Voisin de gauche
            if(tuiles5->getVoisinGauche() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuiles5->getX()-1,tuiles5->getY(),plateau)){
                        cout << " PLACEMENT DE GAUCHE AUTORISE " << endl;
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
               cout << " voisin de gauche fait" << endl;
            //Voisin de droite
            if(tuiles5->getVoisinDroite() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuiles5->getX()+1,tuiles5->getY(),plateau)){
                        cout << " PLACEMENT DE DROITE AUTORISE " << endl;
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
        }
           cout << "voisin de droite fait" << endl;

    return false;
    }


     //test compatible avec plateau
     bool Controller::estCompatible(Tuile newTuile,int x,int y,Plateau *plateau){
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




/*
void Controller::Abbaye(State s) {
        int score = 1;
        for (Tuile* tuile : plateau->getTuiles()) {
            TypesTuiles const typetuile = tuile->getContenu(8);
            ContenanceTuile contenance = tuile->getContenance(8);
            if (typetuile == TypesTuiles::abbaye || contenance.hasMeeple()) {
                // HAUT GAUCHE
                if ((tuile->getVoisinHaut()->getVoisinGauche())!= NULL) {
                    score++;
                }

                // HAUT
                if ((tuile->getVoisinHaut()) != NULL) {
                    score++;
                }

                // HAUT DROITE
                if ((tuile->getVoisinHaut()->getVoisinDroite()) != NULL) {
                    score++;
                }

                // GAUCHE
                if ((tuile->getVoisinGauche()) != NULL) {
                    score++;
                }

                // DROITE
                if ((tuile->getVoisinDroite()) != NULL) {
                    score++;
                }

                // BAS GAUCHE
                if ((tuile->getVoisinBas()->getVoisinGauche())!= NULL) {
                    score++;
                }

                // BAS DROITE
                if ((tuile->getVoisinBas()->getVoisinDroite()) != NULL) {
                    score++;
                }

                // BAS
                if ((tuile->getVoisinBas()) != NULL) {
                    score++;
                }

                if (score == 9 || s == GAME_OVER) {
                    contenance.getJoueur().addScore(score);
                }
            }
            score = 1;
        }
    }

    */

        /*
    //Comptage des scores
    void Controller::compteScore(State state){
        if (state == GAME_OVER){
           compteScore(TypesTuiles::champs, state);
        }
        compteScore(TypesTuiles::ville, state);
        compteScore(TypesTuiles::route, state); // à implémenter une méthode compte score pour les routes et villes
        compteScoreAbbaye(state);
    }
*/

bool Controller::validationPlacementRiviere(Tuile newTuile,int x,int y,Plateau *plateau){

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

     void Controller::placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y,Plateau *plateau){
        Tuile *t = plateau->existeTuile(x,y);
        ContenanceTuile contenance = t->getContenance(i);
        m->setContenance(contenance);
        m->setIdJoueur(j->getId());
        m->setType(tm);
        cout << *m << endl;
        j->removeMeeple();
    }

    void Controller::placementTuile(Tuile *newTuile,int x,int y,Plateau *plateau){
        newTuile->setPosX(x);
        newTuile->setPosY(y);
        plateau->ajouterTuiles(newTuile);
        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            newTuile->setVoisinHaut(plateau->existeTuile(x,y-1));
            plateau->existeTuile(x,y-1)->setVoisinBas(newTuile);
        }
        //Voisin du bas
        if(plateau->existeTuile(x,y+1)){
            newTuile->setVoisinBas(plateau->existeTuile(x,y+1));
            plateau->existeTuile(x,y+1)->setVoisinHaut(newTuile);
        }
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            newTuile->setVoisinGauche(plateau->existeTuile(x-1,y));
            plateau->existeTuile(x-1,y)->setVoisinDroite(newTuile);
        }
        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            newTuile->setVoisinDroite(plateau->existeTuile(x+1,y));
            plateau->existeTuile(x+1,y)->setVoisinGauche(newTuile);
        }
    }
