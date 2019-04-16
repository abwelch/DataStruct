cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++11)
project(projThree)
#Add additional files to set with a space 
set(SOURCE sorting.cpp insertsort.h quicksort.h mergesort.h heapsort.h)
add_executable(${PROJECT_NAME} ${SOURCE})