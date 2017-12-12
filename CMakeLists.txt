cmake_minimum_required(VERSION 3.8)
project(Data_structures)

set(CMAKE_CXX_STANDARD 11)



add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)


set(SOURCE_FILES main.cpp PrettyPrintList.h ListArray.h ListCursor.h ListPointer.h ListDoublePointer.h)

add_executable(Data_structures ${SOURCE_FILES})

# Test part
set(TEST_COMMONS tests/test_main.cpp tests/PrettyPrintList_for_test.h)

set(TEST_LIST_ARRAY ${TEST_COMMONS} tests/test_ListArray.cpp tests/ListArray_for_test.h )
set(TEST_LIST_CURSOR ${TEST_COMMONS} tests/test_ListCursor.cpp tests/ListCursor_for_test.h)
set(TEST_LIST_POINTER ${TEST_COMMONS} tests/test_ListPointer.cpp tests/ListPointer_for_test.h)
set(TEST_LIST_DOUBLE_POINTER ${TEST_COMMONS} tests/test_ListDoublePointer.cpp tests/ListDoublePointer_for_test.h)


add_executable(Test_LA ${TEST_LIST_ARRAY} tests/test_main.cpp)
add_executable(Test_LC ${TEST_LIST_CURSOR} tests/test_main.cpp)
add_executable(Test_LP ${TEST_LIST_POINTER} tests/test_main.cpp)
add_executable(Test_LDP ${TEST_LIST_DOUBLE_POINTER} tests/test_main.cpp)


target_link_libraries(Test_LA gtest gtest_main)
target_link_libraries(Test_LC gtest gtest_main)
target_link_libraries(Test_LP gtest gtest_main)
target_link_libraries(Test_LDP gtest gtest_main)

