#include "animation.h"
#include "ui_animation.h"

animation::animation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::animation)
{
    ui->setupUi(this);
}

animation::~animation()
{
    delete ui;
}

