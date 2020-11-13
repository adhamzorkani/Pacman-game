#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QAbstractScrollArea>
#include "player.h"
#include "pellets.h"
#include "powerpellets.h"
#include "score.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView view;
    view.setFixedSize(800,600);
    view.setWindowTitle("PacMan");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    QGraphicsScene scene;
    view.setScene(&scene);
    QFile file("C:/Users/HP/CS2/PacMan/Pacman/board.txt");
   file.open(QIODevice::ReadOnly);
   int boardData[12][12];
   QTextStream stream(&file);
   QString temp;
   for (int i = 0; i<12;i++)
   for (int j=0;j<12;j++)
   {
       stream >> temp;
       boardData[i][j] = temp.toInt();
   }

     QPixmap bricksImage("C:/Users/HP/CS2/PacMan/Pacman/border1.png");
     bricksImage = bricksImage.scaledToWidth(50);
     bricksImage = bricksImage.scaledToHeight(50);
     QPixmap floorImage("C:/Users/HP/CS2/PacMan/Pacman/grass1.png");
     floorImage = floorImage.scaledToWidth(50);
     floorImage = floorImage.scaledToHeight(50);
   QGraphicsPixmapItem boardImage[12][12];
   for (int i=0;i<12;i++)
       for(int j=0; j<12;j++)
       {
           if(boardData[i][j]==-1)
               boardImage[i][j].setPixmap(bricksImage);
               else
               boardImage[i][j].setPixmap(floorImage);
           boardImage[i][j].setPos(200+50*j,200+50*i);
           scene.addItem(&boardImage[i][j]);


       }

   Player p(9,5,boardData);
   scene.addItem(&p);
   p.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
   p.setFocus();

   score * Score;
   Score = new score();
   scene.addItem(Score);

   Pellets P[60];
 for(int k = 0; k < 60 ; k++)
   {
       for(int i = 1; i < 12; i++)
           for(int j = 1; j < 12; j++)
           {
                if(boardData[i][j] != -1 && boardData[i][j] != 31 && boardData[i][j] != 32 && boardData[i][j] != 39
                && boardData[i][j] != 40 && boardData[i][j] != 00 && boardData[i][j] != 07 && boardData[i][j] != 62 && boardData[i][j] != 67)
                    {
                        P[k].setpellets(i, j);
                        scene.addItem(&P[k]);
                        k++;
                        j++;
                    }
           }
    }

   PowerPellets pp1(1,1), pp2(1 , 10), pp3(10, 1), pp4(10, 10);
   scene.addItem(&pp1);
   scene.addItem(&pp2);
   scene.addItem(&pp3);
   scene.addItem(&pp4);

   view.show();
    return a.exec();
}
