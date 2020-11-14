#include "gamemode.h"

GameMode::GameMode(QGraphicsItem *parent)
{
    setPlainText(QString("NORMAL"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 18));
}

void GameMode::changeMode()
{
    int i = 0;
    while(i != 10)
    {
        setPlainText(QString("INVINCIBLE"));
        i++;
    }
}
