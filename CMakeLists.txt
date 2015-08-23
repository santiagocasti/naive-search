cmake_minimum_required(VERSION 3.3)
project(naive-search)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp btree_node.cpp btree_node.h inverted_index.cpp inverted_index.h)
add_executable(naive-search ${SOURCE_FILES})

SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")