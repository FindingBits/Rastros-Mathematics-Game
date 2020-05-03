cmake_minimum_required(VERSION 3.15)
project(jogo C)

set(CMAKE_C_STANDARD 99)

add_executable(jogo main.c interface.c interface.h logica.c logica.h dados.c dados.h)
