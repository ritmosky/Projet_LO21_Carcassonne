#ifndef VUEPLATEAU_H
#define VUEPLATEAU_H

#include <QWidget>

namespace Ui {
class VuePlateau;
}

class VuePlateau : public QWidget
{
    Q_OBJECT

public:
    explicit VuePlateau(QWidget *parent = nullptr);
    void setTable();
    ~VuePlateau();


private:
    Ui::VuePlateau *ui;
};

#endif // VUEPLATEAU_H
