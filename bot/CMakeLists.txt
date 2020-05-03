cmake_minimum_required(VERSION 3.16)
project(bot C)

set(CMAKE_C_STANDARD 99)

add_executable(bot main.c play.c play.h)