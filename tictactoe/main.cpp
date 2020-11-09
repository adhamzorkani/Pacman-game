#include "tictactoe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TICTACTOE w;
    w.show();
    return a.exec();
}
