//
// Created by EB on 01/01/2020.
//

#ifndef DIRECTEDGRAPH_BFS_NODE_H
#define DIRECTEDGRAPH_BFS_NODE_H


#include "Graph_Node.h"
#define WHITE 0
#define GREY 1
#define BLACK 2
#define UNIT_MAX 0xffffffff


class BFS_Node: public Graph_Node {
private:
    int _color;
    BFS_Node* _parent;
    unsigned _distance;
public:
    BFS_Node(unsigned int key);
};


#endif //DIRECTEDGRAPH_BFS_NODE_H
