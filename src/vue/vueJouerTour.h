#ifndef VUEJOUERTOUR_H
#define VUEJOUERTOUR_H

#include <QWidget>

namespace Ui {
class VueJouerTour;
}

class VueJouerTour : public QWidget
{
    Q_OBJECT

public:
    explicit VueJouerTour(QWidget *parent = nullptr);
    ~VueJouerTour();

private:
    Ui::VueJouerTour *ui;
};

#endif // VUEJOUERTOUR_H
