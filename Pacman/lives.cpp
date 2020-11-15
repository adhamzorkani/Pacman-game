#include "lives.h"

lives::lives(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString("Lives: 3"));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 18));
}

void lives::livesDecrease(int Lives)
{
    setPlainText(QString("Score: ") + QString::number(Lives));
}
