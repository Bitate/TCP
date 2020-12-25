cmake_minimum_required(VERSION 3.16)

set(this TCP)

project(${this})

add_subdirectory(src)
add_subdirectory(googletest)
add_subdirectory(tests)

enable_testing()
