#include "pellets.h"

Pellets::Pellets(int Row, int Column)
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/Pacman/pellets");
    foodImage = foodImage.scaledToWidth(30);
    foodImage = foodImage.scaledToHeight(30);
    setPixmap(foodImage);
    setPos(200+50*Column, 200+50*Row);
}
