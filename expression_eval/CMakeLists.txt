cmake_minimum_required(VERSION 3.10)
project(expression_eval C)

set(CMAKE_C_STANDARD 99)

add_executable(expression_eval main.c stack.h)