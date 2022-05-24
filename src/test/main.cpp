
#include <iostream>
#include "pioche.h"
#include "joueur.h"
#include "espace.h"



using namespace std;



int main(){
    
    
    
    // Test TYPEMEEPLE OK //
    
    cout << endl << "\n---------- Pour TypeMeeple ---------- \n\n";
    
    TypeMeeple tm(paysan);  // une façon de construire, directement avec le nom du meeple
    NomMeeple m2(voleur);
    TypeMeeple tm2(m2);     // une autre façon de construire, avec un objet NomMeeple
    cout << tm2;
    cout << tm;
    
    cout << endl << "------------------------------------- \n\n";
    
    // attention /!\ les deuxièmes paramètres ne suivent pas ici la logique de notre architecture
    ContenanceTuile c1(ville, 9);
    ContenanceTuile c2(champs, 58);
    ContenanceTuile c3(jardin, 43);
    ContenanceTuile c4(route, 26);

    
    
    // Test MEEPLE + CONTENANCETUILE OK //
    
    Meeple M1;
    M1.setType(tm2);
    M1.setIdJoueur(3);
    M1.setContenance(c1);
    cout << M1;
    
    Meeple M2;
    M2.setType(paysan);
    M2.setIdJoueur(4);
    M2.setContenance(c3);
    cout << M2;
    
    
    
    // Test JOUEUR + TUILE OK //
    
    vector<ContenanceTuile> c;
    c.push_back(c1);       // ville
    c.push_back(c2);        // champs
    c.push_back(c3);        // jardin
    c.push_back(c4);        // route
    c.push_back(c1);
    c.push_back(c2);
    c.push_back(c3);
    c.push_back(c4);
    c.push_back(c3);
    
    Tuile T(c);
    cout << T << endl;
    
    Joueur j(1,5,"Taoufiq");
    Joueur j1(2);
    
    j.addScore(50);
    j1.addScore(24);
    
    j.addMeeple(M1);
    j.addMeeple(M2);
    j1.addMeeple(M2);
    
    cout<<"\n-> adresse de M1 = "<< &M1 << endl;
    cout<<"-> adresse de M2 = "<< &M2 << endl;
    
    cout << j;
    cout << j1;
    
    cout << j;
    j1.addName("Amenadiel");
    cout << j1;


    // Test ESPACE OK //
    
    Espace E(ville);
    
    E.addMeeple(M1);
    E.addMeeple(M2);
    
    cout << "adresse du meeple 1 : " << &M1 << endl;
    cout << "adresse du meeple 2 : " << &M2 << endl;
    
    cout << E;
    
    E.addContenance(c1);
    E.addContenance(c3);
    E.addContenance(c2);
    ContenanceTuile c5(ville, 4);
    E.addContenance(c5);
    
    cout << E;
    
    
    // Test PIOCHE OK //
    cout << endl << "\n---------- Pour Pioche ---------- \n\n";
    
    vector<int> mode;
    cout << mode;

    mode.push_back(1);
    cout << mode;


    Pioche pioche(mode);
    cout << pioche << endl;
    
    Tuile T1(pioche.piocher());
    cout<< T1 << endl;
    
    Tuile T2 = pioche.piocher();
    cout << T2 << endl;

    Tuile T3 = pioche.piocher();
    cout << T3 << endl;
    
    
    cout << pioche << endl;

    
    
    // Test de CHANGERORIENTATION :
    cout << endl << "\n---------- Pour changerOrientation ---------- \n\n";

    cout << endl << "---------- avant changerOrientation ---------- \n\n";
    cout << T << endl;
    cout << endl << "---------- après changerOrientation ---------- \n\n";
    T.changerOrientation();
    cout << T << endl;
    
    cout << endl << "---------- avant changerOrientation ---------- \n\n";
    cout << T << endl << endl;
    cout << endl << "---------- après changerOrientation ---------- \n\n";
    T.changerOrientation();
    cout << T << endl << endl;
    
    
    
    // Test AFFECTATION
    cout << endl << "\n---------- Affectation de tuile ---------- \n\n";
    
    Tuile T11(c);
    cout << T11 << endl << endl;
    
    
    const Tuile T22 = T11;
    cout << "\n- avec affectaion : \n\n" << T22 << endl << endl;
    
    
    vector<ContenanceTuile> cc(9);
    for (int i = 0; i < 9 ; i++){
        TypesTuiles t = static_cast<TypesTuiles>(rand() % champs + 1);
        cc[i] = ContenanceTuile(t,i);
    }

    Tuile t(cc);
    cout << endl << endl << t << endl;

    return 0;
}
