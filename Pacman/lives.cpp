#include "lives.h"

lives::lives(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    Lives = 3;
    setPlainText(QString("Lives: ") + QString::number(Lives));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 18));
}

void lives::livesDecrease()
{
    Lives--;
    setPlainText(QString("Score: ") + QString::number(Lives));
}

int lives::getlives()
{
    return Lives;
}


