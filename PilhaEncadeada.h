//
// Created by Vinicius Godoy de Mendonça on 24/08/20.
//

#ifndef ED03_PILHAENCADEADA_H
#define ED03_PILHAENCADEADA_H

#include "Pilha.h"

class No {
private:
    No* anterior;
    int *valor;
public:
    No(No* anterior, const int* valor);
    No* getAnterior() const;
    int* getValor() const;
};

class PilhaEncadeada : public Pilha {
private:
    No* topo;
public:
    PilhaEncadeada();
    void limpar() override;
    void empilha(int* dado) override;
    int* desempilha() override;
    bool isVazia() const override;
    bool isCheia() const override;
    bool igualUltimo(int* dado) const override;
};

#endif //ED03_PILHAENCADEADA_H