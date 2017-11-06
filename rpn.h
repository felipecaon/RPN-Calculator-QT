#ifndef RPN_H
#define RPN_H

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
    QString valorString;

private:
    Ui::RPN *ui;

private slots:
    void botaoPressionado();
    void on_clear_released();
    void on_enter_released();
};

#endif // RPN_H
