cmake_minimum_required(VERSION 4.2)
project(EmergenciasPROG2_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(EmergenciasPROG2_2026_1 main.cpp
        Biblioteca/Atencion.cpp
        Biblioteca/Atencion.h
        Biblioteca/Emergencia.cpp
        Biblioteca/Emergencia.h
        Biblioteca/Urgencia.cpp
        Biblioteca/Urgencia.h
        Biblioteca/NoUrgencia.cpp
        Biblioteca/NoUrgencia.h
        Biblioteca/GestorAtenciones.cpp
        Biblioteca/GestorAtenciones.h
        Biblioteca/Utils.cpp
        Biblioteca/Utils.h
)
