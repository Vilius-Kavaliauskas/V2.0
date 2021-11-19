cmake_minimum_required(VERSION 3.20)
project(V1_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(V1.0)

add_executable(V1_0
        V1.0/Balas.cpp
        V1.0/Balas.h
        V1.0/Balas_list.cpp
        V1.0/Balas_list.h
        V1.0/Generavimas.cpp
        V1.0/Generavimas.h
        V1.0/Input_list.cpp
        V1.0/Input_list.h
        V1.0/Kopijavimas.cpp
        V1.0/Kopijavimas.h
        V1.0/Laikas.h
        V1.0/Output_list.cpp
        V1.0/Output_list.h
        V1.0/Studentas.h
        V1.0/Trynimas.cpp
        V1.0/Trynimas.h
        V1.0/V1.0.cpp)
