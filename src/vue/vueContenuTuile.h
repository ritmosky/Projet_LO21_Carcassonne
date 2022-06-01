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


public:
    explicit VueContenuTuile(TypesTuiles type, bool bouc, QWidget *parent = nullptr);
    ~VueContenuTuile();

    void setNomCouleur();
    TypesTuiles getTypeTuile() const {return this->typeTuile;}
    bool getBouclier()const {return this->bouclier;}





};

#endif // VUECONTENUTUILE_H
