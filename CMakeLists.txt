cmake_minimum_required(VERSION 3.15)
project(DirectedGraph)

set(CMAKE_CXX_STANDARD 11)

add_executable(DirectedGraph main.cpp Rooted_Tree.cpp Rooted_Tree.h Graph_Node.cpp Graph_Node.h Graph_Edge.cpp Graph_Edge.h Dynamic_Graph.cpp Dynamic_Graph.h)