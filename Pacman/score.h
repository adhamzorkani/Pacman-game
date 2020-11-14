#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class score : public QGraphicsTextItem
{

public:
    score(QGraphicsItem * parent = 0);
    void PelletsScore(int score);
    void PowerPelletsScore(int score);
};

#endif // SCORE_H
