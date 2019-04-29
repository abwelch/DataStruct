cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project(mazeProject)
#Add additional files to set with a space 
set(SOURCE buildMaze.cpp maze.cpp mazeCell.h DisjSets.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})