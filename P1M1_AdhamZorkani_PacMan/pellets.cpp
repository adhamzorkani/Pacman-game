#include "pellets.h"

Pellets::Pellets()//draws the pellets
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/P1M1_AdhamZorkani_PacMan/pellets");
    foodImage = foodImage.scaledToWidth(30);
    foodImage = foodImage.scaledToHeight(30);
    setPixmap(foodImage);

}

void Pellets::setpellets(int Row, int Column)//sets the pellets positions
{
    setPos(50+50*Column, 50+50*Row);
}
