#include <iostream>

#include "PilhaEncadeada.h"

using namespace std;

void desempilhaTudo(Pilha& pilha) {
    while (!pilha.isVazia()) {
        cout << pilha.desempilha() << endl;
    }
}

int main(int argc, char *argv[]) {
    PilhaEncadeada pilha;
    pilha.empilha(10);
    pilha.empilha(-20);
    pilha.empilha(30);
    pilha.empilha(-40);
    desempilhaTudo(pilha);
}
