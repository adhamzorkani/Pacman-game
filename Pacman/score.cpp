#include "score.h"


score::score(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    int Score = 0;
    setPlainText(QString("Score: ") + QString::number(Score));
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
