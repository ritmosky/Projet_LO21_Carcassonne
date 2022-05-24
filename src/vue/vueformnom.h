#ifndef VUEFORMNOM_H
#define VUEFORMNOM_H


#include "mainwindow.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class VueFormNom; }
QT_END_NAMESPACE


class VueFormNom : public QWidget
{
    Q_OBJECT

public:
    explicit VueFormNom(QWidget *parent = nullptr);
    ~VueFormNom();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::VueFormNom *ui;
    QWidget* m_window;
    QList<QLineEdit*> m_listLineEdit;
    QList<QLabel*> m_listLabel;
    QVBoxLayout* m_vLayout;
    QVBoxLayout* m_vLayout2;
    QLabel* L_prenom;
    QLineEdit* m_prenom;

};

#endif //VUEFORMNOM_H
