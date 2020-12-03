#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QGraphicsTextItem>
#include <QFont>

class GameMode : public QGraphicsTextItem
{

public:
    GameMode(QGraphicsItem * parent = 0);
    void changeMode();
    void win();
    void lose();
};

#endif // GAMEMODE_H
