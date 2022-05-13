#ifndef VUECONTENUTUILE_H
#define VUECONTENUTUILE_H

#include <QWidget>

namespace Ui {
class VueContenuTuile;
}

class VueContenuTuile : public QWidget
{
    Q_OBJECT

public:
    explicit VueContenuTuile(QWidget *parent = nullptr);
    ~VueContenuTuile();

private:
    Ui::VueContenuTuile *ui;
};

#endif // VUECONTENUTUILE_H
