#include "ball.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ball w;
    w.show();
    return a.exec();
}
