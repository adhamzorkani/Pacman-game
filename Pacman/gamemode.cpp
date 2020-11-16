#include "gamemode.h"

GameMode::GameMode(QGraphicsItem *parent)//initializes the text of the game mode
{
    setPlainText(QString("NORMAL"));//setting the text
    setDefaultTextColor(Qt::red);//setting the color
    setFont(QFont("times", 18));//setting the font and size
}
void GameMode::changeMode()//changes the game mode
{
    setPlainText(QString("INVINCIBLE"));
}
void GameMode::win()//outputs win if the player wins
{
    setPlainText(QString("YOU WON!!!!"));
}
void GameMode::lose()//outputs lose if the player loses
{
    setPlainText(QString("you lost :("));
}
