#ifndef VUEOURETIRERMEEPLE_H
#define VUEOURETIRERMEEPLE_H

#include <QDialog>
#include "vuePartie.h"
#include "modele/tuile.h"
#include <QAbstractButton>



namespace Ui {
class VueOuRetirerMeeple;
}


class VueOuRetirerMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit VueOuRetirerMeeple(QWidget *parent=nullptr,VuePartie* partie=nullpt);
    ~VueOuRetirerMeeple();

    void retirerM(VueTuile& vt);
    void printTuile(Tuile& tuile);

private slots:
    void on_OUI_clicked();

private:
    Ui::VueOuRetirerMeeple *ui;
    VuePartie* partie;
};

#endif // VUEOURETIRERMEEPLE_H
