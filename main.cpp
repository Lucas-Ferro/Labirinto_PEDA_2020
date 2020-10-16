#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "PilhaEncadeada.h"
#include "PilhaArray.h"

//ALUNO: LUCAS FERRO ANTUNES DE OLIVEIRA

using namespace std;

//Cabeçalho
char** AbreLabirinto(const string& arquivo, int* h, int* w);
void Entrada(char** labirinto, int x, int y, int* xE, int* yE);
void ImprimeLabirinto(char** labirinto, int x, int y);
char** DesempilhaEMarcaCertoEErrado(char** lab, Pilha& certo, Pilha& errado);
bool resolveHE(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveHD(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveHC(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveHB(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveAHE(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveAHD(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveAHC(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);
bool resolveAHB(char** labirinto, Pilha& certo, Pilha& errado, int i, int j);

int main(int argc, char *argv[]) {

    //Pilhas
    PilhaEncadeada* certo = new PilhaEncadeada;
    PilhaEncadeada* errado = new PilhaEncadeada;

    //início
    int x = 0;
    int y = 0;

    //abre o txt, salva o labirinto
    char** labirinto = AbreLabirinto("labirinto.txt", &x, &y);

    //acha a entrada do labirinto
    int Ei=0, Ej=0;
    Entrada(labirinto, x, y, &Ei, &Ej);

    int op = -1;
    bool encontrou = false;

    do
    {
        std::cout << "------------------------" << std::endl;
        std::cout << "|      Labirinto       |" << std::endl;
        std::cout << "|                      |" << std::endl;
        std::cout << "|  1 - Iniciar         |" << std::endl;
        std::cout << "|  0 - Sair            |" << std::endl;
        std::cout << "|                      |" << std::endl;
        std::cout << "|  Escolha uma opção: " << std::endl;
        std::cin >> op;

        switch (op) {
            case 0:{
                std::cout << "Saindo..." << std::endl;
                break;
            }
            case 1:{

                int op2 = -1;

                std::cout << "------------------------" << std::endl;
                std::cout << "|        Ordem         |" << std::endl;
                std::cout << "|                      |" << std::endl;
                std::cout << "|  1 - Horário         |" << std::endl;
                std::cout << "|  2 - Anti-horário    |" << std::endl;
                std::cout << "|  0 - Voltar          |" << std::endl;
                std::cout << "|                      |" << std::endl;
                std::cout << "|  Escolha uma opção: " << std::endl;
                std::cin >> op2;

                switch (op2) {
                    case 0:{
                        std::cout << "Voltando..." << std::endl;
                        break;
                    }
                    case 1:{
                        //Sentido horário

                        int op3 = -1;

                        std::cout << "------------------------" << std::endl;
                        std::cout << "|        Começo        |" << std::endl;
                        std::cout << "|                      |" << std::endl;
                        std::cout << "|  1 - Cima            |" << std::endl;
                        std::cout << "|  2 - Baixo           |" << std::endl;
                        std::cout << "|  3 - Direita         |" << std::endl;
                        std::cout << "|  4 - Esquerda        |" << std::endl;
                        std::cout << "|  0 - Voltar          |" << std::endl;
                        std::cout << "|                      |" << std::endl;
                        std::cout << "|  Escolha uma opção: " << std::endl;
                        std::cin >> op3;

                        switch (op3) {
                            case 0:{
                                std::cout << "Voltando..." << std::endl;
                                break;
                            }
                            case 1:{
                                //Cima
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveHC(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "Duração: " << (elapsed.count()/1000) << " ms" << endl;

                                return 0;
                            }
                            case 2:{
                                //Baixo
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveHB(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "Duração: " << (elapsed.count()/1000) << " ms" << endl;

                                return 0;
                            }
                            case 3:{
                                //Direita
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveHD(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "Duração: " << (elapsed.count()/1000) << " ms" << endl;

                                return 0;
                            }
                            case 4:{
                                //Esquerda
                                //Inicia o contador

                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveHE(labirinto, *certo , *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "\nDuração: " << elapsed.count() << " s" << endl;

                                return 0;

                            }
                        }
                        break;
                    }
                    case 2:{
                        //Sentido anti-horário

                        int op3 = -1;

                        std::cout << "------------------------" << std::endl;
                        std::cout << "|        Começo        |" << std::endl;
                        std::cout << "|                      |" << std::endl;
                        std::cout << "|  1 - Cima            |" << std::endl;
                        std::cout << "|  2 - Baixo           |" << std::endl;
                        std::cout << "|  3 - Direita         |" << std::endl;
                        std::cout << "|  4 - Esquerda        |" << std::endl;
                        std::cout << "|  0 - Voltar          |" << std::endl;
                        std::cout << "|                      |" << std::endl;
                        std::cout << "|  Escolha uma opção: " << std::endl;
                        std::cin >> op3;

                        switch (op3) {
                            case 0:{
                                std::cout << "Voltando..." << std::endl;
                                break;
                            }
                            case 1:{
                                //Cima
                                //Inicia o contador

                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveAHC(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }
                                //Mostra o tempo em ms
                                std::cout << "\nDuração: " << (elapsed.count()/1000) << " ms" << endl;

                                return 0;
                            }
                            case 2:{
                                //Baixo
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveAHB(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }
                                //Mostra o tempo em ms
                                std::cout << "\nDuração: " << (elapsed.count()/1000) << " ms" << endl;

                                return 0;
                            }
                            case 3:{
                                //Direita
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveAHD(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "\nDuração: " << (elapsed.count()/1000) << " s" << endl;

                                return 0;
                            }
                            case 4:{
                                //Esquerda
                                //Inicia o contador
                                auto start = std::chrono::high_resolution_clock::now();

                                bool result = resolveAHE(labirinto, *certo, *errado, Ei, Ej);

                                std::cout << std::endl << std::endl<< "Saída encontrada" << endl << endl;

                                //Termina o contador
                                auto finish = std::chrono::high_resolution_clock::now();

                                //Calcula o tempo de resolução do labirinto
                                std::chrono::duration<double> elapsed = finish - start;

                                if(!result) {
                                    DesempilhaEMarcaCertoEErrado(labirinto, *certo, *errado);
                                    ImprimeLabirinto(labirinto, x, y);
                                }

                                //Mostra o tempo em ms
                                std::cout << "\nDuração: " << (elapsed.count()/1000) << " s" << endl;

                                return 0;
                            }
                        }
                    }
                }
            }
        }
    } while ((op != 0) || (encontrou));
    return 0;
}

bool resolveHE(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i, j - 1};
    int coord2[2] = {i - 1, j};
    int coord3[2] = {i, j + 1};
    int coord4[2] = {i + 1, j};

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveHE(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveHE(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveHE(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveHE(labirinto, certo, errado, (i + 1), j);
    }


    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }

}

bool resolveHD(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i, j + 1};
    int coord2[2] = {i + 1, j};
    int coord3[2] = {i, j - 1};
    int coord4[2] = {i - 1, j};

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveHD(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveHD(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveHD(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveHD(labirinto, certo, errado, (i - 1), j);
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

bool resolveHC(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i - 1, j};
    int coord2[2] = {i, j + 1};
    int coord3[2] = {i + 1, j};
    int coord4[2] = {i, j - 1};

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveHC(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveHC(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveHC(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveHC(labirinto, certo, errado, i, (j - 1));
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

bool resolveHB(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i + 1, j};
    int coord2[2] = {i, j - 1};
    int coord3[2] = {i - 1, j};
    int coord4[2] = {i, j + 1};


    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveHB(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveHB(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveHB(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveHB(labirinto, certo, errado, i, (j + 1));
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

bool resolveAHE(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i, j - 1};
    int coord2[2] = {i + 1, j};
    int coord3[2] = {i, j + 1};
    int coord4[2] = {i - 1, j};

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveAHE(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveAHE(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveAHE(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveAHE(labirinto, certo, errado, (i - 1), j);
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

bool resolveAHD(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i, j + 1};
    int coord2[2] = {i - 1, j};
    int coord3[2] = {i, j - 1};
    int coord4[2] = {i + 1, j};

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveAHD(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveAHD(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveAHD(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveAHD(labirinto, certo, errado, (i + 1), j);
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }

}

bool resolveAHC(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i - 1, j};
    int coord2[2] = {i, j - 1};
    int coord3[2] = {i + 1, j};
    int coord4[2] = {i, j + 1};

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveAHC(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveAHC(labirinto, certo, errado, i, (j - 1));
    }

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveAHC(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveAHC(labirinto, certo, errado, i, (j + 1));
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

bool resolveAHB(char** labirinto, Pilha& certo, Pilha& errado, int i, int j){
    bool termina = true;

    // i = altura
    // j = largura
    // i + 1 = desce
    // i - 1 = sobe
    // j - 1 = esquerda
    // j + 1 = direita

    int coord1[2] = {i + 1, j};
    int coord2[2] = {i, j + 1};
    int coord3[2] = {i - 1, j};
    int coord4[2] = {i, j - 1};

    if (labirinto[i + 1][j] == 'S')
        termina = false;

    if (labirinto[i][j + 1] == 'S')
        termina = false;

    if (labirinto[i - 1][j] == 'S')
        termina = false;

    if (labirinto[i][j - 1] == 'S')
        termina = false;

    if (labirinto[i + 1][j] == ' ' && termina && !certo.igualUltimo(coord1) ){
        certo.empilha(coord1);
        termina = resolveAHB(labirinto, certo, errado, (i + 1), j);
    }

    if (labirinto[i][j + 1] == ' ' && termina && !certo.igualUltimo(coord2) ){
        certo.empilha(coord2);
        termina = resolveAHB(labirinto, certo, errado, i, (j + 1));
    }

    if (labirinto[i - 1][j] == ' ' && termina && !certo.igualUltimo(coord3) ){
        certo.empilha(coord3);
        termina = resolveAHB(labirinto, certo, errado, (i - 1), j);
    }

    if (labirinto[i][j - 1] == ' ' && termina && !certo.igualUltimo(coord4) ){
        certo.empilha(coord4);
        termina = resolveAHB(labirinto, certo, errado, i, (j - 1));
    }

    if(termina){
        if(!certo.isVazia()) {
            int coords[2] = {i, j};
            errado.empilha(coords);
            certo.desempilha();
        }
        return true;
    }
    else{
        return false;
    }
}

void ImprimeLabirinto(char** labirinto, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++)
            cout << labirinto[i][j];
        cout << endl;
    }
}

void Entrada(char** labirinto, int x, int y, int* Ei, int* Ej){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (labirinto[i][j] == 'E'){
                *Ei = i;
                *Ej = j;
            }
        }
    }
}

char** AbreLabirinto(const string& arquivo, int* h, int* w){
    string line;
    int i = 0, j = 0;
    char** labirinto;
    ifstream myfile (arquivo);

    //Pega o tamanho do labirinto
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            j = line.length();
            for(char letter : line)
                cout << letter;
            cout<<"\n";
            i++;
        }
        myfile.close();
    }
    else cout << "Não foi possível abrir o arquivo";

    *h = i;
    *w = j;
    labirinto = new char*[i];
    int x = 0;

    //Cria o labirinto
    ifstream myfile2 (arquivo);
    if (myfile2.is_open())
    {
        while ( getline (myfile2,line) ){
            labirinto[x] = new char[j];
            for(int y = 0; y<line.length(); y++)
                labirinto[x][y] = line[y];
            x++;
        }
        myfile2.close();
    }
    else cout << "Não foi possível abrir o arquivo";

    return labirinto;
}

char** DesempilhaEMarcaCertoEErrado(char** lab, Pilha& certo, Pilha& errado){
    if(!certo.isVazia()) {
        int *aux = certo.desempilha();
        while (!certo.isVazia()) {
            lab[aux[0]][aux[1]] = '.';
            aux = certo.desempilha();
        }
    }

    if(!errado.isVazia()) {
        int *aux2 = errado.desempilha();
        while (!errado.isVazia()) {
            lab[aux2[0]][aux2[1]] = '-';
            aux2 = errado.desempilha();
        }
    }
    return lab;
}
