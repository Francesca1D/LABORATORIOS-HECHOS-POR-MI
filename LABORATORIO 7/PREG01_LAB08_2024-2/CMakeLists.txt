cmake_minimum_required(VERSION 4.2)
project(PREG01_LAB08_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG01_LAB08_2024_2 main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Producto.h
        Biblioteca/Bebida.cpp
        Biblioteca/Bebida.h
        Biblioteca/Entrada.cpp
        Biblioteca/Entrada.h
        Biblioteca/DetalleComanda.cpp
        Biblioteca/DetalleComanda.h
        Biblioteca/PlatoFondo.cpp
        Biblioteca/PlatoFondo.h
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
