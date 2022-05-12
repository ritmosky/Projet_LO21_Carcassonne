#ifndef VUEACCUEIL_H
#define VUEACCUEIL_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <iostream>
#include <QString>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;

class VueAccueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit VueAccueil(QWidget *parent = nullptr);
    ~VueAccueil();


    inline int IntNBjoueur();



private:
    Ui::MainWindow *ui;
    QPushButton* m_Quit;
    QPushButton* m_Next;
    QLabel* m_NBjoueur;
    QFormLayout *NBjoueurLayout;
    QLineEdit* L_NBjoueur;
    QLabel* m_extention;
    QLineEdit* L_extention;
    QLabel* Choix_Extention;
    QGridLayout* layoutPlateau;
    QHBoxLayout* layoutInformations;
    QVBoxLayout* m_vLayout;
    QLabel* score;

    friend int add(VueAccueil, VueAccueil);

    int resultat_;


private slots:
     void exit();
     void next();

};

#endif // VUEACCUEIL_H

