#include <QApplication>
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QAbstractScrollArea>
#include <QGraphicsTextItem>
#include "player.h"
#include "pellets.h"
#include "powerpellets.h"
#include "score.h"
#include "lives.h"
#include "gamemode.h"
#include "Ghost.h"

//before running change the directory of the files in the main and the classes: pellets, powerpellet and player.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView view;// creating the view that will contain the scene
    view.setFixedSize(800,600);
    view.setWindowTitle("PacMan");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    QGraphicsScene scene;//creating the scene that will contain the objects drawn
    view.setScene(&scene);
    QFile file("C:/Users/HP/CS2/PacMan/Pacman/board.txt");//start of drawing board
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
           boardImage[i][j].setPos(50+50*j,50+50*i);
           scene.addItem(&boardImage[i][j]);


       }//end of drawing the board

   score * Score;
   Score = new score();
   scene.addItem(Score);//drawing the score on the screen
   lives * Lives;
   Lives = new lives();
   Lives->setPos(Lives->x(), Lives->y()+25);//setting the position of lives
   scene.addItem(Lives);//drawing the lives on the screen
   GameMode * mode;
   mode = new GameMode();
   mode->setPos(mode->x()+300, mode->y());//setting game mode text position
   scene.addItem(mode);//drawing the game mode
   Pellets P[60];// start of drawing pellets
   int k = 0;
       for(int i = 1; i < 12; i++)
           for(int j = 1; j < 12; j++)
           {

                if(boardData[i][j] != -1 && boardData[i][j] != 31 && boardData[i][j] != 32 && boardData[i][j] != 39
                && boardData[i][j] != 40 && boardData[i][j] != 00 && boardData[i][j] != 07 && boardData[i][j] != 64 && boardData[i][j] != 69
                && boardData[i][j] != 43 && boardData[i][j] != 36 && boardData[i][j] != 59 && k != 60)
                    {

                            P[k].setpellets(i, j);
                            scene.addItem(&P[k]);
                            k++;
                    }

          }// end of drawing pellets

   PowerPellets pp1(1,1), pp2(1 , 10), pp3(10, 1), pp4(10, 10);//drawing power pellets
   scene.addItem(&pp1);
   scene.addItem(&pp2);
   scene.addItem(&pp3);
   scene.addItem(&pp4);

   Ghost * pinky;//start of adding ghosts
   pinky = new Ghost("Pinky","C:/Users/HP/CS2/PacMan/Pacman/pinky.png", 5,5,boardData);
   scene.addItem(pinky);
   Ghost * inky;
   inky = new Ghost("Inky","C:/Users/HP/CS2/PacMan/Pacman/inky.png", 6,5,boardData);
   scene.addItem(inky);
   Ghost * clyde;
   clyde = new Ghost("Clyde","C:/Users/HP/CS2/PacMan/Pacman/clyde.png" ,6,6,boardData);
   scene.addItem(clyde);// end of adding ghost

   Player p(9,5,boardData ,Score, Lives, mode, inky, pinky, clyde);//drawing pacman
   scene.addItem(&p);
   p.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
   p.setFocus();

   view.show();
    return a.exec();
}
