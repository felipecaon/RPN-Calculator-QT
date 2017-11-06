#ifndef PILHA_H
#define PILHA_H

#include "listduplamenteencadeada.h"



class Pilha
{
    ListDuplamenteEncadeada* lista = new ListDuplamenteEncadeada();

public:
    Pilha();
    ~Pilha();
    void adicionar(int valor);
    int pegarValorAtual();
    ListDuplamenteEncadeada *getLista() const;
};

#endif // PILHA_H
