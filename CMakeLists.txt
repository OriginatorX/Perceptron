cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(Perceptron)

add_library(Perceptio
    inc/random.hpp
    src/random.cpp

    inc/perceptron.hpp
    src/perceptron.cpp
)
target_include_directories(Perceptio
    PUBLIC
    "inc"
)
add_executable(net
    main.cpp
)
target_link_libraries(net Perceptio)