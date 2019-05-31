cmake_minimum_required(VERSION 3.14)
project(Bomberman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bomberman main.cpp Board.cpp Board.h Bomber.cpp Bomber.h)