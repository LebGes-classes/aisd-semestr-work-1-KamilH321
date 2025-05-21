cmake_minimum_required(VERSION 3.31)
project(AVLTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(AVLTree main.cpp
        avl_tree.cpp
        avl_tree.h)
