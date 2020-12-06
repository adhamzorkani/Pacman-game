#include "Ghost.h"

using namespace std;

Ghost::Ghost(QString name, QString filename, int initialrow,int initialcolumn,int a[12][12])//initiallises the positions the ghosts
{                                                                                           // and draws them
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
         QVector<QVector<int>> Dik = Dijkstra(dik, arr[row][column]);
         int last = Dik[arr[Player::currentRow][Player::currentCol]].size();
                if (Dik[arr[Player::currentRow][Player::currentCol]][last - 2] == arr[row-1][column])
                    {
                         row--;
                         setPos(50 + 50 *column, 50 + 50 * row);
                    }
                else if (Dik[arr[Player::currentRow][Player::currentCol]][last - 2] == arr[row+1][column])
                    {
                        row++;
                        setPos(50 + 50 *column, 50 + 50 * row);
                    }
                else if (Dik[arr[Player::currentRow][Player::currentCol]][last - 2] == arr[row][column+1])
                    {
                        column++;
                        if(arr[row][column] == 43)
                            column = column - 11;
                        setPos(50 + 50 *column, 50 + 50 * row);
                    }
                else if (Dik[arr[Player::currentRow][Player::currentCol]][last - 2] == arr[row][column-1])
                    {
                        column--;
                        if(arr[row][column] == 36)
                            column = column + 11;
                        setPos(50 + 50 *column, 50 + 50 * row);
                    }
                /*int random = rand()%4+1;
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
         setPos(50 + 50 *column, 50 + 50 * row);*/
 }
 QVector<QVector<int>> Ghost::Dijkstra(int Graph[70][70], int startNode)
 {
     const int INFINITE = 9999;
     int temp[70][70], costs[70], previous[70];
     bool visited[70];
     // temp
     for (int i = 0; i < 70; i++)
         for (int j = 0; j < 70; j++)
             if (Graph[i][j] == 0)
                 temp[i][j] = INFINITE;
             else
                 temp[i][j] = Graph[i][j];
     // costs, previous, and visited
     for (int i = 0; i < 70; i++)
     {
         costs[i] = temp[startNode][i];
         previous[i] = startNode;
         visited[i] = false;
     }
     // startNode
     costs[startNode] = 0;
     visited[startNode] = true;

     int count = 1, nextNode, minimumCost;
     while (count < 70)
     {
         // Find the minimum cost in order to visit a node.
         minimumCost = INFINITE;
         for (int i = 0; i < 70; i++)
             if ((costs[i] < minimumCost) && (visited[i] == false))
             {
                 minimumCost = costs[i];
                 nextNode = i;
             }
         // Visit the node.
         visited[nextNode] = true;
         // Update the costs of the children of the visited node.
         for (int i = 0; i < 70; i++)
             if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
             {
                 costs[i] = minimumCost + temp[nextNode][i];
                 previous[i] = nextNode;
             }
         count++;
     }
     // Fill the paths.
     int j;
     QVector<QVector<int>> paths;
     paths.resize(70);
     for (int i = 0; i < 70; i++)
     {
         paths[i].push_back(i);
         if (i != startNode)
         {
             j = i;
             do
             {
                 j = previous[j];
                 paths[i].push_back(j);
             } while (j != startNode);
         }
     }
     return paths;
 }
