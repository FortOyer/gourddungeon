# Define an executable
add_executable(DungeonGourd
    src/main.cpp
    src/graphics/rendering/window.cpp)
set_property(TARGET DungeonGourd PROPERTY CXX_STANDARD 11)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

# Define the libraries this project depends upon
target_link_libraries(DungeonGourd gourd)
target_link_libraries(DungeonGourd SDL2)

add_subdirectory(test)

list(APPEND ExternalSharedLibraries 
    ${SDL2_LIBDIR}/libSDL2-2.0.so.0.5.0
    ${SDL2_LIBDIR}/libSDL2-2.0.so.0
    ${SDL2_LIBDIR}/libSDL2.so
    ${SDL2IMAGE_LIBDIR}/libSDL2_image-2.0.so.0.0.1
    ${SDL2IMAGE_LIBDIR}/libSDL2_image-2.0.so.0
    ${SDL2IMAGE_LIBDIR}/libSDL2_image.so)
# This will copy any files with differing timestamps
message(STATUS "\tCopying shared libraries." )
file(COPY ${ExternalSharedLibraries} DESTINATION "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" NO_SOURCE_PERMISSIONS)
