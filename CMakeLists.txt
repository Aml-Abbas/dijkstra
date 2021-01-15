cmake_minimum_required(VERSION 3.17)
project(dijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(dijkstra main.cpp Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp dijkstra.cpp dijkstra.h)

add_executable(test1 Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp testNodeSet.cpp dijkstra.cpp dijkstra.h)

add_executable(test2 Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp test_Dijkstra.cpp dijkstra.cpp dijkstra.h)

add_executable(test3 Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp dijkstra.cpp dijkstra.h testNode.cpp)

add_executable(test4 Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp Graph.cpp Graph.h  dijkstra.cpp dijkstra.h testGraphNofile.cpp)

add_executable(test5 Edge.h Edge.cpp Node.h Node.cpp NodeSet.h NodeSet.cpp Graph.cpp Graph.h  dijkstra.cpp dijkstra.h mytest_Dijkstra.cpp)
