#ifndef VUECONTENUTUILE_H
#define VUECONTENUTUILE_H

#include <QWidget>

namespace Ui {
class VueContenuTuile;
}

class VueContenuTuile : public QWidget
{
    Q_OBJECT

private:
    Ui::VueContenuTuile *ui;
    int typeTuile;
    int numPlacement;

public:
    explicit VueContenuTuile(int type, int numPlacement, QWidget *parent = nullptr);
    ~VueContenuTuile();

    void setCouleur();
    void setNom();
    int getTypeTuile() const {return this->typeTuile;}





};

#endif // VUECONTENUTUILE_H
