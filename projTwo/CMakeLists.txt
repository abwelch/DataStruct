cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++11)
project(projectTwo)
#Add additional files to set with a space 
set(SOURCE Employee.cpp empmaps.cpp empdriver.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})