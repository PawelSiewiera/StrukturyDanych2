cmake_minimum_required(VERSION 3.30)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5
        main.cpp
        test.cpp
        TablicaPriorytetowa.cpp
        heap.cpp
        generate_data.cpp
)


target_include_directories(untitled5 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
