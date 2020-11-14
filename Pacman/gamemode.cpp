#include "gamemode.h"

GameMode::GameMode(QGraphicsItem *parent)
{
    setPlainText(QString("NORMAL"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 18));
}

void GameMode::changeMode()
{
    setPlainText(QString("INVINCIBLE"));
}
