#ifndef LIVES_H
#define LIVES_H


#include <QGraphicsTextItem>
#include <QFont>

class lives : public QGraphicsTextItem
{
private:
    int Lives;
public:
    lives(QGraphicsItem * parent = 0);
    void livesDecrease();
    int getlives();
};

#endif // LIVES_H
