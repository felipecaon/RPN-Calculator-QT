#ifndef PILHA_H
#define PILHA_H

#include "listduplamenteencadeada.h"



class Pilha
{
    ListDuplamenteEncadeada* lista = new ListDuplamenteEncadeada();
    int tamanho = 0;

public:
    Pilha();
    ~Pilha();
    void adicionar(int valor);
    int pegarValorAtual();
    void descartaUltimoValor();
    ListDuplamenteEncadeada *getLista() const;
    int getTamanho() const;
};

#endif // PILHA_H
