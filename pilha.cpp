#include "pilha.h"

ListDuplamenteEncadeada *Pilha::getLista() const
{
    return lista;
}

Pilha::Pilha()
{

}

Pilha::~Pilha()
{
    delete lista;
}

void Pilha::adicionar(int valor)
{
    lista->adicionar(valor);
}

int Pilha::pegarValorAtual()
{
    int valor = lista->valorAtual();

    if(!lista->estaVazio()){
        lista->remover();
    }
    return valor;
}

