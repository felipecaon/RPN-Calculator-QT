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
    QString numeroLineEdit;
    void deletaUltimoOperando();
    int getUltimoOperando();
    void adicionarNumeroAoVisor(int valor);

private slots:
    void botaoPressionado();
    void on_clear_released();
    void on_enter_released();
    void onSomar();
    void OnLimpaLineEdit();
    void onDivisao();
    void onMutiplicacao();
    void onSubtracao();
    void onInverteValores();
    void onDeletaUltimoPilha();
    void onDown();
    void onUp();




};

#endif // RPN_H
