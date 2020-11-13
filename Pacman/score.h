#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class score : public QGraphicsTextItem
{
private:
    int Score;
public:
    score(QGraphicsItem * parent = 0);
    void PelletsScore();
    void PowerPelletsScore();
    int getScore();
};

#endif // SCORE_H
