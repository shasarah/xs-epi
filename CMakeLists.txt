cmake_minimum_required(VERSION 3.13)
project(xs_epi)

set(CMAKE_CXX_STANDARD 14)

add_executable(count_bits primative_types/count_bits.cpp)
add_executable(parity primative_types/parity.cpp)
add_executable(swap_bits primative_types/swap_bits.cpp)
add_executable(reverse_bits primative_types/03_reverse_bits.cpp)
add_executable(closest_in_same_weight primative_types/04_closest_int_same_weight.cpp)
add_executable(comput_multiply primative_types/05_compute_multiply.cpp)
