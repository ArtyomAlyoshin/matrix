cmake_minimum_required(VERSION 3.21)
project(lab5d C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5d main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h)

add_subdirectory(libs)
target_link_libraries(lab5d algorithms)
target_link_libraries(lab5d data_structures)
