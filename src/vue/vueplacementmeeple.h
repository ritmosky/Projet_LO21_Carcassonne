#ifndef VUEPLACEMENTMEEPLE_H
#define VUEPLACEMENTMEEPLE_H

#include "modele/tuile.h"
#include <QDialog>
#include <QAbstractButton>>
#include "vuePartie.h"


namespace Ui {
class vuePlacementMeeple;
}

class vuePlacementMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit vuePlacementMeeple(QWidget *parent = nullptr, VuePartie* partie = nullptr, const int Nligne = 0, const int NCol = 0,Tuile* tuile = nullptr);
    ~vuePlacementMeeple();
private slots:

    void on_Non_clicked(vuePlacementMeeple* affichage );

    void on_Oui_clicked(vuePlacementMeeple* affichage );


private:
    Ui::vuePlacementMeeple *ui;
    VuePartie* partie;
    const int Nligne;
    const int NCol;
    Tuile* tuile;
};

#endif // VUEPLACEMENTMEEPLE_H
