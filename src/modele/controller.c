#include <iostream>
#include <string>
#include ".vscode"
#include "tuiles.h"
#include "pioche.h"
#include "plateau.h"
#define NBRE_MEEPLE_MAX 7


//Il faut rajouter les fonctions getVoisin_haut(), getVoisin_bas(), getVoisin_gauche(), getVoisin_droite() dans Tuile
// Rajouter getTuileAleatoire() et getNbTuiles() dans Pioche pour récuperer la tuile aléatoirement choisie et le nombre de tuiles restant dans la pioche
// Rajouter getTuiles() permettant de récupérer la liste des tuiles présentes sur le plateau
// Ajouter une méthode addscore() et getNbMeeple dans joueur


    Controller(int nj):nbJoueur(nj){
        setState(GAME_MENU);
        tour = 0;
    }

    bool placementTuileAutorise(Tuile* newTuile){
        //Parcourir toutes les tuiles du plateau
        for(Tuile *tuile : plateau->getTuiles()){
            //Voisin du haut
            if(tuile->getVoisin_haut() != NULL){
                //On considère les 4 rotations de la tuile
                for(int rotation=0;rotation<4; rotation++){
                    //On regarde si la tuile est compatible
                    if(estCompatible(newTuile, tuile->getVoisin_haut()),tuile){
                        //On peut la placer
                        return true;
                    }
                    newtuile->rotation();
                }
            }

            //Voisin du bas
            if(tuile->getVoisin_bas() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisin_bas()),tuile){
                        return true;
                    }
                    newtuile->rotation();
                }
            }

            //Voisin de gauche
            if(tuile->getVoisin_gauche() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisin_gauche()),tuile){
                        return true;
                    }
                    newtuile->rotation();
                }
            }

            //Voisin de droite
            if(tuile->getVoisin_droite() != NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getVoisin_droite()),tuile){
                        return true;
                    }
                    newtuile->rotation();
                }
            }
        }

    return false;
    }


    bool estCompatible(Tuile* newTuile, Tuile* voisin,Tuile* tuile){
        //Voisin du haut
        if(tuile->getVoisin_haut()!=null){
            if(newTuile->getContenuTuile(1)!=voisin->getContenuTuile(5)){
                return false;
            }
        }

        //Voisin du bas
        if(tuile->getVoisin_bas()!=null){
            if(newTuile->getContenuTuile(5)!=voisin->getContenuTuile(1)){
                return false;
            }
        }

        //Voisin de gauche
        if(tuile->getVoisin_gauche()!=null){
            if(newTuile->getContenuTuile(7)!=voisin->getContenuTuile(3)){
                return false;
            }
        }

        //Voisin de droite
        if(tuile->getVoisin_droite()!=null){
            if(newTuile->getContenuTuile(3)!=voisin->getContenuTuile(7)){
                return false;
            }
        }
        return true;

    }

    //PlacementMeeple
    bool placementMeepleAutorise(Meeple m){
        

    }


    //Comptage des scores
    void compteScore(State state){
		if (state == State.GAME_OVER){
           compteScore("Champs", state);
        }
		compteScore("Ville", state);
		compteScore("Routes", state); // à implémenter une méthode compte score pour les routes et villes
		compteScoreAbbaye(state);
	}

    

    //Tour suivant
    void nextTour(){
        if(pioche.getNbTuiles() == 0){
            setState(GAME_END);
        }
        else{
            compteScore(getState());
            tour++;
            setState(PLACING_tuile);
        }
    }

//ok
void setState(State state){
    
    this->state = state;

    switch(state){
        case GAME_MENU:
            //Initialisation du mode de jeu et des joueurs, on initialise les deux attributs mode de jeu et joueur
            modeJeu = new ModeJeu[5];
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
            placementTuile(pioche->getTuileAleatoire());
            setState(PLACING_MEEPLE);
            break;

        case PLACING_MEEPLE:
            //Si le joueur actuelle a 0 meeple on passe le tour
            if(listeJoueur.at(tour%nbJoueurs)->getNbMeeple() == 0){
                nextTour();
            }

            placementMeeple(joueur->getMeeple());
            nextRound();
            break;

            //Fin de la partie et comptage des scores des joueurs , Joueurs.getscore()
        case GAME_OVER:
            compteScore(getState());
            break;
    }
}


//ok
void compteScoreAbbaye(State s) {
		int score = 1;
		for (Tuile* tuile : plateau->getTuiles()) {
			TypesTuiles& typetuile = tuile->getContenuTuile(8);
            ContenanceTuile contenance = tuile->getContance(8);
			if (typetuile == "Abbaye" && contenance.hasMeeple()) {
				// HAUT GAUCHE
				if (tuile->getVoisin_Haut()->getVoisin_Gauche()!= null) {
					score++;
				}

				// HAUT
				if (tuile->getVoisin_Haut() != null) {
					score++;
				}

				// HAUT DROITE
				if (tuile->getVoisin_Haut()->getVoisin_Droite() != null) {
					score++;
				}

				// GAUCHE
				if (tuile->getVoisin_Gauche() != null) {
					score++;
				}

				// DROITE
				if (tuile->getVoisin_Droite() != null) {
					score++;
				}

				// BAS GAUCHE
				if (tuile->getVoisin_Bas()->getVoisin_Gauche()!= null) {
					score++;
				}

				// BAS DROITE
				if (tuile->getVoisin_Bas()->getVoisin_Droite() != null) {
					score++;
				}

				// BAS
				if (tuile->getVoisin_Bas() != null) {
					score++;
				}

				if (score == 9 || s == State.GAME_OVER) {
					contenance.getJoueur().addScore(score); 
				}
			}
			score = 1;
		}
	}

