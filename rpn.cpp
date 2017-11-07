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

void RPN::deletaUltimoOperando()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.removeSelectedText();
    cursor.movePosition(QTextCursor::Start);
    ui->textEdit->setTextCursor(cursor);
}

int RPN::getUltimoOperando()
{
    deletaUltimoOperando();
    return pilha->pegarValorAtual();
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

    adicionarNumeroAoVisor(pilhaDeValores.toInt());
    pilha->adicionar(pilhaDeValores.toInt());
    pilhaDeValores = QString::fromStdString("0");
    ui->lineEdit->setText(pilhaDeValores);

}

void RPN::onSomar()
{

    if(pilha->getTamanho() > 1){

        int operando_1 = getUltimoOperando();
        int operando_2 = getUltimoOperando();
        int resultado = operando_1 + operando_2;
        pilha->adicionar(resultado);
        adicionarNumeroAoVisor(resultado);


    }

}

void RPN::onDivisao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = getUltimoOperando();
        int operando_2 = getUltimoOperando();
        int resultado = operando_1 / operando_2;
        pilha->adicionar(resultado);
        adicionarNumeroAoVisor(resultado);

    }
}

void RPN::onMutiplicacao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = getUltimoOperando();
        int operando_2 = getUltimoOperando();
        int resultado = operando_1 * operando_2;
        pilha->adicionar(resultado);
        adicionarNumeroAoVisor(resultado);

    }
}

void RPN::onSubtracao()
{
    if(pilha->getTamanho() > 1){

        int operando_1 = getUltimoOperando();
        int operando_2 = getUltimoOperando();
        int resultado = operando_1 - operando_2;
        pilha->adicionar(resultado);
        adicionarNumeroAoVisor(resultado);

    }
}

void RPN::adicionarNumeroAoVisor(int valor)
{

    ui->textEdit->moveCursor(QTextCursor::Start);
    ui->textEdit->moveCursor(QTextCursor::StartOfLine);
    ui->textEdit->insertPlainText(QString::number(valor,'g',15) + "\r\n");
}
