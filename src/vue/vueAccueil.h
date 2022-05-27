#ifndef VUEACCUEIL_H
#define VUEACCUEIL_H

#include <QMainWindow>

namespace Ui {
class VueAccueil;
}

class VueAccueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit VueAccueil(QWidget *parent = nullptr);
    ~VueAccueil();
    void setNbrJoueur();
    int getNbrJoueur()const{return this->nbJoueur;}
private:
    Ui::VueAccueil *ui;
    int nbJoueur;

private slots:
        void on_pushButton_clicked();
};

#endif // VUEACCUEIL_H
