cmake_minimum_required(VERSION 3.8)
project(Data_structures)

set(CMAKE_CXX_STANDARD 11)



add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)


set(SOURCE_FILES main.cpp ListArray.h ListCursor.h PrettyPrintList.h tests/test_ListArray.cpp)
add_executable(Data_structures ${SOURCE_FILES})


set(TEST_FILES tests/test_main.cpp tests/test_ListArray.cpp)
add_executable(Test ${TEST_FILES} tests/test_main.cpp)
target_link_libraries(Test gtest gtest_main)
