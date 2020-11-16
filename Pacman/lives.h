#ifndef LIVES_H
#define LIVES_H


#include <QGraphicsTextItem>
#include <QFont>

class lives : public QGraphicsTextItem
{
public:
    lives(QGraphicsItem * parent = 0);
    void livesDecrease(int L);
};

#endif // LIVES_H
