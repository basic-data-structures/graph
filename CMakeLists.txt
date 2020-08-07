cmake_minimum_required(VERSION 3.16)
project(graphTemplates)

set(CMAKE_CXX_STANDARD 14)

add_executable(graphTemplates main.cpp
        headers/List.h
        headers/Node.h
        headers/Graph.h
        headers/Matrix.h
        headers/Queue.h
        )