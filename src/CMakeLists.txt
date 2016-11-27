cmake_minimum_required (VERSION 3.5)
project(DungeonGourd VERSION 0.1 LANGUAGES CXX)

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/bin)

INCLUDE(FindPkgConfig)

enable_testing()
add_subdirectory(lib)
add_subdirectory(app)
