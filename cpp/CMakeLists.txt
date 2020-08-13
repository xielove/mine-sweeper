cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_CXX_STANDARD_REQUIRED c++11)

project(MineSweeper)

add_executable(main
    game.cpp
    fieldItem.cpp
    main.cpp
)