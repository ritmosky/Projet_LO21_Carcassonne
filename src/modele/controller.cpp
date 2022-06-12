#include "modeJeu.h"
#include "controller.h"
#define NBRE_MEEPLE_MAX 7




    Controller::Controller(int nj):nbJoueurs(nj){
        tour = 0;
        plateau = new Plateau(0);
        pioche = new Pioche(extensions);
    }


    Controller::Controller(int nj,vector<string> listeNomJoueur,vector<int> listeNumExtensions):nbJoueurs(nj),extensions(listeNumExtensions){
        tour = 0;
        for(int i=0;i<nbJoueurs;i++){
            listeJoueurs.push_back(new Joueur(i,NBRE_MEEPLE_MAX,""));
            listeJoueurs[i]->addName(listeNomJoueur[i]);
            }
        for (size_t i = 0 ; i < listeNumExtensions.size() ; i++) {
            if (listeNumExtensions[i] == 2) paysansActive = true;
            if (listeNumExtensions[i] == 3){
                abbeActive = true;
                for(int i=0;i<nbJoueurs;i++){
                    Meeple* meepleabbe = new Meeple();
                    meepleabbe->setType(NomMeeple::abbe);
                    listeJoueurs[i]->setNbMeeple(listeJoueurs[i]->getNbrMeeples()+1);
                    listeJoueurs[i]->addMeeple(*meepleabbe);
                    }
            }
            if (listeNumExtensions[i] == 4) riviereActive = true;
            if (listeNumExtensions[i] == 5) aubergeActive = true;

        }
        plateau = new Plateau(0);
        pioche = new Pioche(extensions);
        modeJeu[0] = new Standard();
        modeJeu[1] = new Paysan();
        modeJeu[2] = new Abbe();
        modeJeu[3] = new Riviere();
        modeJeu[4] = new AubergesEtCathedrales();
    }

    void Controller::placementMeeple(Joueur* j,Meeple* m,TypesTuiles tm,int i,int x,int y){
       Tuile *t = plateau->existeTuile(x,y);
       ContenanceTuile *contenance = t->getContenancePointeur(i);

       this->getEspace(t->getContenancePointeur(i))->addMeeple(m);
       m->setContenance(*contenance);
       m->setIdJoueur(j->getId());
       if(tm==TypesTuiles::champs){
           m->setType(NomMeeple::paysan);
       }
       else if(tm==TypesTuiles::abbaye || tm==TypesTuiles::jardin){
           m->setType(NomMeeple::abbe);
       }
       else if(tm==TypesTuiles::ville){
           m->setType(NomMeeple::chevalier);
       }
       else if(tm==TypesTuiles::route){
           m->setType(NomMeeple::voleur);
       }
       else if(tm==TypesTuiles::champs){
           m->setType(NomMeeple::paysan);
       }
       else{
           m->setType(NomMeeple::rien);
       }
       j->removeMeeple();
   }

    void Controller::placementTuile(Tuile *newTuile,int x,int y){
        newTuile->setPosX(x);
        newTuile->setPosY(y);
        plateau->ajouterTuiles(newTuile);
        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            newTuile->setVoisinHaut(plateau->existeTuile(x,y-1));
            plateau->existeTuile(x,y-1)->setVoisinBas(newTuile);
        }
        //Voisin du bas
        if(plateau->existeTuile(x,y+1)){
            newTuile->setVoisinBas(plateau->existeTuile(x,y+1));
            plateau->existeTuile(x,y+1)->setVoisinHaut(newTuile);
        }
        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            newTuile->setVoisinGauche(plateau->existeTuile(x-1,y));
            plateau->existeTuile(x-1,y)->setVoisinDroite(newTuile);
        }
        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            newTuile->setVoisinDroite(plateau->existeTuile(x+1,y));
            plateau->existeTuile(x+1,y)->setVoisinGauche(newTuile);
        }
    }

    bool Controller::placementTuileAutorise(Tuile newTuile){
        //Parcourir toutes les tuiles du plateau présent dans un vecteur de tuiles
        for(Tuile *tuile : plateau->getTuiles()){
            //Voisin du haut
            if(tuile->getVoisinHaut() == NULL){
                //On considère les 4 rotations de la tuile
                for(int rotation=0;rotation<4; rotation++){
                    //On regarde si la tuile est compatible
                    if(estCompatible(newTuile,tuile->getX(),tuile->getY()-1)){
                        //On peut la placer
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin du bas
            if(tuile->getVoisinBas() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile,tuile->getX(),tuile->getY()+1)){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de gauche)
            if(tuile->getVoisinGauche() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile,tuile->getX()-1,tuile->getY())){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }

            //Voisin de droite
            if(tuile->getVoisinDroite() == NULL){
                for(int rotation=0;rotation<4; rotation++){
                    if(estCompatible(newTuile, tuile->getX()+1,tuile->getY())){
                        return true;
                    }
                    newTuile.changerOrientation();
                }
            }
        }

    return false;
    }

     bool Controller::estCompatible(Tuile newTuile,int x,int y){

         //s'il aucun voisin

         if(!plateau->existeTuile(x,y-1) && !plateau->existeTuile(x,y+1) && !plateau->existeTuile(x-1,y) && !plateau->existeTuile(x+1,y)){
             return false;
         }
         
          //Si on clique sur la meme tuile
         std::vector<Tuile*> tuiles = plateau->getTuiles();
         for(Tuile* t : tuiles){
            if(t->getX()==x && t->getY()==y){
                return false;
            }
         }

        //Voisin du haut
        if(plateau->existeTuile(x,y-1)){
            if(newTuile.getContenu(1)!=plateau->existeTuile(x,y-1)->getContenu(5)){
                return false;
            }
        }


        //Voisin du bas
        if(plateau->existeTuile(x,y+1)){
            if(newTuile.getContenu(5)!=plateau->existeTuile(x,y+1)->getContenu(1)){
                return false;
            }
        }

        //Voisin de gauche
        if(plateau->existeTuile(x-1,y)){
            if(newTuile.getContenu(7)!=plateau->existeTuile(x-1,y)->getContenu(3)){
                return false;
            }
        }

        //Voisin de droite
        if(plateau->existeTuile(x+1,y)){
            if(newTuile.getContenu(3)!=plateau->existeTuile(x+1,y)->getContenu(7)){
                return false;
            }
        }

        return true;

    }

     //Tour suivant
    void Controller::nextTour(){
        if(pioche->estVide()==true){
            cout << " FINISHED ";
           return ;
        }
        else{
            this->getJoueurs().at(getTour()%(getJoueurs().size()));
            tour++;
        }
    }



Espace* Controller::getEspace(const ContenanceTuile* c) {
    for (Espace* esp : plateau->getEspaces() ){
        for (int i = 0; i < esp->getNbrContenanceTuile() ; i++){
            if (c == (esp->getContenus(i)) )
                { return esp; }
        }
    }
    return nullptr;
}

Espace* Controller::getEspaceTuile(const ContenanceTuile& c,const vector<Espace*> e) {
    for (Espace* esp : e ){
        for (int i = 0; i < esp->getContenus().size() ; i++){
            if ( &c == esp->contenus[i] )
                { return esp; }
        }
    }
    return nullptr;
}



void Controller::creerEspace(const Tuile* T){

    vector<Espace*> Espaces_créées;
    
// Création de l'espace avec le centre
    
    // Gestion double route Auberge Cathédrales
    
    if (T->getContenu(8) == droute){
        Espace* e = new Espace(T->getContenu(8));
        //cout << "On crée un espace à " << T->getContenance(8) << endl;
        // Ajout du centre à l'espace
        e->addContenance(&(T->getContenance(8)));
        // Ajout au vecteur
        Espaces_créées.push_back(e);
    }

    else {
    Espace* e = new Espace(T->getContenu(8));
    //cout << "On crée un espace à " << T->getContenance(8) << endl;
    // Ajout du centre à l'espace
    e->addContenance(&(T->getContenance(8)));
    // Ajout au vecteur
    Espaces_créées.push_back(e);
    }


    // Parcours en croix
    for (int i = 1 ; i < 8 ; i = i + 2){
        // Si sont de même type on l'ajoute
        if ( T->getContenu(i) == T->getContenu(8)) {
            
           getEspaceTuile(T->getContenance(8), Espaces_créées)->addContenance(&(T->getContenance(i)));
            //cout << "On ajoute " << T->getContenance(i) << " à " << T->getContenance(8) <<endl ;

        }
 
    }

    for (int i = 0 ; i < 7 ; i++ ){
        
        
        if ( i == 0) {
            
// Cas de ville/champ plein(e) pour ne pas séparer c0 des autres
    if ( T->getContenu(0) == T->getContenu(1) && getEspaceTuile(T->getContenance(1), Espaces_créées) != nullptr)
            {
                getEspaceTuile(T->getContenance(1), Espaces_créées)->addContenance(&(T->getContenance(0)));
            }
    else if ( T->getContenu(0) == T->getContenu(7) && getEspaceTuile(T->getContenance(7), Espaces_créées) != nullptr)
                    {
                        getEspaceTuile(T->getContenance(7), Espaces_créées)->addContenance(&(T->getContenance(0)));
                    }
    // Cas champs coins opposés
    else if (T->getContenu(0) == champs && T->getContenu(4) == champs &&
 (
            ( // Passage ouvert par en haut
 (T->getContenu(1) != rivière && T->getContenu(1) != route) && (T->getContenu(3) != rivière && T->getContenu(3) != route) )
    ||
            ( // Passage ouvert par en bas
(T->getContenu(7) != rivière && T->getContenu(7) != route) && (T->getContenu(5) != rivière && T->getContenu(5) != route) )
  ))
            {
                Espace* e = new Espace(T->getContenu(0));
                e->addContenance(&(T->getContenance(0)));
                Espaces_créées.push_back(e);
                getEspaceTuile(T->getContenance(0), Espaces_créées)->addContenance(&(T->getContenance(4)));

            }
            
    // Cas champ séparé par ville
    else if (T->getContenu(0) == champs && T->getContenu(1) == ville && T->getContenu(2) == champs )
    {
        Espace* e = new Espace(T->getContenu(0));
        e->addContenance(&(T->getContenance(0)));
        Espaces_créées.push_back(e);
        getEspaceTuile(T->getContenance(0), Espaces_créées)->addContenance(&(T->getContenance(2)));

    }
    else if (T->getContenu(0) == champs && T->getContenu(7) == ville && T->getContenu(6) == champs )
    {
        Espace* e = new Espace(T->getContenu(0));
        e->addContenance(&(T->getContenance(0)));
        Espaces_créées.push_back(e);
        getEspaceTuile(T->getContenance(0), Espaces_créées)->addContenance(&(T->getContenance(6)));

    }
        // Voisin arrière
        
    else {
        //cout << "On n'a pas encore d'espace pour " << T->getContenance(i) << endl ;
        Espace* e = new Espace(T->getContenu(i));
        e->addContenance(&(T->getContenance(i)));
        Espaces_créées.push_back(e);
    }
            
    if ( T->getContenu(0) == T->getContenu(7) && getEspaceTuile(T->getContenance(7), Espaces_créées) == nullptr ) {
                //cout << "On ajoute " << T->getContenance(7) << " à " << T->getContenance(0) <<endl ;

            getEspaceTuile(T->getContenance(0), Espaces_créées)->addContenance(&(T->getContenance(7)));}
            
        // Voisin devant

    if ( T->getContenu(0) == T->getContenu(1) && getEspaceTuile(T->getContenance(1), Espaces_créées) == nullptr){
                
        //cout << "On ajoute " << T->getContenance(1) << " à " << T->getContenance(0)<<endl;
        getEspaceTuile(T->getContenance(0), Espaces_créées)->addContenance(&(T->getContenance(1)));
        
        }
    }
     
// Cas ville en X
        
        else if (i % 2 == 0 && getEspaceTuile(T->getContenance(i), Espaces_créées) == nullptr && T->getContenu(i) == ville && T->getContenu(i-2) == ville  )
          {
              getEspaceTuile(T->getContenance(i-2), Espaces_créées)->addContenance(&(T->getContenance(i)));

          }
        else if (i % 2 == 1 && getEspaceTuile(T->getContenance(i+1), Espaces_créées) == nullptr && T->getContenu(i-1) == ville && T->getContenu(i+1) == ville  )
          {
              getEspaceTuile(T->getContenance(i-1), Espaces_créées)->addContenance(&(T->getContenance(i+1)));

          }
        else if (getEspaceTuile(T->getContenance(i+2), Espaces_créées) != nullptr && (T->getContenu(i+1) == jardin || T->getContenu(i+1) == abbaye || T->getContenu(i+1) == auberge)&& T->getContenu(i) == champs && T->getContenu(i+2) == champs  )
          {
              getEspaceTuile(T->getContenance(i+2), Espaces_créées)->addContenance(&(T->getContenance(i)));

          }
        else if (getEspaceTuile(T->getContenance(i+1), Espaces_créées) == nullptr && (T->getContenu(i) == jardin || T->getContenu(i) == abbaye || T->getContenu(i) == auberge)&& T->getContenu(i-1) == champs && T->getContenu(i+1) == champs  )
          {
              getEspaceTuile(T->getContenance(i-1), Espaces_créées)->addContenance(&(T->getContenance(i+1)));

          }
          
   
      else if (getEspaceTuile(T->getContenance(i), Espaces_créées) == nullptr )
        {
            //cout << "On n'a pas encore d'espace pour " << T->getContenance(i) << endl ;
            Espace* e = new Espace(T->getContenu(i));
            e->addContenance(&(T->getContenance(i)));
            Espaces_créées.push_back(e);
        }
        
        
        // Cas champ séparé par ville
                  else  if (i % 2 == 0 && T->getContenu(i) == champs && T->getContenu(i+1) == ville && T->getContenu(i+2) == champs )
                    {
                        getEspaceTuile(T->getContenance(i), Espaces_créées)->addContenance(&(T->getContenance(i+2)));

                    }
                    
            
            else {
// Cas champs coins opposés
                if (i == 2 && T->getContenu(2) == champs && T->getContenu(6) == champs &&
             (
                        ( // Passage ouvert par en haut
             (T->getContenu(3) != rivière && T->getContenu(3) != route) && (T->getContenu(5) != rivière && T->getContenu(5) != route) )
                ||
                        ( // Passage ouvert par en bas
            (T->getContenu(1) != rivière && T->getContenu(1) != route) && (T->getContenu(7) != rivière && T->getContenu(7) != route) )
              ))
                        {
                            getEspaceTuile(T->getContenance(2), Espaces_créées)->addContenance(&(T->getContenance(6)));

                        }
    
            
// Voisin arrière

            if ( T->getContenu(i) == T->getContenu(i-1) && getEspaceTuile(T->getContenance(i-1), Espaces_créées) != nullptr) {
                //cout << "On ajoute " << T->getContenance(i-1) << " à " << T->getContenance(i)<<endl;
                getEspaceTuile(T->getContenance(i), Espaces_créées)->addContenance(&(T->getContenance(i-1)));
            }
            else if (getEspaceTuile(T->getContenance(i), Espaces_créées) == nullptr && T->getContenu(i) == T->getContenu(i+1) && getEspaceTuile(T->getContenance(i+1), Espaces_créées) != nullptr) {
                getEspaceTuile(T->getContenance(i+1), Espaces_créées)->addContenance(&(T->getContenance(i)));

            }
                
            else if (getEspaceTuile(T->getContenance(i-1), Espaces_créées) == nullptr ) {
                //cout << "On crée un espace à " << T->getContenance(i-1) << endl;
                Espace* e = new Espace(T->getContenu(i-1));
                e->addContenance(&(T->getContenance(i-1)));
                Espaces_créées.push_back(e);
                
            }
            
// Voisin devant

            if ( T->getContenu(i) == T->getContenu(i+1) && getEspaceTuile(T->getContenance(i+1), Espaces_créées) == nullptr) {
                //cout << "On ajoute " << T->getContenance(i+1) << " à " << T->getContenance(i)<<endl;
                getEspaceTuile(T->getContenance(i), Espaces_créées)->addContenance(&(T->getContenance(i+1)));
            }
            else if (getEspaceTuile(T->getContenance(i+1), Espaces_créées) == nullptr && T->getContenu(i+1) == T->getContenu(i+2) && getEspaceTuile(T->getContenance(i+2), Espaces_créées) != nullptr) {
                getEspaceTuile(T->getContenance(i+2), Espaces_créées)->addContenance(&(T->getContenance(i+1)));

            }
            else if (getEspaceTuile(T->getContenance(i+1), Espaces_créées) == nullptr  ) {
                //cout << "On crée un espace à " << T->getContenance(i+1) << endl;
                Espace* e = new Espace(T->getContenu(i+1));
                e->addContenance(&(T->getContenance(i+1)));
                Espaces_créées.push_back(e);
            }
                
        }
       
            
    
    
}
    
    // On ajoute les espaces créés au plateau

    for (auto esp : Espaces_créées)
        {
            this->getPlateau()->ajouterEspace(esp);
        }
}
    


void Controller::fusionVoisin(const Tuile* tuile)
{
    

// Voisin Haut
    
    
    if ( tuile->getVoisinHaut() != nullptr )
        
    {
    // Premier Contenu
         if(getEspace(tuile->getVoisinHaut()->getContenancePointeur(6)) != getEspace(tuile->getContenancePointeur(0))){
        if ( tuile->getContenu(0) == tuile->getVoisinHaut()->getContenu(6))
        {
            Espace* toDelete = getEspace(tuile->getVoisinHaut()->getContenancePointeur(6));
    getEspace(tuile->getContenancePointeur(0))->Espace::fusionEspace(getEspace(tuile->getVoisinHaut()->getContenancePointeur(6)));
            // Si la fusion a lieu on supprime l'espace du voisin du haut
            this->getPlateau()->supprimerEspace(toDelete);
        }
         }
    // Deuxième Contenu

    if ( tuile->getContenu(1) == tuile->getVoisinHaut()->getContenu(5)
            && getEspace(tuile->getVoisinHaut()->getContenancePointeur(5)) != getEspace(tuile->getContenancePointeur(1)) )
        {
            Espace* toDelete = getEspace(tuile->getVoisinHaut()->getContenancePointeur(5));

    getEspace(tuile->getContenancePointeur(1))->Espace::fusionEspace(getEspace(tuile->getVoisinHaut()->getContenancePointeur(5)));
            // Si la fusion a lieu on supprime l'espace du voisin du haut
            this->getPlateau()->supprimerEspace(toDelete);
        }
  // Troisième Contenu
        if ( tuile->getContenu(2) == tuile->getVoisinHaut()->getContenu(4)
                && getEspace(tuile->getVoisinHaut()->getContenancePointeur(4)) != getEspace(tuile->getContenancePointeur(2)) )
            {
                Espace* toDelete = getEspace(tuile->getVoisinHaut()->getContenancePointeur(4));

        getEspace(tuile->getContenancePointeur(2))->Espace::fusionEspace(getEspace(tuile->getVoisinHaut()->getContenancePointeur(4)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
        
    }
    
    
    cout<<endl<<endl;

    if ( tuile->getVoisinDroite() != nullptr )
    {
        // Premier Contenu
             if(getEspace(tuile->getVoisinDroite()->getContenancePointeur(0)) != getEspace(tuile->getContenancePointeur(2))){
            if ( tuile->getContenu(2) == tuile->getVoisinDroite()->getContenu(0))
            {
                Espace* toDelete = getEspace(tuile->getVoisinDroite()->getContenancePointeur(0));
        getEspace(tuile->getContenancePointeur(2))->Espace::fusionEspace(getEspace(tuile->getVoisinDroite()->getContenancePointeur(0)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
             }
            
        // Deuxième Contenu

        if ( tuile->getContenu(3) == tuile->getVoisinDroite()->getContenu(7)
        && getEspace(tuile->getVoisinDroite()->getContenancePointeur(7)) != getEspace(tuile->getContenancePointeur(3)) )
            {
                Espace* toDelete = getEspace(tuile->getVoisinDroite()->getContenancePointeur(7));
        getEspace(tuile->getContenancePointeur(3))->Espace::fusionEspace(getEspace(tuile->getVoisinDroite()->getContenancePointeur(7)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
      // Troisième Contenu
        
        cout<<getEspace(tuile->getContenancePointeur(4))<<endl;
            if ( tuile->getContenu(4) == tuile->getVoisinDroite()->getContenu(6)
        && getEspace(tuile->getVoisinDroite()->getContenancePointeur(6)) != getEspace(tuile->getContenancePointeur(4)) )
                {
                    Espace* toDelete = getEspace(tuile->getVoisinDroite()->getContenancePointeur(6));
            getEspace(tuile->getContenancePointeur(4))->Espace::fusionEspace(getEspace(tuile->getVoisinDroite()->getContenancePointeur(6)));
                    // Si la fusion a lieu on supprime l'espace du voisin du haut
                    this->getPlateau()->supprimerEspace(toDelete);
                }
        
        
        
    }

    if ( tuile->getVoisinBas() != nullptr )
    {

        // Premier Contenu
          if(getEspace(tuile->getVoisinBas()->getContenancePointeur(2)) != getEspace(tuile->getContenancePointeur(4))){
            if ( tuile->getContenu(4) == tuile->getVoisinBas()->getContenu(2))
            {
                Espace* toDelete = getEspace(tuile->getVoisinBas()->getContenancePointeur(2));

        getEspace(tuile->getContenancePointeur(4))->Espace::fusionEspace(getEspace(tuile->getVoisinBas()->getContenancePointeur(2)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
          }
        // Deuxième Contenu

        if ( tuile->getContenu(5) == tuile->getVoisinBas()->getContenu(1)
                && getEspace(tuile->getVoisinBas()->getContenancePointeur(1)) != getEspace(tuile->getContenancePointeur(5)) )
            {
                Espace* toDelete = getEspace(tuile->getVoisinBas()->getContenancePointeur(1));     
        getEspace(tuile->getContenancePointeur(5))->Espace::fusionEspace(getEspace(tuile->getVoisinBas()->getContenancePointeur(1)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
      // Troisième Contenu
            if ( tuile->getContenu(6) == tuile->getVoisinBas()->getContenu(0)
                    && getEspace(tuile->getVoisinBas()->getContenancePointeur(0)) != getEspace(tuile->getContenancePointeur(6)) )
                {
                    Espace* toDelete = getEspace(tuile->getVoisinBas()->getContenancePointeur(0));

            getEspace(tuile->getContenancePointeur(6))->Espace::fusionEspace(getEspace(tuile->getVoisinBas()->getContenancePointeur(0)));
                    // Si la fusion a lieu on supprime l'espace du voisin du haut
                    this->getPlateau()->supprimerEspace(toDelete);
                }
        
    }
    
    
    
    
    
    if ( tuile->getVoisinGauche() != nullptr )
    {

        // Premier Contenu
             if(getEspace(tuile->getVoisinGauche()->getContenancePointeur(4)) != getEspace(tuile->getContenancePointeur(6))){
            if ( tuile->getContenu(6) == tuile->getVoisinGauche()->getContenu(4))
            {
                
                Espace* toDelete = getEspace(tuile->getVoisinGauche()->getContenancePointeur(4));

        getEspace(tuile->getContenancePointeur(6))->Espace::fusionEspace(getEspace(tuile->getVoisinGauche()->getContenancePointeur(4)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
             }
            
        // Deuxième Contenu
        
        if ( tuile->getContenu(7) == tuile->getVoisinGauche()->getContenu(3)
                && getEspace(tuile->getVoisinGauche()->getContenancePointeur(3)) != getEspace(tuile->getContenancePointeur(7)) )
            {
                Espace* toDelete = getEspace(tuile->getVoisinGauche()->getContenancePointeur(3));

    getEspace(tuile->getContenancePointeur(7))->Espace::fusionEspace(getEspace(tuile->getVoisinGauche()->getContenancePointeur(3)));
                // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
            }
      // Troisième Contenu
            if ( tuile->getContenu(0) == tuile->getVoisinGauche()->getContenu(2)
                    && getEspace(tuile->getVoisinGauche()->getContenancePointeur(2)) != getEspace(tuile->getContenancePointeur(0)) )
                {
                    Espace* toDelete = getEspace(tuile->getVoisinGauche()->getContenancePointeur(2));
            getEspace(tuile->getContenancePointeur(0))->Espace::fusionEspace(getEspace(tuile->getVoisinGauche()->getContenancePointeur(2)));
                    // Si la fusion a lieu on supprime l'espace du voisin du haut
                this->getPlateau()->supprimerEspace(toDelete);
                }
    }
    
    
}
