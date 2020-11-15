#include "Ghost.h"


using namespace std;
Ghost::Ghost(QString name, QString filename, int initialrow,int initialcolumn,int a[12][12])
{
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
            arr[i][j] = a[i][j];


    ghostname = name;
row = initialrow;
column = initialcolumn;
setPos(50+50*column , 50+50*row );
QPixmap m(filename);
m = m.scaledToWidth(50);
m = m.scaledToHeight(50);
setPixmap(m);
/*timer = new QTimer();
connect(timer, SIGNAL(timeout()),this, SLOT(moveghost()));
timer->start(100);*/

}

void Ghost::setrow(int x)
{
row = x;
}
void Ghost::setcolumn(int y)
{
    column = y;
}
int Ghost::getrow()
{
    return row;
}
int Ghost::getcolumn()
{
    return column;
}
QString Ghost::getghostname()
{
    return ghostname;
}


 void Ghost::moveghost(int arr[12][12])
 {
     int random = rand()%4+1;
     if (random == 1 && arr[row - 1][column] != -1)
     {
         row--;
     }
     else if (random == 2 && arr[row + 1][column] != -1)
     {
         row++;
     }
     else if (random == 3 && arr[row][column + 1] != -1)
     {
         column++;
     }
     else if (random == 4 && arr[row][column - 1] != -1)
     {
         column--;
     }
     setPos(50 + 50 *column, 50 + 50 * row);
 }
