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



    connect(ui->soma, SIGNAL(released()),this,SLOT(onSomar()));
    connect(ui->divisao, SIGNAL(released()),this,SLOT(onDivisao()));
    connect(ui->multiplicacao, SIGNAL(released()),this,SLOT(onMutiplicacao()));
    connect(ui->subtracao, SIGNAL(released()),this,SLOT(onSubtracao()));


}

RPN::~RPN()
{
    delete ui;
}

void RPN::botaoPressionado()
{
    QPushButton * botao = (QPushButton*)sender();
    double numDoBtn = (ui->lineEdit->text() + botao->text()).toDouble();
    pilhaDeValores = QString::number(numDoBtn,'g',15);
    ui->lineEdit->setText(pilhaDeValores);
}

void RPN::on_clear_released()
{
    ui->lineEdit->setText("0");
}

void RPN::on_enter_released()
{

    ui->textEdit->setText(pilhaDeValores);
    ui->lineEdit->setText("0");
    pilha->adicionar(pilhaDeValores.toInt());

}

void RPN::onSomar()
{

    if(pilha->getTamanho() > 1){

        int operando_1 = pilha->pegarValorAtual();
        int operando_2 = pilha->pegarValorAtual();
        int resultado = operando_1 + operando_2;
        pilha->adicionar(resultado);
        ui->textEdit->setText(QString::number(resultado,'g',15));


    }

}

void RPN::onDivisao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = pilha->pegarValorAtual();
        int operando_2 = pilha->pegarValorAtual();
        int resultado = operando_1 / operando_2;
        pilha->adicionar(resultado);
        ui->textEdit->setText(QString::number(resultado,'g',15));

    }
}

void RPN::onMutiplicacao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = pilha->pegarValorAtual();
        int operando_2 = pilha->pegarValorAtual();
        int resultado = operando_1 * operando_2;
        pilha->adicionar(resultado);
        ui->textEdit->setText(QString::number(resultado,'g',15));

    }
}

void RPN::onSubtracao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = pilha->pegarValorAtual();
        int operando_2 = pilha->pegarValorAtual();
        int resultado = operando_1 - operando_2;
        pilha->adicionar(resultado);
        ui->textEdit->setText(QString::number(resultado,'g',15));

    }
}
