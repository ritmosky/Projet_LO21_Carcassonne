#ifndef VUEFORMNOM_H
#define VUEFORMNOM_H

#include "vueAccueil.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <iostream>



class VueFormNom : public QMainWindow
{
    Q_OBJECT
public:

    VueFormNom();
    ~VueFormNom();

    friend VueAccueil;

private:


    QList<QLabel*> m_listLabel;
    QList<QLineEdit*> m_listLineEdit;
    QVBoxLayout* m_vLayout;
    QWidget* n_window;
    QPushButton* m_commencer;


private slots:

     void commencer();



};

#endif // VUEFORMNOM_H
