//
// Created by Vinicius Godoy de Mendonça on 24/08/20.
//

#include "PilhaEncadeada.h"

//---------------
//Classe do No
//---------------
No::No(No* anterior, int valor) {
   this->anterior = anterior;
   this->valor = valor;
}

No* No::getAnterior() const {
    return anterior;
}

int No::getValor() const {
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

void PilhaEncadeada::empilha(int dado) {
    No* no = new No(topo, dado);
    topo = no;
}

int PilhaEncadeada::desempilha() {
    int dado = topo->getValor();
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
