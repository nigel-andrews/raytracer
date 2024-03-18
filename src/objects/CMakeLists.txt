add_library(geometry STATIC sphere.cpp)

target_include_directories(geometry PRIVATE ${SRC_DIR})

set_target_properties(geometry PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

target_link_libraries(geometry PRIVATE compile_options)
