#ifndef GHOSTS_H
#define GHOSTS_H

#include<QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>
#include "player.h"

class Ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString ghostname;
    int row;
    int column;
    int arr[12][12];
    int dik[70][70] ={ 0 };
public:
    static bool invincible;
    Ghost (QString name, QString filename,int row, int column,int a[12][12]);
    void setrow(int);
    void setcolumn(int);
    int getrow();
    int getcolumn();
    QString getghostname();
    QVector<QVector<int>> Dijkstra(int dik[70][70], int startNode);
public slots:
    void moveghost();
};












#endif

