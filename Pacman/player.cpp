#include "player.h"

Player::Player(int initialRow, int initialColumn, int d[12][12] , score* S, lives * L, GameMode * M, Ghost * i, Ghost * p, Ghost * c)
{//draws pacmanand initiallises the objects of the ghosts, lives, score and gamemode
    Pscore = 0;
    Plives = 3;
    Score = S;
    Lives = L;
    mode = M;
    I = i;
    P = p;
    C = c;
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

int Player::getScore()
{
    return Pscore;
}
int Player::getlives()
{
    return Plives;
}
void Player::keyPressEvent(QKeyEvent *event)//controls the movement of pacman
{
    if (event->key() == Qt::Key_Up && data[row - 1][column] != -1)
    {
        row--;
        I->moveghost();//when pacman moves the ghosts move
        P->moveghost();
        C->moveghost();
    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] != -1)
    {
        row++;
        I->moveghost();
        P->moveghost();
        C->moveghost();
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] != -1)
    {
        column++;
        if(data[row][column] == 43)
            column = column - 11;
        I->moveghost();
        P->moveghost();
        C->moveghost();
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] != -1)
    {
        column--;
        if(data[row][column] == 36)
            column = column + 11;
        I->moveghost();
        P->moveghost();
        C->moveghost();
    }
    setPos(50 + 50 * column, 50 + 50 * row);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Pellets))
        {
            Pscore += 10;
            Score->PelletsScore(Pscore);//outputs the new score
            scene()->removeItem(items[i]);//removes the pellets when collides with pacman
            if(Pscore == 710)
            {
                mode->win();// outputs win if the score is 710
            }
        }

    }

    QList<QGraphicsItem*> items2 = collidingItems();
    for (int i = 0; i < items2.size(); i++)
    {
        if (typeid(*items2[i]) == typeid(PowerPellets))
        {
            Pscore += 30;
            Score->PowerPelletsScore(Pscore);//outputs the new score
            mode->changeMode();//changes the gamemode to invincible when pacman eats a pellet
            scene()->removeItem(items2[i]);//removess the powerpellets when they collide with pacman
            if(Pscore == 710)
            {
                mode->win();// if the score is 710 it outputs win
            }
        }
    }

    QList<QGraphicsItem*> items3 = collidingItems();
    for (int i = 0; i < items3.size(); i++)
    {
        if (typeid(*items3[i]) == typeid(Ghost))
        {
            Plives -= 1;
            Lives->livesDecrease(Plives);// outputs the new lives
            if(Plives == 0)
            {
                mode->lose();// if the lives became 0 it outputs you lost
            }
        }

    }
}
