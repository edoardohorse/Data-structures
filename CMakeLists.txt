cmake_minimum_required(VERSION 3.8)
project(Data_structures)

set(CMAKE_CXX_STANDARD 11)



add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)


set(SOURCE_FILES main.cpp PrettyPrintList.h ListArray.h ListCursor.h
        ListPointer.h ListDoublePointer.h ListCircular.h StackArray.h
        StackPointer.h QueueArray.h QueuePointer.h Set.h Map.h)

add_executable(Data_structures ${SOURCE_FILES})

# Test part
set(TEST_COMMONS tests/test_main.cpp tests/PrettyPrintList_for_test.h)

set(TEST_LIST_ARRAY ${TEST_COMMONS} tests/test_ListArray.cpp tests/ListArray_for_test.h )
set(TEST_LIST_CURSOR ${TEST_COMMONS} tests/test_ListCursor.cpp tests/ListCursor_for_test.h)
set(TEST_LIST_POINTER ${TEST_COMMONS} tests/test_ListPointer.cpp tests/ListPointer_for_test.h)
set(TEST_LIST_DOUBLE_POINTER ${TEST_COMMONS} tests/test_ListDoublePointer.cpp tests/ListDoublePointer_for_test.h)
set(TEST_LIST_CIRCULAR ${TEST_COMMONS} tests/test_ListCircular.cpp tests/ListCircular_for_test.h)
set(TEST_STACK_ARRAY ${TEST_COMMONS} tests/test_StackArray.cpp tests/StackArray_for_test.h)
set(TEST_STACK_POINTER ${TEST_COMMONS} tests/test_StackPointer.cpp tests/StackPointer_for_test.h)
set(TEST_QUEUE_ARRAY ${TEST_COMMONS} tests/test_QueueArray.cpp tests/QueueArray_for_test.h)
set(TEST_QUEUE_POINTER ${TEST_COMMONS} tests/test_QueuePointer.cpp tests/QueuePointer_for_test.h)
set(TEST_SET_ARRAY ${TEST_COMMONS} tests/test_Set.cpp tests/Set_for_test.h)
set(TEST_MAP ${TEST_COMMONS} tests/test_Map.cpp tests/Map_for_test.h tests/Hash.h)



add_executable(Test_LA ${TEST_LIST_ARRAY} tests/test_main.cpp)
add_executable(Test_LCU ${TEST_LIST_CURSOR} tests/test_main.cpp)
add_executable(Test_LP ${TEST_LIST_POINTER} tests/test_main.cpp)
add_executable(Test_LDP ${TEST_LIST_DOUBLE_POINTER} tests/test_main.cpp)
add_executable(Test_LCI ${TEST_LIST_CIRCULAR} tests/test_main.cpp)
add_executable(Test_STKA ${TEST_STACK_ARRAY} tests/test_main.cpp)
add_executable(Test_STKP ${TEST_STACK_POINTER} tests/test_main.cpp)
add_executable(Test_QUEA ${TEST_QUEUE_ARRAY} tests/test_main.cpp)
add_executable(Test_QUEP ${TEST_QUEUE_POINTER} tests/test_main.cpp)
add_executable(Test_SET ${TEST_SET_ARRAY} tests/test_main.cpp)
add_executable(Test_MAP ${TEST_MAP} tests/test_main.cpp)


target_link_libraries(Test_LA gtest gtest_main)
target_link_libraries(Test_LCU gtest gtest_main)
target_link_libraries(Test_LP gtest gtest_main)
target_link_libraries(Test_LDP gtest gtest_main)
target_link_libraries(Test_LCI gtest gtest_main)
target_link_libraries(Test_STKA gtest gtest_main)
target_link_libraries(Test_STKP gtest gtest_main)
target_link_libraries(Test_QUEA gtest gtest_main)
target_link_libraries(Test_QUEP gtest gtest_main)
target_link_libraries(Test_SET gtest gtest_main)
target_link_libraries(Test_MAP gtest gtest_main)