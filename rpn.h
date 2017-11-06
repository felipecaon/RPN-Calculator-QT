#ifndef RPN_H
#define RPN_H

#include "pilha.h"

#include <QWidget>

namespace Ui {
class RPN;
}

class RPN : public QWidget
{
    Q_OBJECT

public:
    explicit RPN(QWidget *parent = 0);
    ~RPN();
private:
    Ui::RPN *ui;
    Pilha* pilha = new Pilha();
    QString pilhaDeValores;

private slots:
    void botaoPressionado();
    void on_clear_released();
    void on_enter_released();
    void onSomar();
    void onDivisao();
    void onMutiplicacao();
    void onSubtracao();
};

#endif // RPN_H
