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
    int numPlacement;

public:
    explicit VueContenuTuile(TypesTuiles type, int numPlacement, QWidget *parent = nullptr);
    ~VueContenuTuile();

    void setCouleur();
    void setNom();
    TypesTuiles getTypeTuile() const {return this->typeTuile;}





};

#endif // VUECONTENUTUILE_H
