//
// Created by Vinicius Godoy de Mendonça on 24/08/20.
//

#ifndef ED03_PILHAENCADEADA_H
#define ED03_PILHAENCADEADA_H

#include "Pilha.h"

class No {
    private:
        No* anterior;
        int valor;
    public:
        No(No* anterior, int valor);
        No* getAnterior() const;
        int getValor() const;
};

class PilhaEncadeada : public Pilha {
    private:
        No* topo;
    public:
        PilhaEncadeada();
        virtual void limpar();
        virtual void empilha(int dado);
        virtual int desempilha();
        virtual bool isVazia() const;
        virtual bool isCheia() const;
};


#endif //ED03_PILHAENCADEADA_H
