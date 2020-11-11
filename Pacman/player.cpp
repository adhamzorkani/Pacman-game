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
    setPos(50 + 50 * column, 50 + 50 * row);
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
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] != -1)
    {
        column--;
    }
    setPos(50 + 50 *column, 50 + 50 * row);
}
