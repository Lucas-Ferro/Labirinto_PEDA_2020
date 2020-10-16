//
// Created by Vinicius Godoy de Mendonça on 07/08/20.
//

#include "Pilha.h"

#ifndef ED05_PILHAESTATICA_H
#define ED05_PILHAESTATICA_H

class PilhaEstatica : public Pilha {
private:
    int *dados;
    int capacidade;
    int topo;

public:
    explicit PilhaEstatica(int capacidade);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    PilhaEstatica(const PilhaEstatica& other) = delete;
    PilhaEstatica& operator = (const PilhaEstatica& other) = delete;

    virtual void limpar() override;
    virtual void empilha(int dado) override;
    virtual int desempilha() override;
    virtual bool isVazia() const override;
    virtual bool isCheia() const override;

    virtual ~PilhaEstatica();
};


#endif //ED05_PILHAESTATICA_H
