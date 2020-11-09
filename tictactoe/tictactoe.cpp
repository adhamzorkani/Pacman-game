#include "tictactoe.h"
#include "ui_tictactoe.h"

TICTACTOE::TICTACTOE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TICTACTOE)
{
    ui->setupUi(this);
}

TICTACTOE::~TICTACTOE()
{
    delete ui;
}


void TICTACTOE::on_pushButton_clicked()
{
    if(clickedButton[0]== 0)
    {
        int player = playerTurn(0);
        if(player == 1)
        {
            ui->pushButton->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton->setText("O");
        }
    }

}

void TICTACTOE::on_pushButton_2_clicked()
{
    if(clickedButton[1]== 0)
    {
        int player = playerTurn(1);
        if(player == 1)
        {
            ui->pushButton_2->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_2->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_3_clicked()
{
    if(clickedButton[2]== 0)
    {
        int player = playerTurn(2);
        if(player == 1)
        {
            ui->pushButton_3->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_3->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_4_clicked()
{
    if(clickedButton[3]== 0)
    {
        int player = playerTurn(3);
        if(player == 1)
        {
            ui->pushButton_4->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_4->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_5_clicked()
{
    if(clickedButton[4]== 0)
    {
        int player = playerTurn(4);
        if(player == 1)
        {
            ui->pushButton_5->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_5->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_6_clicked()
{
    if(clickedButton[5]== 0)
    {
        int player = playerTurn(5);
        if(player == 1)
        {
            ui->pushButton_6->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_6->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_7_clicked()
{
    if(clickedButton[6]== 0)
    {
        int player = playerTurn(6);
        if(player == 1)
        {
            ui->pushButton_7->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_7->setText("O");
        }
    }
}

void TICTACTOE::on_pushButton_8_clicked()
{
    if(clickedButton[7]== 0)
    {
        int player = playerTurn(7);
        if(player == 1)
        {
            ui->pushButton_8->setText("X");
        }
              else if (player == 2)
        {
            ui->pushButton_8->setText("O");
        }
    }
}

void TICTACTOE::on_PUSHBUTTON9_clicked()
{
    if(clickedButton[8]== 0)
    {
        int player = playerTurn(8);
        if(player == 1)
        {
            ui->PUSHBUTTON9->setText("X");
        }
              else if (player == 2)
        {
            ui->PUSHBUTTON9->setText("O");
        }
    }
}
int TICTACTOE::playerTurn(int buttonIndex)
{
    counter++;
            int modulus = counter%2;
    if(modulus == 1)
    {
        ui->label->setText("Player 2");
        clickedButton[buttonIndex]=2;
        return 2;
    }
    else
    {
        ui->label->setText("Player 1");
        clickedButton[buttonIndex]=1;
        return 1;
    }
}
