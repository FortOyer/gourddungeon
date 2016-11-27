project(GourdsLib VERSION 0.1 LANGUAGES CXX)

add_subdirectory(src)
add_library(gourd SHARED ${SOURCE})

set_property(TARGET gourd PROPERTY CXX_STANDARD 11)

target_include_directories(gourd PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_public>
    $<INSTALL_INTERFACE:include_public>)

target_include_directories(gourd PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_private>)

add_subdirectory(internaltest)
