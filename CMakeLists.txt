cmake_minimum_required(VERSION 3.13)
project(xs_epi)

set(CMAKE_CXX_STANDARD 14)

add_executable(count_bits primative_types/count_bits.cpp)
add_executable(parity primative_types/parity.cpp)
add_executable(swap_bits primative_types/swap_bits.cpp)
