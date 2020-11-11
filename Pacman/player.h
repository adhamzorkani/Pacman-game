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

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[12][12];
public:
    Player(int initialRow, int initialColumn, int d[12][12]);
    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // PLAYER_H
