#include "pilha.h"
Pilha::~Pilha()
{
    if(!cabeca) return;
    for(No* tmp = cabeca->getProx(); tmp; tmp = tmp->getProx()) delete tmp->getPrev();
    delete rabo;
}

void Pilha::pilha(int valor)
{
    if(!cabeca)
    {
        cabeca = new No(nullptr, nullptr, valor);
        rabo = cabeca;
    }else if(cabeca == rabo){
        cabeca = new No(rabo, nullptr, valor);
        rabo->setPrev(cabeca);
    }else{
        No* no = new No(cabeca, nullptr, valor);
        cabeca->setPrev(no);
        cabeca = no;
    }

    this->tamanho++;
}

int Pilha::desempilha()
{

    int valorRetorno;

    if(!cabeca) return 0;

    if(cabeca == rabo)
    {
        valorRetorno = cabeca->getNumero();
        delete cabeca;
        cabeca = rabo = nullptr;

    }else{

        valorRetorno = cabeca->getNumero();
        cabeca = cabeca->getProx();
        delete cabeca->getPrev();
    }

    this->tamanho--;
    return valorRetorno;
}

int Pilha::getTamanho() const
{
    return this->tamanho;
}

No *Pilha::getRabo() const
{
    return this->rabo;
}

No *Pilha::getCabeca() const
{
    return this->cabeca;
}


