
#include <iostream>
#include "espace.h"



void Espace::addContenance(const ContenanceTuile* C){
    if ( C->getType() == this->getType() )
    {
        for (int i = 0 ; i < contenus.size() ; i++ )
        {
            if (C == contenus[i]){ return; }
        }
    contenus.push_back(C);
        
    }
}
 


void Espace::addMeeple(const Meeple* M){
    meeples.push_back(M);
    nbrMeeple += 1;
}

Espace* Espace::fusionEspace(Espace* e){
    if (type == e->type)
    {
        
    nbrMeeple += e->nbrMeeple;
    nbrBouclier += e->nbrBouclier;
        
        cout<< " ------- Espace initiaux : --------- " << endl;
        for ( auto esp : contenus){cout<<*esp<<endl;}
        cout<< " ------- Espace qu'on va ajouter : --------- " << endl;
        for ( auto esp : e->contenus){cout<<*esp<<endl;}

        for ( int i = 0 ; i < e->getNbrContenanceTuile() ; i++){
            addContenance(e->getContenus(i) );
            //contenus.insert( contenus.end(), e->contenus.begin(), e->contenus.end() );
        }
        cout<< " ------- Fusion des Espaces : --------- " << endl;
        for ( auto esp : contenus){cout<<*esp<<endl;}
        
        for ( int i = 0 ; i < e->getNbrMeeple() ; i++){
            addMeeple(e->getMeeples(i));
            //contenus.insert( contenus.end(), e->contenus.begin(), e->contenus.end() );
        }
    meeples.insert( meeples.end(), e->meeples.begin(), e->meeples.end() );
    
    }
    return this;
}






ostream& operator<<(ostream& f, const Espace& E){

    f << "--------------------------------------------------------\n";

    f << "\n Espace de type : " << TypesTuiles_str[E.getType()];
    f << "\n Nombre de boucliers : " << E.getNbrBouclier();

    if (E.isFree()){
        f << "\n\n Disponibilité : libre";
    }

    else{
        f << "\n\n Disponibilité : occupé";
    }

    f << "\n Nombre de meeples placés dessus : " << E.getNbrMeeple();
    for(int i =0; i< E.getMeeples().size(); i++){
        cout << "\n\t - adresse du meeple " << i+1 << " : " << E.getMeeples()[i];
    }

    f << "\n\n Nombre de ContenanceTuile : " << E.getNbrContenanceTuile();
    for(int i =0; i< E.getContenus().size(); i++){
        cout << "\n\t - adresse du contenu " << i+1 << " : " << E.getContenus()[i];
    }

    f << "\n\n --------------------------------------------------------\n\n";

    return f;
}
