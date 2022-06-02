#ifndef VUECONTENUTUILE_H
#define VUECONTENUTUILE_H

#include <QWidget>
#include "../modele/tuile.h"

namespace Ui {
class VueContenuTuile;
}

class VueContenuTuile : public QWidget
{
    Q_OBJECT

private:
    Ui::VueContenuTuile *ui;
    TypesTuiles typeTuile;
    bool bouclier;
    int idJoueurMeeple;
    bool meeple;


public:
    explicit VueContenuTuile(TypesTuiles type, bool bouc, QWidget *parent = nullptr);
    explicit VueContenuTuile(TypesTuiles type, bool bouc,int id, bool meeple, QWidget *parent = nullptr);
    ~VueContenuTuile();

    void setNomCouleurSansM();
    void setNomCouleurAvecM(const int& id);
    TypesTuiles getTypeTuile() const {return this->typeTuile;}
    bool getBouclier()const {return this->bouclier;}





};

#endif // VUECONTENUTUILE_H
