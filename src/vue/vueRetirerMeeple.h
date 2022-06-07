#ifndef VUERETIRERMEEPLE_H
#define VUERETIRERMEEPLE_H

#include <QDialog>
#include "vuePartie.h"
#include "modele/tuile.h"
#include <QAbstractButton>
#include "vueOuRetirerMeeple.h"



namespace Ui {
class VueRetirerMeeple;
}

class VueRetirerMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit VueRetirerMeeple(QWidget *parent = nullptr, VuePartie* partie = nullptr, const int l = 0, const int c = 0, Tuile* t = nullptr);
    ~VueRetirerMeeple();

private slots:
    void on_oui_clicked();
    void on_non_clicked();


private:
    Ui::VueRetirerMeeple *ui;
    VuePartie* partie;
    int Nligne;
    int NCol;
    Tuile* tuile;
};

#endif // VUERETIRERMEEPLE_H
