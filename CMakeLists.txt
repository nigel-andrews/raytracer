cmake_minimum_required(VERSION 3.20)

project(raytracer)

add_library(compile_options INTERFACE)

set_target_properties(compile_options PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS
                                                                 OFF)

target_compile_options(
  compile_options
  INTERFACE "-Wall"
            "-Wextra"
            "-pedantic"
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-Werror>
            $<$<CONFIG:Debug>:-O0>
            $<$<CONFIG:Debug>:-fno-inline>
            $<$<CONFIG:Debug>:-g3>
            $<$<CONFIG:Debug>:-fsanitize=address>)

target_link_options(compile_options INTERFACE
                    $<$<CONFIG:Debug>:-fsanitize=address>)

add_executable(raytracer src/main.cpp)

target_link_libraries(raytracer PRIVATE compile_options)
