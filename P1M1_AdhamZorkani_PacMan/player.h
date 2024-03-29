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
    char direction;
    score* Score;
    GameMode * mode;
    lives * Lives;
public:
    static int currentRow;
    static int currentCol;
    Player(int initialRow, int initialColumn, int d[12][12] , score* Score, lives * Lives, GameMode * mode);
    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
    int getScore();
    int getlives();
public slots:
    void keyPressEvent(QKeyEvent *event);
    void movePlayer();
};
#endif // PLAYER_H
