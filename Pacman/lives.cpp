#include "lives.h"

lives::lives(QGraphicsItem * parent) : QGraphicsTextItem(parent)//initiallises the lives text
{
    setPlainText(QString("Lives: 3"));//sets the initial text
    setDefaultTextColor(Qt::yellow);//set the color
    setFont(QFont("times", 18));// sets the font and size
}

void lives::livesDecrease(int Lives)//adjust the lives in case of pacman and ghost collision
{
    setPlainText(QString("Score: ") + QString::number(Lives));
}
