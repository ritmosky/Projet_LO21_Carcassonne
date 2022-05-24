
#include "meeple.h"
#include <iostream>




ostream& operator<<(std::ostream& f, const TypeMeeple& Tm){

    f << " Meeple de type : " << NomMeeple_str[Tm.getNom()] << endl;

    return f;
}



ostream& operator<<(std::ostream& f, const Meeple& M){

    f << "--------------------------------------------------------\n\n";

    // Meeple posé?
    if (M.isUsed() == 0){
        f << " Meeple posé sur aucun contenu de tuile \n";
    }

    else{
        f << " Meeple posé sur le contenu tuile d\'adresse : " << M.getContenanceTuile() << endl;

        // Id du joueur et type du meeple, si le meeple a été posé
        f << M.getType();

        if (M.getIdJoueur() == 0){
            f << " Meeple attribué à aucun joueur \n\n";
        }

        else{
            f << " Meeple attribué au joueur : " << M.getIdJoueur() << endl << endl;
        }

        f << *M.getContenanceTuile(); // on affiche l'objet ContenanceTuile()
    }

    f << "\n--------------------------------------------------------\n";

    return f;
}




