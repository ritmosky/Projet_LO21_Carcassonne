#include <iostream>
#include <string>
#include 'controller.h'
#define NBRE_MEEPLE_MAX 7


/*
- Modification : Enlever DebutTour,Debut,FinTour,Fin , remplacé par les énum + attribut tour pour savoir le nombre de tour
- Liste de pointeur de pointeur de listeJoueurs en vecteur
*/

void setState(State state){
    this->state = state;

    Controller(int nj):nbJoueur(nj){
        setState(GAME_MENU);
        tour = 0;
    }

    //PlacementTuile
    void placementTuile(Tuile t);

    //PlacementMeeple
    void placementMeeple(Meeple m);


    //Comptage des scores
    void addScore();

    //Tour suivant
    void nextTour(){
        if(pioche.getNbTuiles() == 0){
            setState(GAME_END);
        }
        else{
            tour++;
            setState(PLACING_TILE);
            compteScore();
        }
    }

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
            plateau = new Plateau();
            pioche = new Pioche();
            setState(PLACING_TILE);
            break;

        case PLACING_TILE:
            //on place une tuile sur le plateau, avec la vue Qt du plateau
            placementTuile(pioche->getTuile());
            setState(PLACING_MEEPLE);
            break;

        case PLACING_MEEPLE:
            placementMeeple(joueur->getMeeple());
            nextRound();
            break;

            //Fin de la partie et comptage des scores des joueurs , Joueurs.getscore()
        case GAME_OVER:
            addScore();
            break;
    }
}