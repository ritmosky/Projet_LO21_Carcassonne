#include "modeJeu.h"
#include "controller.h"
#define NBRE_MEEPLE_MAX 7


//Il faut rajouter les fonctions getVoisinHaut(), getVoisinBas(), getVoisinGauche(), getVoisinDroite() dans Tuile
// Rajouter getTuiles() permettant de récupérer la liste des tuiles présentes sur le plateau
// Contenance hasMeeple(), Contenance getJoueur() pour le score
//Mettre la méthode const changer orientation() dans Tuile



    Controller::Controller(int nj):nbJoueurs(nj){
        setState(GAME_MENU);
        tour = 0;
    }

    bool Controller::placementTuileAutorise(const Tuile newTuile){
        //Parcourir toutes les tuiles du plateau
        for(Tuile *tuile : plateau->getTuiles()){
            //Voisin du haut
            if(tuile->getVoisinHaut() != NULL){
                //On considère les 4 rotations de la tuile
                for(int rotation=0;rotation<4; rotation++){
                    //On regarde si la tuile est compatible
                    if(estCompatible(newTuile, tuile->getVoisinHaut(),tuile)){
                        //On peut la placer
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin du bas
            if(tuile->getVoisinBas() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisinBas(),tuile)){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de gauche)
            if(tuile->getVoisinGauche() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisinGauche(),tuile)){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de droite
            if(tuile->getVoisinDroite() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisinDroite(),tuile)){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
        }

    return false;
    }


    bool Controller::estCompatible(const Tuile newTuile,const Tuile* voisin,Tuile* tuile){
        //Voisin du haut
        if(tuile->getVoisinHaut()!=NULL){
            if(newTuile.getContenu(1)!=voisin->getContenu(5)){
                return false;
            }
        }

        //Voisin du bas
        if(tuile->getVoisinBas()!=NULL){
            if(newTuile.getContenu(5)!=voisin->getContenu(1)){
                return false;
            }
        }

        //Voisin de gauche
        if(tuile->getVoisinGauche()!=NULL){
            if(newTuile.getContenu(7)!=voisin->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(tuile->getVoisinDroite()!=NULL){
            if(newTuile.getContenu(3)!=voisin->getContenu(7)){
                return false;
            }
        }
        return true;

    }

    //PlacementMeeple
    //bool Controller::placementMeepleAutorise(Meeple m){}


    //Comptage des scores
    void Controller::compteScore(State state){
		if (state == GAME_OVER){
           compteScore(TypesTuiles::champs, state);
        }
		compteScore(TypesTuiles::ville, state);
		compteScore(TypesTuiles::route, state); // à implémenter une méthode compte score pour les routes et villes
		compteScoreAbbaye(state);
	}

    

    //Tour suivant
    void Controller::nextTour(){
        if(pioche->getNbTuiles() == 0){
            setState(GAME_OVER);
        }
        else{
            compteScore(getState());
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
            modeJeu = new ModeJeu[5];
            modeJeu[0] = new Standard();
            modeJeu[1] = new Riviere();
            modeJeu[2] = new AubergesEtCathedrales();
            modeJeu[3] = new Paysan();
            
            for(int i=0;i<nbJoueurs;i++){
                listeJoueurs.push_back(new Joueur(i,NBRE_MEEPLE_MAX));
            }
            break;

        case GAME_START:
            //initialisation le plateau,la pioche de tuile, et de lancer la partie, avec la vue Qt du plateau
            plateau = new Plateau(0,0);
            //La pioche doit être initialisée avec le mode de jeu et avec un booléen abbé
            pioche = new Pioche();
            setState(PLACING_TILE);
            break;

        case PLACING_TILE:
            //on place une tuile sur le plateau, avec la vue Qt du plateau
            placementTuileAutorise(pioche->Piocher());
            setState(PLACING_MEEPLE);
            break;

        case PLACING_MEEPLE:
            //Si le joueur actuelle a 0 meeple on passe le tour
            if(listeJoueurs.at(tour%nbJoueurs)->getNbrMeeples() == 0){
                nextTour();
            }

            //placementMeeple();
            nextTour();
            break;

            //Fin de la partie et comptage des scores des joueurs , Joueurs.getscore()
        case GAME_OVER:
            compteScore(getState());
            break;
    }
}


/*
void Controller::compteScoreAbbaye(State s) {
		int score = 1;
		for (Tuile* tuile : plateau->getTuiles()) {
			TypesTuiles const typetuile = tuile->getContenu(8);
            ContenanceTuile contenance = tuile->getContenance(8);
			if (typetuile == TypesTuiles::abbaye && contenance.hasMeeple()) {
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

