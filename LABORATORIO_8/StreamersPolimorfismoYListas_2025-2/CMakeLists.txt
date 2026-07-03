cmake_minimum_required(VERSION 4.2)
project(StreamersPolimorfismoYListas_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(StreamersPolimorfismoYListas_2025_2 main.cpp
        Biblioteca/Metrica.cpp
        Biblioteca/Metrica.h
        Biblioteca/MetricaBasica.cpp
        Biblioteca/MetricaBasica.h
        Biblioteca/MetricaEngagement.cpp
        Biblioteca/MetricaEngagement.h
        Biblioteca/MetricaCalidad.cpp
        Biblioteca/MetricaCalidad.h
        Biblioteca/Nodo.cpp
        Biblioteca/Nodo.h
        Biblioteca/Lista.cpp
        Biblioteca/Lista.h)
