cmake_minimum_required(VERSION 4.2)
project(2025_2_Laboratorio09_STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_2_Laboratorio09_STL main.cpp
        Biblioteca/Etiqueta.cpp
        Biblioteca/Etiqueta.h
        Biblioteca/Categoria.cpp
        Biblioteca/Categoria.h
        Biblioteca/Comentario.cpp
        Biblioteca/Comentario.h
        Biblioteca/Streamer.cpp
        Biblioteca/Streamer.h
        Biblioteca/SistemaDeGestion.cpp
        Biblioteca/SistemaDeGestion.h)
