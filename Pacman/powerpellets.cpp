#include "powerpellets.h"

PowerPellets::PowerPellets(int Row, int Column)
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/Pacman/pellets");
    foodImage = foodImage.scaledToWidth(50);
    foodImage = foodImage.scaledToHeight(50);
    setPixmap(foodImage);
    setPos(50+50*Column, 50+50*Row);
}
