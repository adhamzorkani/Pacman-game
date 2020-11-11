#include "powerpellets.h"

PowerPellets::PowerPellets(int Row, int Column)
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/Pacman/pellets");
    foodImage = foodImage.scaledToWidth(50);
    foodImage = foodImage.scaledToHeight(50);
    setPixmap(foodImage);
    setPos(200+50*Column, 200+50*Row);
}
