#include "pellets.h"

Pellets::Pellets()
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/Pacman/pellets");
    foodImage = foodImage.scaledToWidth(30);
    foodImage = foodImage.scaledToHeight(30);
    setPixmap(foodImage);

}

void Pellets::setpellets(int Row, int Column)
{
    setPos(50+50*Column, 50+50*Row);
}
