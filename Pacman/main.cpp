#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView view;
    view.setFixedSize(700,700);
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
          
   Player p(10,5,boardData);
   scene.addItem(&p);
   p.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
   p.setFocus();
            
   view.show();
    return a.exec();
}
