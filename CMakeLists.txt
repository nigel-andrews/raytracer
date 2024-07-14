cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(raytracer)

add_library(compile_options INTERFACE)

target_compile_options(
  compile_options
  INTERFACE "-Wall"
            "-Wextra"
            "-pedantic"
            "-std=c++23"
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-Werror>
            $<$<CONFIG:Debug>:-O0>
            $<$<CONFIG:Debug>:-fno-inline>
            $<$<CONFIG:Debug>:-g3>
            $<$<CONFIG:Debug>:-fsanitize=address>)

target_link_options(compile_options INTERFACE
                    $<$<CONFIG:Debug>:-fsanitize=address>)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(raytracer src/main.cpp)

set_target_properties(raytracer PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

target_include_directories(raytracer PRIVATE ${SRC_DIR})
