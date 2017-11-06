#ifndef NO_H
#define NO_H


class No
{
protected:
    No* prox;
    No* prev;
    int numero;
public:                
    Node(No* next, No* prev, int numero);
    int getNumero() const;
    void setNumero(int value);
};

#endif // NO_H
