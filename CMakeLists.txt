cmake_minimum_required(VERSION 3.22)
project(DianaOOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(DianaOOP main.cpp DAL/abstraction/conscript.cpp DAL/abstraction/conscript.h++ DAL/implementation/captain.cpp DAL/implementation/captain.h++ DAL/implementation/cadet.cpp DAL/implementation/cadet.h++ UI/menu.cpp UI/menu.h++ Container/binarySearchTree.cpp Container/binarySearchTree.h++)
