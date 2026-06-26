cmake_minimum_required(VERSION 4.2)
project(2025_1_Lab09_STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1_Lab09_STL main.cpp
        Biblioteca/Infraccion.cpp
        Biblioteca/Infraccion.h
        Biblioteca/Vehiculo.cpp
        Biblioteca/Vehiculo.h
        Biblioteca/Multa.cpp
        Biblioteca/Multa.h
        Biblioteca/Empresa.cpp
        Biblioteca/Empresa.h
        Biblioteca/MinisterioDeTransporte.cpp
        Biblioteca/MinisterioDeTransporte.h)
