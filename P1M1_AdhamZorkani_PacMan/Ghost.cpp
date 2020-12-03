#include "Ghost.h"


using namespace std;
Ghost::Ghost(QString name, QString filename, int initialrow,int initialcolumn,int a[12][12])//initiallises the positions the ghosts
{                                                   // and draws them
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
    for(int i = 0; i < 12;i++)
        for(int j = 0; j < 12;j++)
        {
            if(arr[i][j] != -1)
            {
                int current = arr[i][j];
                if(arr[i][j+1] != -1)
                    dik[current][arr[i][j+1]] = 1;
                if(arr[i][j-1] != -1)
                    dik[current][arr[i][j-1]] = 1;
                if(arr[i+1][j] != -1)
                    dik[current][arr[i+1][j]] = 1;
                if(arr[i-1][j] != -1)
                    dik[current][arr[i-1][j]] = 1;
            }
        }

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
 void Ghost::moveghost()// this function controls the movement of the ghosts
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
            if(arr[row][column] == 43)
                column = column - 11;
        }
        else if (random == 4 && arr[row][column - 1] != -1)
        {
            column--;
            if(arr[row][column] == 36)
                column = column + 11;
        }
         setPos(50 + 50 *column, 50 + 50 * row);
       //dijkstra(dik, arr[row][column]);
 }
