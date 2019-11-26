cmake_minimum_required(VERSION 3.10.2)
project(da_01)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(da_01 main.cpp vector.h)
add_executable(generate generate.cpp)
add_executable(square_sort square_counting_sort.cpp)
add_executable(std_sort std_sort.cpp)
add_executable(test_speed test_speed.cpp)
add_executable(serega serega.cpp)