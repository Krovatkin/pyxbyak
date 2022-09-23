

cmake_minimum_required(VERSION 3.0)

project(pyxbyak LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(xbyak)
add_executable(toy main.cpp)

add_custom_command(TARGET toy 
    POST_BUILD
    COMMAND cp ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})

target_link_libraries(toy xbyak::xbyak)

