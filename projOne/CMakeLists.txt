cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++14)
project(projectOne)
#Add additional files to set with a space 
set(SOURCE components.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})