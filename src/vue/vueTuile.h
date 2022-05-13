#ifndef VUETUILE_H
#define VUETUILE_H

#include <QWidget>

namespace Ui {
class VueTuile;
}

class VueTuile : public QWidget
{
    Q_OBJECT

public:
    explicit VueTuile(QWidget *parent = nullptr);
    ~VueTuile();

private:
    Ui::VueTuile *ui;
};

#endif // VUETUILE_H
