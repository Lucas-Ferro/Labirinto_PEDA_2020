//
// Created by Vinicius Godoy de Mendonça on 07/08/20.
//

#include "Pilha.h"

#ifndef ED05_PILHAARRAY_H
#define ED05_PILHAARRAY_H

class PilhaArray : public Pilha {
private:
    int *dados;
    int capacidade;
    int topo;
    double fator;

    void redimensionar(int novaCapacidade);

public:
    explicit PilhaArray(int capacidade, double fator=0.5);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    PilhaArray(const PilhaArray& other) = delete;
    PilhaArray& operator = (const PilhaArray& other) = delete;

    virtual void limpar() override;
    virtual void empilha(int dado) override;
    virtual int desempilha() override;
    virtual bool isVazia() const override;
    virtual bool isCheia() const override;

    void ajustarAoTamanho();

    virtual ~PilhaArray();
};


#endif //ED05_PILHAARRAY_H
