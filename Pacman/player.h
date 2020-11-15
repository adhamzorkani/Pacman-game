#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QList>
#include "pellets.h"
#include "powerpellets.h"
#include <QGraphicsScene>
#include "score.h"
#include "lives.h"
#include "gamemode.h"
#include "Ghost.h"
#include <QTimer>
#include <QGraphicsScene>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int Pscore;
    int Plives;
    int data[12][12];
    score* Score;
    GameMode * mode;
    lives * Lives;
    Ghost * I;
    Ghost * P;
    Ghost * C;
public:
    Player(int initialRow, int initialColumn, int d[12][12] , score* Score, lives * Lives, GameMode * mode, Ghost * i, Ghost * p, Ghost * c);
    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
    int getScore();
    int getlives();
private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // PLAYER_H
