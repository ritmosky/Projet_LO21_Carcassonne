#include "controller.h"


int main(){
    Controller* c = new Controller(6);
    c->AffichageJoueurs();

    Plateau *p1 = new Plateau(0);

    vector<ContenanceTuile> c1(9);
    c1[0] = ContenanceTuile(champs,0);  c1[1] = ContenanceTuile(champs,1);  c1[2] = ContenanceTuile(champs,2);
    c1[7] = ContenanceTuile(champs,7);   c1[8] = ContenanceTuile(abbaye, 8); c1[3]= ContenanceTuile(champs,3);
    c1[6] = ContenanceTuile(champs,6);  c1[5] = ContenanceTuile(route,5);  c1[4] = ContenanceTuile(champs,4);
    Tuile t1(c1);
    t1.setX(72);
    t1.setY(72);

    vector<ContenanceTuile> c2(9);
    c2[0] = ContenanceTuile(champs,0);  c2[1] = ContenanceTuile(ville,1);  c2[2] = ContenanceTuile(champs,2);
    c2[7] = ContenanceTuile(route,7);   c2[8] = ContenanceTuile(route, 8);  c2[3] = ContenanceTuile(route,3);
    c2[6] = ContenanceTuile(champs,6);  c2[5] = ContenanceTuile(champs,5);  c2[4] = ContenanceTuile(champs,4);
    Tuile t2(c2);


    vector<ContenanceTuile> c3(9);
    c3[0] = ContenanceTuile(ville,0);  c3[1] = ContenanceTuile(champs,1);  c3[2] = ContenanceTuile(ville,2);
    c3[7] = ContenanceTuile(ville,7);  c3[8] = ContenanceTuile(ville, 8); c3[3] = ContenanceTuile(ville,3);
    c3[6] = ContenanceTuile(ville,6);  c3[5] = ContenanceTuile(champs,5);  c3[4] = ContenanceTuile(ville,4);
    Tuile t3(c3);

    //Ajout de la tuile 1 dans le plateau
    p1->ajouterTuiles(&t1);
    std::vector<Tuile*> tuiles = p1->getTuiles();
    for(Tuile* t : tuiles){
        cout << *t << endl << endl;
    }

    //Test si on peut ajouter la tuile 3
    cout << "On va essayer de placer la tuile t3" << endl;
    cout << t3 << endl;
    bool a = c->placementTuileAutorise(t3,p1);
    cout << "Placement de la tuile 3 autorise : " << a << endl  << endl;

    //Test si on peut ajouter la tuile 2
    cout << "On va essayer de placer la tuile t2" << endl;
    cout << t2 << endl;
    bool b = c->placementTuileAutorise(t2,p1);
    cout << "Placement autorise : " << b << endl<< endl ;

    //Ajouter la tuile 2
    c->placementTuile(&t2,72,71,p1);

    Tuile *t4 = t1.getVoisinHaut();
    cout << "Tuile voisine haut de t1 : " << endl << *t4 << endl << endl;

    Tuile *t5 = t2.getVoisinBas();
    cout << "Tuile voisine bas de t2 : " << endl << *t5 << endl << endl;

    //Placement meeple sur une tuile
    cout << "On va essayer de placer un meeple sur la tuile t1" << endl;
    cout << t1 << endl;
    Meeple *m = new Meeple();
    TypeMeeple tm(paysan);
    Joueur *j = new Joueur(1,6,"");
    c->placementMeeple(j,m,tm,1,72,72,p1);
    



    return 0;
}