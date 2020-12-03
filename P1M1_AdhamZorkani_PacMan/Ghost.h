#ifndef GHOSTS_H
#define GHOSTS_H

#include<QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

class Ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString ghostname;
    int row;
    int column;
    int move;
    int arr[12][12];
    int dik[70][70] ={ 0 };
public:
    bool ghostmoving;
    Ghost (QString name, QString filename,int row, int column,int a[12][12]);
    void setrow(int);
    void setcolumn(int);
    int getrow();
    int getcolumn();
    QString getghostname();
    static bool invincible;
    int dijkstra(int a[70][70], int a2[12][12]);
public slots:
    void moveghost();
};












#endif

