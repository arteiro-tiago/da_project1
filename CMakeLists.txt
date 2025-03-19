cmake_minimum_required(VERSION 3.10)
project(da_project1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

include_directories(data_structures Files)

add_executable(da_project1
        Files/builder.cpp
        Files/menu.cpp
        main.cpp
)

target_include_directories(da_project1 PRIVATE data_structures Files)