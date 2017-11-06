#include "rpn.h"
#include "ui_rpn.h"
#include "QDebug"
#include <QKeyEvent>

RPN::RPN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RPN)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(botaoPressionado()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(botaoPressionado()));


}

RPN::~RPN()
{
    delete ui;
}

void RPN::botaoPressionado()
{
    QPushButton * botao = (QPushButton*)sender();
    //QString valorString;
    double valor;

    valor = (ui->lineEdit->text() + botao->text()).toDouble();

    valorString = QString::number(valor,'g',15);

    ui->lineEdit->setText(valorString);
}

void RPN::on_clear_released()
{
    ui->lineEdit->setText("0");
}

void RPN::on_enter_released()
{

    ui->textEdit->append(valorString);

    ui->lineEdit->setText("0");

}
