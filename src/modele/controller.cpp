#include "modeJeu.h"
#include "controller.h"
#define NBRE_MEEPLE_MAX 7


//Il faut rajouter les setter pour les vosins et les posX et posY
// Rajouter getTuiles() permettant de récupérer la liste des tuiles présentes sur le plateau
//tableau modedeJeu (template method)


Controller::Controller(int nj):nbJoueurs(nj){
    setState(GAME_MENU);
    tour = 0;
}

void Controller::placementMeeple(Joueur* j,Meeple* m,TypeMeeple tm,int i,int x,int y,Plateau *plateau){
    Tuile *t = plateau->existeTuile(x,y);
    ContenanceTuile contenance = t->getContenance(i);
    m->setContenance(contenance);
    m->setIdJoueur(j->getId());
    m->setType(tm);
    cout << *m;
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
    //Voisin du haut
    if(plateau->existeTuile(x,y-1)){
        if(newTuile.getContenu(0)!=plateau->existeTuile(x,y-1)->getContenu(6)
           || newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)
           || newTuile.getContenu(2)!=plateau->existeTuile(x,y-1)->getContenu(4) ){
            return false;
        }
    }


    //Voisin du bas

    if(plateau->existeTuile(x,y+1)){
        if(newTuile.getContenu(6)!=plateau->existeTuile(x,y+1)->getContenu(0)
           || newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)
           || newTuile.getContenu(4)!=plateau->existeTuile(x,y+1)->getContenu(2) ){
            return false;
        }
    }

    //Voisin de gauche
    if(plateau->existeTuile(x-1,y)){
        if(newTuile.getContenu(0)!=plateau->existeTuile(x-1,y)->getContenu(2)
           || newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)
           || newTuile.getContenu(6)!=plateau->existeTuile(x-1,y)->getContenu(4)){
            return false;
        }
    }

    //Voisin de droite
    if(plateau->existeTuile(x+1,y)){
        if(newTuile.getContenu(2)!=plateau->existeTuile(x+1,y)->getContenu(0)
           || newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)
           || newTuile.getContenu(4)!=plateau->existeTuile(x+1,y)->getContenu(6)){
            return false;
        }
    }

    return true;

}


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
        if(newTuile.getContenu(0)!=plateau->existeTuile(x,y-1)->getContenu(6)
           || newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)
           || newTuile.getContenu(2)!=plateau->existeTuile(x,y-1)->getContenu(4) ){
            return false;
        }
    }


    //Voisin du bas

    if(plateau->existeTuile(x,y+1)){
        if(newTuile.getContenu(6)!=plateau->existeTuile(x,y+1)->getContenu(0)
           || newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)
           || newTuile.getContenu(4)!=plateau->existeTuile(x,y+1)->getContenu(2) ){
            return false;
        }
    }

    //Voisin de gauche
    if(plateau->existeTuile(x-1,y)){
        if(newTuile.getContenu(0)!=plateau->existeTuile(x-1,y)->getContenu(2)
           || newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)
           || newTuile.getContenu(6)!=plateau->existeTuile(x-1,y)->getContenu(4)){
            return false;
        }
    }

    //Voisin de droite
    if(plateau->existeTuile(x+1,y)){
        if(newTuile.getContenu(2)!=plateau->existeTuile(x+1,y)->getContenu(0)
           || newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)
           || newTuile.getContenu(4)!=plateau->existeTuile(x+1,y)->getContenu(6)){
            return false;
        }
    }

    return true;

}





//Tour suivant
void Controller::nextTour(){
    if(pioche->getNbTuiles() == 0){
        setState(GAME_OVER);
    }
    else{
        tour++;
        setState(PLACING_TILE);
    }
}


//ok
void Controller::setState(State state){

    this->state = state;

    switch(state){
        case GAME_MENU:
            //Initialisation du mode de jeu et des joueurs, on initialise les deux attributs mode de jeu et joueur
            //modeJeu = new ModeJeu[5];
            // modeJeu[0] = new Standard();
            // modeJeu[1] = new Riviere();
            //modeJeu[2] = new AubergesEtCathedrales();
            // modeJeu[3] = new Paysan();

            for(int i=0;i<nbJoueurs;i++){
                listeJoueurs.push_back(new Joueur(i,NBRE_MEEPLE_MAX));
            }
            setState(GAME_START);
            break;

        case GAME_START:{
            //initialisation le plateau,la pioche de tuile, et de lancer la partie, avec la vue Qt du plateau
            plateau = new Plateau(0);
            //La pioche doit être initialisée avec le mode de jeu
            vector<int> mode = {1,2};
            pioche = new Pioche(mode);
            cout << pioche->getNbTuiles() << endl;
            setState(PLACING_TILE);
            break;
        }


        case PLACING_TILE:
            //on place une tuile sur le plateau, avec la vue Qt du plateau
            if(!placementTuileAutorise(pioche->Piocher())){
                //On supprime la tuile de la pioche
            }
            setState(PLACING_MEEPLE);
            break;

        case PLACING_MEEPLE:
            //Si le joueur actuelle a 0 meeple on passe le tour
            if(listeJoueurs.at(tour%nbJoueurs)->getNbrMeeples() == 0){
                nextTour();
            }
            //placementMeeple();
            //nextTour();
            break;

            //Fin de la partie et comptage des scores des joueurs
        case GAME_OVER:
            //compteScore(getState());
            break;
    }
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