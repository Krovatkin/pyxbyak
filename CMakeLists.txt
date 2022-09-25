

cmake_minimum_required(VERSION 3.0)

project(pyxbyak LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(xbyak)
add_executable(toy main.cpp)

add_custom_command(TARGET toy 
    POST_BUILD
    COMMAND cp ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})

add_subdirectory(pybind11)

pybind11_add_module(pyxbyak pymain.cpp)
target_link_libraries(pyxbyak PUBLIC pybind11::module PRIVATE xbyak::xbyak)

target_link_libraries(toy xbyak::xbyak)

