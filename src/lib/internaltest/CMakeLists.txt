# This is an /internal/ unit test.
# This does not test the external interface of the library.
# These unit tests are for internal unexposed features. For external library 
# features look at integration testing.

add_executable(testgourd
     ${SOURCE} # Pull in everything from lib/src for compilation.
     test.cpp
     broadcasting.cpp
     creaturegenertion.cpp)

set_property(TARGET testgourd PROPERTY CXX_STANDARD 11)

add_test(testgourd testgourd)
include_directories(testgourd ${CMAKE_SOURCE_DIR}/../extlibs/Catch/single_include)
include_directories(testgourd ${CMAKE_CURRENT_SOURCE_DIR}/../include_private/)