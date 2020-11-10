#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[10][10];
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
