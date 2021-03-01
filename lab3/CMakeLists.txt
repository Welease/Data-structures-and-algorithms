cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp DinamicQueue.cpp DinamicQueue.h)

add_executable(lab3random main3lab.cpp DinamicQueue.cpp DinamicQueue.h)