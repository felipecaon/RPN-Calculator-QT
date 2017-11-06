#include "no.h"

No::No(No *prox, No *prev, int numero)
{
    this->prev = prev;
    this->prox = prox;
    this->numero = numero;
}

No *No::getProx() const
{
    return prox;
}

void No::setProx(No *value)
{
    prox = value;
}

No *No::getPrev() const
{
    return prev;
}

void No::setPrev(No *value)
{
    prev = value;
}

int No::getNumero() const
{
    return numero;
}

void No::setNumero(int value)
{
    numero = value;
}
