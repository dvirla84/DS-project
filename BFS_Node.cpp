//
// Created by EB on 01/01/2020.
//

#include "BFS_Node.h"

BFS_Node::BFS_Node(unsigned int key) :
        Graph_Node(key),
        _color(WHITE),
        _parent(NULL),
        _distance(UNIT_MAX)
{
}