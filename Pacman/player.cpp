#include "player.h"

Player::Player(int initialRow, int initialColumn, int d[12][12])
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = d[i][j];

    QPixmap playerImage("C:/Users/HP/CS2/PacMan/Pacman/PacMan.png");
    playerImage = playerImage.scaledToWidth(50);
    playerImage = playerImage.scaledToHeight(50);
    setPixmap(playerImage);
    row = initialRow;
    column = initialColumn;
    setPos(200 + 50 * column, 200 + 50 * row);
}
void Player::setRow(int newRow)
{
    row = newRow;
}
void Player::setColumn(int newColumn)
{
    column = newColumn;
}
int Player::getRow()
{
    return row;
}
int Player::getColumn()
{
    return column;
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up && data[row - 1][column] != -1)
    {
        row--;
    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] != -1)
    {
        row++;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] != -1)
    {
        column++;
        if(data[row][column] == 41)
            column = column - 11;
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] != -1)
    {
        column--;
        if(data[row][column] == 36)
            column = column + 11;
    }
    setPos(200 + 50 * column, 200 + 50 * row);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Pellets))
        {
            scene()->removeItem(items[i]);
            //Score->PelletsScore();

        }

    }

    QList<QGraphicsItem*> items2 = collidingItems();
    for (int i = 0; i < items2.size(); i++)
    {
        if (typeid(*items2[i]) == typeid(PowerPellets))
        {
            scene()->removeItem(items2[i]);
            //Score->PowerPelletsScore();

        }
    }
}
