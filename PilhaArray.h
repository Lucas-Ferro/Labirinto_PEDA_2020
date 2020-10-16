//
// Created by Vinicius Godoy de Mendonça on 07/08/20.
//

#include "Pilha.h"

#ifndef ED05_PILHAARRAY_H
#define ED05_PILHAARRAY_H

#include "Pilha.h"

class PilhaArray : public Pilha {
private:
    int **dados;
    int capacidade;
    int topo;
    double fator;

    void redimensionar(int novaCapacidade);

public:
    explicit PilhaArray(int capacidade, double fator=0.5);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    PilhaArray(const PilhaArray& other) = delete;
    PilhaArray& operator = (const PilhaArray& other) = delete;

    void limpar() override;
    void empilha(int* dado) override;
    int* desempilha() override;
    bool isVazia() const override;
    bool isCheia() const override;
    bool igualUltimo(int* dado) const override;

    void ajustarAoTamanho();

    virtual ~PilhaArray();
};

#endif //ED05_PILHAARRAY_H
