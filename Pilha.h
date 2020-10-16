#ifndef ED05_PILHA_H
#define ED05_PILHA_H


class Pilha {
public:
    virtual void limpar() = 0;
    virtual void empilha(int* dado) = 0;
    virtual int* desempilha() = 0;
    virtual bool isVazia() const = 0;
    virtual bool isCheia() const = 0;
    virtual bool igualUltimo(int* dado) const = 0;
    virtual ~Pilha() {}

};

#endif //ED05_PILHA_H
