#include "PilhaArray.h"
#include <string.h>

#include "PilhaArray.h"
#include <cstring>
#include <iostream>
using namespace std;

PilhaArray::PilhaArray(int capacidade, double fator) {
    this->capacidade = capacidade;
    this->dados = new int*[capacidade];
    for(int i=0; i<capacidade; i++)
        dados[i] = new int[2];
    this->topo = -1;
    this->fator = fator;
}

void PilhaArray::limpar() {
    topo = -1;
}

void PilhaArray::empilha(int* dado) {
    if (topo == capacidade-1) {
        int novaCapacidade = capacidade * (1.0+fator);
        if (novaCapacidade <= capacidade) novaCapacidade = capacidade + 1;
        redimensionar(novaCapacidade);
    }
    topo = topo + 1;
    dados[topo][0] = dado[0];
    dados[topo][1] = dado[1];
}

int* PilhaArray::desempilha(){
    int* dado = dados[topo];
    topo = topo -1;
    return dado;
}

bool PilhaArray::isVazia() const{
    return topo == -1;
}

bool PilhaArray::isCheia() const{
    return false;
}

PilhaArray::~PilhaArray(){
    delete [] dados;
}

void PilhaArray::ajustarAoTamanho() {
    if (capacidade == topo+1) return;
    redimensionar(topo+1);
}

void PilhaArray::redimensionar(int novaCapacidade) {
    int** novo = new int*[novaCapacidade];
    for(int i=0; i<novaCapacidade; i++)
        novo[i] = new int[2];

    memcpy(novo, dados, capacidade*sizeof(int[2]));
    delete [] dados;

    dados = novo;
    capacidade = novaCapacidade;
}

bool PilhaArray::igualUltimo(int* dado) const {
    if(topo == 0 || topo == -1)
        return false;
    else{
        if ((dado[0] == dados[topo - 1][0]) && (dado[1] == dados[topo - 1][1]))
            return true;
        else
            return false;
    }
}