#include "ball.h"
#include "ui_ball.h"

ball::ball(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ball)
{
    ui->setupUi(this);
}

ball::~ball()
{
    delete ui;
}

