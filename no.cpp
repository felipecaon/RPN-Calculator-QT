#include "no.h"

No::No()
{

}

No::Node(No *prox, No *prev, int numero)
{
    this->prev = prev;
    this->prox = prox;
    this->numero = numero
}

int No::getNumero() const
{
    return numero;
}

void No::setNumero(int value)
{
    numero = value;
}
