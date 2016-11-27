# Every library has unit tests, of course
add_executable(testapp
     apptest.cpp)

target_link_libraries(testapp gourd)

add_test(testapp testapp)
include_directories(testapp ${CMAKE_SOURCE_DIR}/../extlibs/Catch/single_include)