#include <iostream>
//#include "tuile.h"
#include "joueur.h"
#include "espace.h"




using namespace std;

int main(){
    
    
    // Test TypeMeeple OK //
    
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

    
    
    // Test Meeple + ContenanceTuile OK //
    
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
    
    
    // Test Joueur + Tuile OK //
    
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
    
    Joueur j(1,5);
    Joueur j1(2,7);
    
    j.addScore(50);
    j1.addScore(24);
    
    j.addMeeple(M1);
    j.addMeeple(M2);
    j1.addMeeple(M2);
    
    cout<<"\n-> adresse de M1 = "<< &M1 << endl;
    cout<<"-> adresse de M2 = "<< &M2 << endl;
    
    cout << j;
    cout << j1;
    
    
//    vector<void*> c0;
//    for (int i = 0; i < 9 ; i++){
//        TypesTuiles t = static_cast<TypesTuiles>(rand() % champs + 1);
//        ContenanceTuile c0[i](t,i);
//    }
//
//    Tuile T1(c0);
//    cout << T1 << endl;


    // Test Espace OK //
    
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
    cout << "adresse de la contenance 1 : " << &c1 << endl;
    cout << "adresse de la contenance 2 : " << &c3 << endl;
    cout << "adresse de la contenance 3 : " << &c2 << endl;
    cout << "adresse de la contenance 4 : " << &c5 << endl;
    cout << E;
    
    return 0;
}
