#include "PilhaEncadeada.h"

//---------------
//Classe do No
//---------------
No::No(No* anterior, const int* valor) {
    this->anterior = anterior;
    this->valor = new int[2];
    this->valor[0] = valor[0];
    this->valor[1] = valor[1];
}

No* No::getAnterior() const {
    return anterior;
}

int* No::getValor() const {
    return valor;
}

//------------------------
//Classe da PilhaEncadeada
//------------------------

PilhaEncadeada::PilhaEncadeada() {
    topo = nullptr;
}

void PilhaEncadeada::limpar() {
    while (!isVazia()) {
        desempilha();
    }
}

void PilhaEncadeada::empilha(int* dado) {
    No* no = new No(topo, dado);
    topo = no;
}

int* PilhaEncadeada::desempilha() {
    int* dado = topo->getValor();
    No* anterior = topo->getAnterior();
    delete topo;
    topo = anterior;
    return dado;
}

bool PilhaEncadeada::isVazia() const {
    return topo == nullptr;
}

bool PilhaEncadeada::isCheia() const {
    return false;
}

bool PilhaEncadeada::igualUltimo(int* dado) const {
    if(isVazia() || topo->getAnterior() == nullptr)
        return false;

    else {
        if ((dado[0] == topo->getAnterior()->getValor()[0]) && (dado[1] == topo->getAnterior()->getValor()[1]))
            return true;
        else
            return false;
    }
}