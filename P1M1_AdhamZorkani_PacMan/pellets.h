#ifndef PELLETS_H
#define PELLETS_H

#include <QGraphicsPixmapItem>

class Pellets : public QGraphicsPixmapItem
{
public:
    Pellets();
    void setpellets(int row, int column);
};

#endif // PELLETS_H
