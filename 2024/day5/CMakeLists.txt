cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

project(advent_of_code)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(main "${SOURCES}")
# target_compile_options(main PRIVATE -fsanitize=address)
# target_link_options(main PRIVATE -fsanitize=address)
target_link_libraries(main)
