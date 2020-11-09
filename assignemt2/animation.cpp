#include "animation.h"
#include "ui_animation.h"
#include "ball.h"

animation::animation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::animation)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

     ui->graphicsView->setRenderHint(QPainter::Antialiasing);
     scene->setSceneRect(-200,-200,300,300); // to be at center
                 QPen mypen(Qt::red);
                 QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
                 QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
                 QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
                 QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );

                 scene->addLine(TopLine,mypen);
                 scene->addLine(LeftLine,mypen);
                 scene->addLine(RightLine,mypen);
                 scene->addLine(BottomLine,mypen);

                 int ItemCount=3;

                          for (int i=0;i<ItemCount;i++)
                          {
                              ball *new_ball= new ball;
                              scene->addItem(new_ball);
                          }

                          timer = new QTimer(this);
                          connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
                          timer->start(100);
}

animation::~animation()
{
    delete ui;
}

