cmake_minimum_required(VERSION 4.2)
project(HERENCIA_LAB7_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(HERENCIA_LAB7_2024_2 main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Producto.h
        Biblioteca/Bebida.cpp
        Biblioteca/Bebida.h
        Biblioteca/Entrada.cpp
        Biblioteca/Entrada.h
        Biblioteca/PlatoFondo.cpp
        Biblioteca/PlatoFondo.h
        Biblioteca/Comanda.cpp
        Biblioteca/Comanda.h
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
