cmake_minimum_required(VERSION 3.8)
project(Data_structures)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ListArray_full.h PrettyPrintList.h ListCursor.h)
add_executable(Data_structures ${SOURCE_FILES})