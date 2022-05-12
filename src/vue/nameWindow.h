#ifndef NAMEWINDOW_H
#define NAMEWINDOW_H

#include "mainwindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <iostream>


class NameWindow : public QMainWindow
{
    Q_OBJECT
public:

    NameWindow();
    ~NameWindow();

    friend MainWindow;

private:


    QList<QLabel*> m_listLabel;
    QList<QLineEdit*> m_listLineEdit;
    QVBoxLayout* m_vLayout;
    QWidget* n_window;
    QPushButton* m_commencer;


private slots:

     void commencer();



};

#endif // NAMEWINDOW_H
