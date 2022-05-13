#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QMainWindow>

namespace Ui {
class VuePartie;
}

class VuePartie : public QMainWindow
{
    Q_OBJECT

public:
    explicit VuePartie(QWidget *parent = nullptr);
    ~VuePartie();
    void setAffichageScore();

private:
    Ui::VuePartie *ui;
};

#endif // VUEPARTIE_H
