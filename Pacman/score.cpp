#include "score.h"


score::score(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString("Score: 0"));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 18));
}

void score::PowerPelletsScore(int Score)
{
    setPlainText(QString("Score: ") + QString::number(Score));
}

void score::PelletsScore(int Score)
{
    setPlainText(QString("Score: ") + QString::number(Score));
}
