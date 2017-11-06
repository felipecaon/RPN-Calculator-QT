#include "listduplamenteencadeada.h"

ListDuplamenteEncadeada::ListDuplamenteEncadeada()
{

}

ListDuplamenteEncadeada::~ListDuplamenteEncadeada()
{
    if(!cabeca) return;
    for(No* tmp = cabeca->prox; tmp; tmp = tmp->prox) delete tmp->prev;
    delete rabo;
}

int ListDuplamenteEncadeada::valorAtual()
{
    if(m_current) return *atual->numero;
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
    rabo->prev->prox = rabo;
    atual = rabo;
}

void ListDuplamenteEncadeada::remover()
{
    if(!cabeca) return;

    No* noAtual = atual;

    if(cabeca == rabo)
    {
        cabeca = reabo = atual = nullptr;
        return;
    }

    if(noAtual == cabeca)
    {
        cabeca = cabeca->prox;
        delete cabeca->prev;
        atual = cabeca;
        return;
    }

    if(cabeca == rabo)
    {
        rabo = rabo->prev;
        delete rabo->prox;
        atual = rabo;
        return;
    }
    atual = noAtual->prox;
    noAtual->prev->prox = noAtual->proximo;
    delete notAtual;
}

bool ListDuplamenteEncadeada::proximo()
{
    if(atual && atual->prox)
    {
       atual = atual->prox;
       return true;
    }
    return false;
}

bool ListDuplamenteEncadeada::anterior()
{
    if(atual && atual->prox)
    {
       atual = atual->prev;
       return true;
    }
    return false;
}
