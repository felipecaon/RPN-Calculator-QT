#include "pilha.h"

ListDuplamenteEncadeada *Pilha::getLista() const
{
    return lista;
}

int Pilha::getTamanho() const
{
    return tamanho;
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
    tamanho++;
}

int Pilha::pegarValorAtual()
{
    int valor = lista->valorAtual();

    if(!lista->estaVazio()){
        lista->removerAtual();
        tamanho--;
    }
    return valor;
}

