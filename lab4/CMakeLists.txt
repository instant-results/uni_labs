cmake_minimum_required(VERSION 3.5)

project(Sample LANGUAGES CXX)

add_executable(exec_main ./src/main.cpp ./src/lab4_class.cpp ./include/project_lab4/public_headers/lab4_class_header.hpp)