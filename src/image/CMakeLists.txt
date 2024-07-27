add_library(image STATIC app.cpp)

set_target_properties(image PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

target_link_libraries(image PRIVATE compile_options)
