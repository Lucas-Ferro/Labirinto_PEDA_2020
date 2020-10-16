cmake_minimum_required(VERSION 3.17)
project(PilhaArray)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PilhaArray
        main.cpp
        Pilha.h
        PilhaArray.cpp
        PilhaArray.h
        PilhaEncadeada.cpp
        PilhaEncadeada.h
        labirinto.txt)
