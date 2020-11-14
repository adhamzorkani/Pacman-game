#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QGraphicsTextItem>
#include <QFont>

class GameMode : public QGraphicsTextItem
{

public:
    GameMode(QGraphicsItem * parent = 0);
    void changeMode();
};

#endif // GAMEMODE_H
