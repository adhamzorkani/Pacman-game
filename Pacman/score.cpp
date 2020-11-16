#include "score.h"


score::score(QGraphicsItem * parent) : QGraphicsTextItem(parent)//initiallises and draws the score
{
    setPlainText(QString("Score: 0"));//sets the initial score
    setDefaultTextColor(Qt::blue);//sets the score
    setFont(QFont("times", 18));//sets the font and the size
}
void score::PowerPelletsScore(int Score)//adjust the new score
{
    setPlainText(QString("Score: ") + QString::number(Score));
}
void score::PelletsScore(int Score)//adjusts the new score
{
    setPlainText(QString("Score: ") + QString::number(Score));
}
