cmake_minimum_required(VERSION 4.2)
project(CLASES_OBJETOS_y_SOBRECARGAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_OBJETOS_y_SOBRECARGAS main.cpp
        Biblioteca/Infraccion.cpp
        Biblioteca/Infraccion.h
        Biblioteca/Empresa.cpp
        Biblioteca/Empresa.h
        Biblioteca/Multa.cpp
        Biblioteca/Multa.h
        Biblioteca/MinisterioDeTransporte.cpp
        Biblioteca/MinisterioDeTransporte.h
)
