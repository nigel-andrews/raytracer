include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.6.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests test.cpp)
target_include_directories(tests PUBLIC ../src/)
target_link_libraries(tests PRIVATE compile_options Catch2::Catch2WithMain)
