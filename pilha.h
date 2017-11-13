#ifndef LISTDUPLAMENTEENCADEADA_H
#define LISTDUPLAMENTEENCADEADA_H

#include "no.h"



class Pilha
{
    No* cabeca;
    No* rabo;
    int tamanho = 0;
public:
    Pilha() { cabeca = rabo = nullptr; }
    ~Pilha();
    void pilha(int valor);
    int desempilha();
    bool estaVazio() {
        return cabeca == nullptr;
    }


    int getTamanho() const;
    No *getRabo() const;
    No *getCabeca() const;
};

#endif // LISTDUPLAMENTEENCADEADA_H
