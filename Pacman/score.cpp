#include "score.h"


score::score(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    Score = 0;
    setPlainText(QString("Score: ") + QString::number(Score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 18));
}

void score::PowerPelletsScore()
{
    Score = Score + 30;
    setPlainText(QString("Score: ") + QString::number(Score));
}

int score::getScore()
{
    return Score;
}

void score::PelletsScore()
{
    Score = Score + 10;
    setPlainText(QString("Score: ") + QString::number(Score));
}
