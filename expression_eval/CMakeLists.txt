cmake_minimum_required(VERSION 3.10)
project(expression_eval C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lm")
add_executable(expression_eval main.c stack.h utils.h expr.h)

target_link_libraries(expression_eval m)