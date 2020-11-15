#ifndef GHOSTS_H
#define GHOSTS_H

#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QRandomGenerator>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

class Ghost : public QGraphicsPixmapItem, QObject
{
private:
    QString ghostname;
    int row;
    int column;
    int move;
    int arr[12][12];
    QTimer * timer;
public:
    bool ghostmoving;
    Ghost (QString name, QString filename,int row, int column,int a[12][12]);
    void setrow(int);
    void setcolumn(int);
    int getrow();
    int getcolumn();
    QString getghostname();
    void moveghost(int arr[12][12]);\

};












#endif

