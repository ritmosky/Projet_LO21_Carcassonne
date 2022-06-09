
#include "pioche.h"
#include <algorithm>
#include <random>
// Pour bien parcourir le Plateau :

// Norme appliquée aux villes : Si c'est une tuile qui contient une muraille ( fin de tuile ), seul sa partie centrale est de TypesTuiles = ville, ses extrémités sont des champs. Cela permet de repérer avec plus de facilité la fin d'une ville puisque une ville qui elle peut être encore complétée aura les 3 TypesTuiles d'une même brodure de TypesTuiles = ville

// Si 2 TypeTuiles champs séparé par une ville sur une même bordure alors il s'agit du même champ
//      De même sur une diagonale interne à une tuile (càd pour structure de Ville dans un coin : TypeTuile = ville au centre d'une des bordure avec un champs dans un des deux coins ; Route en 'L' qui coupe le milieu ; et autre TypesTuiles = Champs dans le coin opposé )



ostream& operator<<(ostream& f, const Pioche& P){

    for (size_t i = 0 ; i < P.getNbTuiles(); i++){
        if (P.estVide()) {f << "Pioche vide"<< endl;}
        else {
        f << "Tuile " << i << " : " << endl<< endl;
        f << P.getTuile(i) << endl << endl;

        f << " -----------------------" << endl<< endl;
    }
    }
    return f;
}


Tuile* Pioche::piocher(int nbTour, bool riviereActive) {

    if (Pioche::estVide()) cout<<"Pioche vide";
    
    // Gestion de l'extension Rivière
    if ( nbTour< 12 && riviereActive){
        cout<<"Extension rivière :"<<endl;
        Tuile* T = new Tuile(tuiles[0]);
        cout<<T;
        auto it = tuiles.cbegin();
        tuiles.erase(it);
        return T;
        }

    else {
        cout<<"PAS Extension rivière"<<endl;

        // On mélange la pioche
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(tuiles), std::end(tuiles), rng);

    // On tire le premier élément
    Tuile* T = new Tuile(tuiles[0]);

   // On la pioche
   //Tuile* T = new Tuile(tuiles[i]);

     // On la retire de la pioche
    for (auto it = tuiles.cbegin(); it != tuiles.cend(); it++){
        if( *it == *T){
            tuiles.erase(it);
            break;
        }
    }
    return T;
   }
}








// --------------------------------------- Constructeur de la Pioche ----------------------------------------------


Pioche::Pioche(vector<int> mode) : tuiles() {

    // On va générer manuellement l'ensemble des tuiles existantes selon les extensions choisies

    // Documentation des Tuiles utilisée : http://ithaque.org/wp-content/uploads/2014/06/Carcassonne-r%C3%A8gles.pdf
    //                                     http://ludikerborg.free.fr/Jeux/carcassonne/Carcassonne.pdf



    bool aubergeActive = false;
    bool riviereActive = false;
    bool abbeActive = false;


    // Tests sur les Extensions activés par rapport à Abbé

    for (size_t i = 0 ; i < mode.size() ; i++) {
        if (mode[i] == 3) abbeActive = true;
        if (mode[i] == 4) riviereActive = true;
        if (mode[i] == 5) aubergeActive = true;

    }


    for (size_t i = 0 ; i < mode.size() ; i++) {
        

// ---------------------------------- Tuiles du mode de jeu Standard : 72 Tuiles --------------------------------------

        // -> Tuile de départ :   Route horizontale avec Ville au dessus


        if (mode[i] == 1 && not abbeActive) {


    //  x2 "Abbayes avec route" :

            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);   c[8] = ContenanceTuile(abbaye, 8); c[3]= ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);

                Tuile T(c);
                tuiles.push_back(T);
            }

    //  x4 "Abbayes sans route" :

            for (int i = 0 ; i < 4 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);   c[8] = ContenanceTuile(abbaye, 8); c[3]= ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                Tuile T(c);
                tuiles.push_back(T);
                    }


    // x1  Ville pleine :

        for (int i = 0 ; i < 1 ; i++){

            // -> On garde une boucle de 1 pour ne pas avoir de problèmes de variables globales redéfinies pour les                                 tuiles ne se trouvant qu'une seule fois

            vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
            c[7] = ContenanceTuile(ville,7);   c[8] = ContenanceTuile(ville, 8); c[3]= ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(ville,4);

            Tuile T(c);
            tuiles.push_back(T);
        }


    // x5 "Route horizontale avec Ville au dessus" :

            for (int i = 0 ; i < 5 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                Tuile T(c);
                tuiles.push_back(T);
            }


    //  x5 "Villes au dessus avec Champs en dessous" :

            for (int i = 0 ; i < 5 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                Tuile T(c);
                tuiles.push_back(T);
            }

    //  x2 "Ville en X avec bouclier"

            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                c[2].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }


    // x1 "Ville en X sans bouclier"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

   // x3 " Villes séparées par champ au milieu"
            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x2 "Ville haut et droite"

            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x3 "Ville au dessus et route en  'L' "

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x3 "Ville au dessus et route en  'L' inversé "

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }
    // x3 " Ville au dessus et route en  'T'  "

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }


    // x2 " Ville dans l'angle avec bouclier  "

            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x3 " Ville dans l'angle  sans bouclier  "

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x2 " Ville dans l'angle avec bouclier et route en 'L'"

            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x3 " Ville dans l'angle sans bouclier et route en 'L'"

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }
    // x1 " Ville pleine avec champs en dessous avec bouclier"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x3 " Ville pleine avec champs en dessous sans bouclier"

            for (int i = 0 ; i < 3 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x2 " Ville pleine avec route en dessous avec bouclier"
            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Ville pleine avec route en dessous sans bouclier"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x8 " Route droite" :

            for (int i = 0 ; i < 8 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x9 " Route en 'L' "

            for (int i = 0 ; i < 9 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x4 " Route en T "

            for (int i = 0 ; i < 4 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Croisement de Route "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }




        }




// --------------------------------- Tuiles de Auberges et Cathédrales : 18 Tuiles -----------------------------------


        if (mode[i] == 5 && not abbeActive ) {


    // x1 " Route en 'L' avec Auberge"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(auberge,2);
            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(champs,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Route droite avec Auberge "   ABBE MODIF
            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Route en 'T' avev Auberge "
            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(auberge,2);
            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }
    // x1 "Route droite avec Abbaye"
            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(abbaye, 8);c[3] = ContenanceTuile(route,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Double Route en 'L' "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(droute, 8);c[3] = ContenanceTuile(route,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

     // x1 "Ville angle avec Route"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
            c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Ville en pointe" -> doit être une fin de champ en haut
            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " 4 villes dos à dos "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

     // x1 " Villes séparées par Route les liant "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(droute, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }
    // x2 " Cathédrale"
            for (int i = 0 ; i < 2 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(cathédrale, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(ville,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Ville angle avec bouclier, Route 'L' et Auberge "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(auberge, 8);c[3] = ContenanceTuile(route,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

     // x1 " Ville haut, Route en 'L' et Auberge"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 "Ville angle avec Route et Auberge"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " 3 villes dos à dos et champs"

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Ville angle + Ville côté avec Bouclier "

            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8);c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                c[0].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }

    // x1 " Ville en X avec Route haut/bas et Bouclier"
            for (int i = 0 ; i < 1 ; i++){
                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                c[3].setBouclier();
                Tuile T(c);
                tuiles.push_back(T);
            }


        }
// --------------------------------- Tuiles de Abbé : 72 - 101 Tuiles -----------------------------------

                if (mode[i] == 3 && abbeActive) {


                    // -> Tuile de départ :   Route horizontale avec Ville au dessus



                //  x2 "Abbayes avec route" :

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(champs,7);   c[8] = ContenanceTuile(abbaye, 8); c[3]= ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);

                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                //  x4 "Abbayes sans route" :

                        for (int i = 0 ; i < 4 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(champs,7);   c[8] = ContenanceTuile(abbaye, 8); c[3]= ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                            Tuile T(c);
                            tuiles.push_back(T);
                                }


                // x1  Ville pleine :

                    for (int i = 0 ; i < 1 ; i++){

                        // -> On garde une boucle de 1 pour ne pas avoir de problèmes de variables globales redéfinies pour les                                 tuiles ne se trouvant qu'une seule fois

                        vector<ContenanceTuile> c(9);
                        c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                        c[7] = ContenanceTuile(ville,7);   c[8] = ContenanceTuile(ville, 8); c[3]= ContenanceTuile(ville,3);
                        c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(ville,4);

                        Tuile T(c);
                        tuiles.push_back(T);
                    }


                // x5 "Route horizontale avec Ville au dessus" :

                        for (int i = 0 ; i < 5 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                            Tuile T(c);
                            tuiles.push_back(T);
                        }


            //  x4 "Villes au dessus avec Champs en dessous" :

                        for (int i = 0 ; i < 4 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0); c[1] = ContenanceTuile(ville,1); c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7); c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x 1 "Ville au dessus avec Champs en dessous et Jardin"
                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(jardin,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);

                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                //  x2 "Ville en X avec bouclier"

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                            c[2].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }


                // x1 "Ville en X sans bouclier"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

               // x2 " Villes séparées par champ au milieu"

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

            // x1 " Villes séparées par champ et jardin au milieu"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(jardin, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }
                // x1 "Ville haut et droite"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x1 " Ville haut et droite avec jardin"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(jardin, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x3 "Ville au dessus et route en  'L' "

                        for (int i = 0 ; i < 3 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x3 "Ville au dessus et route en  'L' inversé "

                        for (int i = 0 ; i < 3 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }
                // x3 " Ville au dessus et route en  'T'  "

                        for (int i = 0 ; i < 3 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }


                // x1 " Ville dans l'angle avec bouclier  "

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            c[0].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }
                // x1 " Ville dans l'angle avec bouclier et jardin"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(jardin,4);
                            c[0].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x2 " Ville dans l'angle  sans bouclier  "

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x1 "Ville dans l'angle sans bouclier avec jardin"
                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8); c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(jardin,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x2 " Ville dans l'angle avec bouclier et route en 'L'"

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            c[0].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x3 " Ville dans l'angle sans bouclier et route en 'L'"

                        for (int i = 0 ; i < 3 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }
                // x1 " Ville pleine avec champs en dessous avec bouclier"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                            c[0].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x2 " Ville pleine avec champs en dessous sans bouclier"

                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(ville,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                //x2 " Ville pleine avec champs en dessous sans bouclier avec jardin"
                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(jardin,5);  c[4] = ContenanceTuile(ville,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x2 " Ville pleine avec route en dessous avec bouclier"
                        for (int i = 0 ; i < 2 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            c[0].setBouclier();
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x1 " Ville pleine avec route en dessous sans bouclier"

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                            c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x7 " Route droite" :

                        for (int i = 0 ; i < 7 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x1 " Route droite avec jardin"
                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(jardin,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x8 " Route en 'L' "

                        for (int i = 0 ; i < 8 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

            // x1 " Route en 'L' avec jardin "

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(jardin,2);
                c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(champs,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x4 " Route en T "

                        for (int i = 0 ; i < 4 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }

                // x1 " Croisement de Route "

                        for (int i = 0 ; i < 1 ; i++){
                            vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);   c[8] = ContenanceTuile(route, 8);  c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                            Tuile T(c);
                            tuiles.push_back(T);
                        }








                if (aubergeActive)

                {
                    // x1 " Route en 'L' avec Auberge"

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(auberge,2);
                    c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(champs,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Route droite avec Auberge et Jardin "
                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                c[7] = ContenanceTuile(jardin,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Route en 'T' avev Auberge "
                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(auberge,2);
                    c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }
            // x1 "Route droite avec Abbaye"
                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(abbaye, 8);c[3] = ContenanceTuile(route,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Double Route en 'L' "

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(droute, 8);c[3] = ContenanceTuile(route,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

             // x1 "Ville angle avec Route"

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                    c[7] = ContenanceTuile(champs,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Ville en pointe" -> doit être une fin de champ en haut
                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(ville,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " 4 villes dos à dos avec jardin "

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(jardin, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

             // x1 " Villes séparées par Route les liant "

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(droute, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }
            // x2 " Cathédrale"
                    for (int i = 0 ; i < 2 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(cathédrale, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(ville,6);  c[5] = ContenanceTuile(ville,5);  c[4] = ContenanceTuile(ville,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Ville angle avec bouclier, Route 'L' et Auberge "

                    for (int i = 0 ; i < 1 ; i++){
        vector<ContenanceTuile> c(9);
        c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(auberge,2);
        c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8); c[3] = ContenanceTuile(route,3);
        c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        c[0].setBouclier();
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

             // x1 " Ville haut, Route en 'L' et Auberge"

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(route,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 "Ville angle avec Route et Auberge"

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(auberge,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " 3 villes dos à dos et champs"

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Ville angle + Ville côté avec Bouclier "

                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(ville,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(champs, 8);c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                        c[0].setBouclier();
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

            // x1 " Ville en X avec Route haut/bas et Bouclier"
                    for (int i = 0 ; i < 1 ; i++){
                        vector<ContenanceTuile> c(9);
                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                    c[7] = ContenanceTuile(ville,7);  c[8] = ContenanceTuile(ville, 8); c[3] = ContenanceTuile(ville,3);
                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                        c[3].setBouclier();
                        Tuile T(c);
                        tuiles.push_back(T);
                    }

}

                    if (riviereActive)
                    {



                                // Embouchure

                                        for (int i = 0 ; i < 1 ; i++){
                                            vector<ContenanceTuile> c(9);
                                        c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                                        c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(champs,3);
                                        c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                                            Tuile T(c);
                                            tuiles.insert(tuiles.begin(), T);
                                        }


                        // x2 " Rivière droite "

                                for (int i = 0 ; i < 2 ; i++){
                                    vector<ContenanceTuile> c(9);
                                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                                    c[7] = ContenanceTuile(rivière,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
                                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x1 " Rivière centre, ville gauche"

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x1 " Rivière avec pont par dessus"

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(jardin,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x1 " Rivière avec Abbaye "

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(abbaye,1);  c[2] = ContenanceTuile(champs,2);
                                    c[7] = ContenanceTuile(rivière,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(rivière,3);
                                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x2 " Rivière en 'L' "

                                for (int i = 0 ; i < 2 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(jardin,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x1 " Rivière en 'L' avec Route en 'L"'

                                // ->    l'information de la route au centre est plus importante que la rivière, la continuité de celle-ci              est assurée par les extrémités et aucun Meeple ne peut être posé dessus

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(rivière,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }

                        // x1 " Rivière en 'L' avec Ville dans l'angle "

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }
                                // Source

                                        for (int i = 0 ; i < 1 ; i++){
                                            vector<ContenanceTuile> c(9);
                                        c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                                        c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(champs,3);
                                        c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                            Tuile T(c);
                                            tuiles.insert(tuiles.begin(), T);

                                            }

                        // x1 " Rivière entre deux Villes "

                                for (int i = 0 ; i < 1 ; i++){
                                    vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(ville,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                    Tuile T(c);
                                    tuiles.insert(tuiles.begin(), T);
                                }


                    }






                }


                // ------------------------------- Tuiles de l'extension Rivière :  12 Tuiles ----------------------------------------



                        if (mode[i] == 4 && not abbeActive) {


                            // Embouchure

                                    for (int i = 0 ; i < 1 ; i++){
                                        vector<ContenanceTuile> c(9);
                                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                                    c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(champs,3);
                                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                                        Tuile T(c);
                                        tuiles.insert(tuiles.begin(), T);
                                    }


                    // x2 " Rivière droite "

                            for (int i = 0 ; i < 2 ; i++){
                                vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(rivière,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(champs,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x1 " Rivière centre, ville gauche"

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x1 " Rivière avec pont par dessus"

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(route,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x1 " Rivière avec Abbaye "

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                                c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(abbaye,1);  c[2] = ContenanceTuile(champs,2);
                                c[7] = ContenanceTuile(rivière,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(rivière,3);
                                c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(route,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x2 " Rivière en 'L' "

                            for (int i = 0 ; i < 2 ; i++){
                                vector<ContenanceTuile> c(9);
            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
            c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x1 " Rivière en 'L' avec Route en 'L"'

                            // ->    l'information de la route au centre est plus importante que la rivière, la continuité de celle-ci              est assurée par les extrémités et aucun Meeple ne peut être posé dessus

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(route,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(route,7);c[8] = ContenanceTuile(route, 8);c[3] = ContenanceTuile(rivière,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }

                    // x1 " Rivière en 'L' avec Ville dans l'angle "

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(ville,0);  c[1] = ContenanceTuile(ville,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(rivière,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }
                            // Source

                                    for (int i = 0 ; i < 1 ; i++){
                                        vector<ContenanceTuile> c(9);
                                    c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(champs,1);  c[2] = ContenanceTuile(champs,2);
                                    c[7] = ContenanceTuile(champs,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(champs,3);
                                    c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                        Tuile T(c);
                                        tuiles.insert(tuiles.begin(), T);

                                        }

                    // x1 " Rivière entre deux Villes "

                            for (int i = 0 ; i < 1 ; i++){
                                vector<ContenanceTuile> c(9);
                            c[0] = ContenanceTuile(champs,0);  c[1] = ContenanceTuile(rivière,1);  c[2] = ContenanceTuile(champs,2);
                            c[7] = ContenanceTuile(ville,7);c[8] = ContenanceTuile(rivière, 8);c[3] = ContenanceTuile(ville,3);
                            c[6] = ContenanceTuile(champs,6);  c[5] = ContenanceTuile(rivière,5);  c[4] = ContenanceTuile(champs,4);
                                Tuile T(c);
                                tuiles.insert(tuiles.begin(), T);
                            }









                        }


    }



}
