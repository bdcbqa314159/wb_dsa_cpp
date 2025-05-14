cmake_minimum_required(VERSION 3.30)

project(wb_dsa_with_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

MESSAGE(STATUS "the source directory is: ${CMAKE_SOURCE_DIR}")

add_subdirectory(book)
add_subdirectory(libraries)
add_subdirectory(work)



