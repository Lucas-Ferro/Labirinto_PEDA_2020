#include "PilhaEstatica.h"


PilhaEstatica::PilhaEstatica(int capacidade) {
    this->capacidade = capacidade;
    this->dados = new int[capacidade];
    this->topo = -1;
}

void PilhaEstatica::limpar() {
    topo = -1;
}

void PilhaEstatica::empilha(int dado) {
    topo = topo + 1;
    dados[topo] = dado;
}

int PilhaEstatica::desempilha()
{
    int dado = dados[topo];
    topo = topo -1;
    return dado;
}
bool PilhaEstatica::isVazia() const
{
    return topo == -1;
}

bool PilhaEstatica::isCheia() const
{
    return topo == capacidade-1;
}


PilhaEstatica::~PilhaEstatica()
{
    delete [] dados;
}