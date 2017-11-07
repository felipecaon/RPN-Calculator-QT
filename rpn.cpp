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

    connect(ui->clear, SIGNAL(released()),this,SLOT(OnLimpaLineEdit()));
    connect(ui->row, SIGNAL(released()),this,SLOT(onInverteValores()));
    connect(ui->del, SIGNAL(released()),this,SLOT(onDeletaUltimoPilha()));


}

RPN::~RPN()
{
    delete ui;
}

void RPN::deletaUltimoOperando()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.removeSelectedText();
    cursor.deletePreviousChar();
    cursor.movePosition(QTextCursor::NextBlock);
    cursor.deletePreviousChar();
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
    numeroLineEdit = QString::number(numDoBtn,'g',15);
    ui->lineEdit->setText(numeroLineEdit);
}

void RPN::on_clear_released()
{
    ui->lineEdit->setText("0");
}

void RPN::on_enter_released()
{

    adicionarNumeroAoVisor(numeroLineEdit.toInt());
    pilha->adicionar(numeroLineEdit.toInt());
    numeroLineEdit = QString::fromStdString("0");
    ui->lineEdit->setText(numeroLineEdit);

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

void RPN::OnLimpaLineEdit()
{
   numeroLineEdit = QString::fromStdString("0");
   ui->lineEdit->setText("0");

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

void RPN::onInverteValores()
{
    if(pilha->getTamanho() > 1){

        int valor_1 = getUltimoOperando();
        int valor_2 = getUltimoOperando();

        pilha->adicionar(valor_1);
        adicionarNumeroAoVisor(valor_1);
        pilha->adicionar(valor_2);
        adicionarNumeroAoVisor(valor_2);

    }
}

void RPN::onDeletaUltimoPilha()
{
    if(pilha->getTamanho() > 0){
        pilha->descartaUltimoValor();
        deletaUltimoOperando();
    }
}

void RPN::adicionarNumeroAoVisor(int valor)
{

    ui->textEdit->moveCursor(QTextCursor::Start);
    ui->textEdit->moveCursor(QTextCursor::StartOfLine);
    ui->textEdit->insertPlainText(QString::number(valor,'g',15) + "\r\n");
}

