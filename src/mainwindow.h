#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();






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


private slots:
     void exit();
     void next();
     void NewWindow();

};



#endif // MAINWINDOW_H
