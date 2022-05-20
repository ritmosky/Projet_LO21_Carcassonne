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


public:
    explicit VueContenuTuile(TypesTuiles type, QWidget *parent = nullptr);
    ~VueContenuTuile();

    void setNomCouleur();
    TypesTuiles getTypeTuile() const {return this->typeTuile;}





};

#endif // VUECONTENUTUILE_H
