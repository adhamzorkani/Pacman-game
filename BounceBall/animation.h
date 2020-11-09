#ifndef ANIMATION_H
#define ANIMATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class animation; }
QT_END_NAMESPACE

class animation : public QMainWindow
{
    Q_OBJECT

public:
    animation(QWidget *parent = nullptr);
    ~animation();

private:
    Ui::animation *ui;
};
#endif // ANIMATION_H
