#include "powerpellets.h"

PowerPellets::PowerPellets(int Row, int Column)//draws the pellets
{
    QPixmap foodImage ("C:/Users/HP/CS2/PacMan/P1M1_AdhamZorkani_PacMan/pellets");
    foodImage = foodImage.scaledToWidth(50);
    foodImage = foodImage.scaledToHeight(50);
    setPixmap(foodImage);
    setPos(50+50*Column, 50+50*Row);
}
