#include "listduplamenteencadeada.h"

ListDuplamenteEncadeada::~ListDuplamenteEncadeada()
{
    if(!cabeca) return;
    for(No* tmp = cabeca->getProx(); tmp; tmp = tmp->getProx()) delete tmp->getPrev();
    delete rabo;
}

int ListDuplamenteEncadeada::valorAtual()
{
    return atual->getNumero();
}

void ListDuplamenteEncadeada::adicionar(int valor)
{
    if(!cabeca)
    {
        cabeca = new No(nullptr, nullptr, valor);
        rabo = cabeca;
        atual = cabeca;
        return;
    }

    rabo = new No(nullptr, rabo, valor);
    rabo->getPrev()->setProx(rabo);
    atual = rabo;
}

void ListDuplamenteEncadeada::removerAtual()
{
    if(!cabeca) return;

    if(cabeca == rabo)
    {
        delete cabeca;
        cabeca = rabo = atual = nullptr;
        return;
    }

    if(atual == cabeca)
    {
        cabeca = cabeca->getProx();
        delete cabeca->getPrev();
        atual = cabeca;
        return;
    }

    if(atual == rabo)
    {
        rabo = rabo->getPrev();
        delete rabo->getProx();
        atual = rabo;
        return;
    }


    atual->getPrev()->setProx(atual->getProx());
    atual->getProx()->setPrev(atual->getPrev());
    No* temp = atual;
    atual = atual->getPrev();
    delete temp;
}

bool ListDuplamenteEncadeada::proximo()
{
    if(atual && atual->getProx())
    {
       atual = atual->getProx();
       return true;
    }
    return false;
}

bool ListDuplamenteEncadeada::anterior()
{
    if(atual && atual->getPrev())
    {
       atual = atual->getPrev();
       return true;
    }
    return false;
}
