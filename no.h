#ifndef NO_H
#define NO_H


class No
{
protected:
    No* prox;
    No* prev;
    int numero;
public:                
    No(No* next, No* prev, int numero);
    int getNumero() const;
    void setNumero(int value);
    No *getProx() const;
    void setProx(No *value);
    No *getPrev() const;
    void setPrev(No *value);
};

#endif // NO_H
