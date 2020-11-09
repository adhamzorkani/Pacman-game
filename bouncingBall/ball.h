#ifndef BALL_H
#define BALL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ball; }
QT_END_NAMESPACE

class ball : public QMainWindow
{
    Q_OBJECT

public:
    ball(QWidget *parent = nullptr);
    ~ball();

private:
    Ui::ball *ui;
};
#endif // BALL_H
