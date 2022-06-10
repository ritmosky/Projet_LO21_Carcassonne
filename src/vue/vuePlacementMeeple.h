#ifndef VUEPLACEMENTMEEPLE_H
#define VUEPLACEMENTMEEPLE_H

#include "modele/tuile.h"
#include <QDialog>
#include <QAbstractButton>
#include "vuePartie.h"
#include "vueOuPlacerMeeple.h"


namespace Ui {
class vuePlacementMeeple;
}

class vuePlacementMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit vuePlacementMeeple(QWidget *parent = nullptr, VuePartie* partie = nullptr, const int l = 0, const int c = 0,Tuile* tuile = nullptr,Controller* con=nullptr);
    ~vuePlacementMeeple();

    inline int getNligne()const {return Nligne;}
    inline int getNCol()const {return NCol;}

private slots:

    void on_Non_clicked();
    void on_Oui_clicked();

private:
    Ui::vuePlacementMeeple *ui;
    VuePartie* partie;
    const int Nligne;
    const int NCol;
    Tuile* tuile;
    Controller* controller;
};

#endif // VUEPLACEMENTMEEPLE_H
