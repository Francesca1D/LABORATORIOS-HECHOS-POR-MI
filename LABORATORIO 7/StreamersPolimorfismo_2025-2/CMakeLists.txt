cmake_minimum_required(VERSION 4.2)
project(StreamersPolimorfismo_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(StreamersPolimorfismo_2025_2 main.cpp
        Biblioteca/Metrica.cpp
        Biblioteca/Metrica.h
        Biblioteca/MetricaEngagement.cpp
        Biblioteca/MetricaEngagement.h
        Biblioteca/MetricaBasica.cpp
        Biblioteca/MetricaBasica.h
        Biblioteca/MetricaCalidad.cpp
        Biblioteca/MetricaCalidad.h
        Biblioteca/AdministrarMetricas.cpp
        Biblioteca/AdministrarMetricas.h
        Biblioteca/GestorStreamer.cpp
        Biblioteca/GestorStreamer.h)
