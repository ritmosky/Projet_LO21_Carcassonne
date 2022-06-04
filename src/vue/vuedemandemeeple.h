#ifndef VUEDEMANDEMEEPLE_H
#define VUEDEMANDEMEEPLE_H


#include <QWidget>


namespace Ui {
class VueDemandeMeeple;
}

class VueDemandeMeeple : public QWidget
{
    Q_OBJECT

public:
    explicit VueDemandeMeeple(QWidget *parent = nullptr);
    ~VueDemandeMeeple();


private:
    Ui::VueDemandeMeeple *ui;
};

#endif // VUEDEMANDEMEEPLE_H
