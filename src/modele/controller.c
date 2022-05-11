#include <iostream>
#include <string>
#include 'controller.h'

void setState(State state){
    this->state = state;

    Controller(){
        setState(GAME_MENU);
        tour = 0;
    }

    //PlacementTuile
    void placementTuile(Tuile t);

    //PlacementMeeple
    void placementMeeple(Meeple m);


    switch(state){
        case GAME_MENU:
            //Initialisation du mode de jeu et des joueurs, on initialise les deux attributs mode de jeu et joueur
            std::cout << "STATE_MENU" << std::endl;
            break;
        case GAME_START:
            //initialisation le plateau,la pioche de tuile, et de lancer la partie, avec la vue Qt du plateau
            // on initialise les deux attributs plateau, pioche et on lance la partie avec setState(PLACING_TILE)
            std::cout << "STATE_GAME" << std::endl;
            break;
        case PLACING_TILE:
            //Placement de la tuile , placementTuile(Tuile t);
            std::cout << "PLACING_TILE" << std::endl;
            break;
        case PLACING_MEEPLE:
            //Placement du meeple, placementMeeple(Meeple m);
            std::cout << "PLACING_MEEPLE" << std::endl;
            break;
            //Fin de la partie et comptage des scores des joueurs , Joueurs.getscore()
        case GAME_OVER:
            std::cout << "STATE_END" << std::endl;
            break;
    }
}