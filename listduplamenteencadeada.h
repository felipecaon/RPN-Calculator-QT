#ifndef LISTDUPLAMENTEENCADEADA_H
#define LISTDUPLAMENTEENCADEADA_H

#include "no.h"



class ListDuplamenteEncadeada
{
    No* cabeca;
    No* rabo;
    No* atual;
public:
    ListDuplamenteEncadeada() { cabeca = rabo = atual = nullptr; }
    ~ListDuplamenteEncadeada();
    int valorAtual();
    void adicionar(int valor);
    void remover();
    void comeco() { atual = cabeca; }
    void final() { atual = rabo; }
    bool proximo();
    bool anterior();
    bool estaVazio() { return cabeca != nullptr; }


};

#endif // LISTDUPLAMENTEENCADEADA_H
