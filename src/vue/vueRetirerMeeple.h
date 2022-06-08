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
    explicit VueRetirerMeeple(VuePartie* partie=nullptr,QWidget *parent=nullptr);
    ~VueRetirerMeeple();

private slots:
    void on_oui_clicked();
    void on_non_clicked();


private:
    Ui::VueRetirerMeeple *ui;
    VuePartie* partie;
};

#endif // VUERETIRERMEEPLE_H
