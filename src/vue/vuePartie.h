#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include "mainwindow.h"
#include "nameWindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <iostream>


class VuePartie : public QMainWindow
{
    Q_OBJECT

public:

    VuePartie();
    ~VuePartie();


    friend NameWindow;
    friend MainWindow;

private:

        QWidget* P_window;



};

#endif // VUEPARTIE_H
