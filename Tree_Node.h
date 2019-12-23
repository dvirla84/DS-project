//
// Created by EB on 20/12/2019.
//

#ifndef DIRECTEDGRAPH_TREE_NODE_H
#define DIRECTEDGRAPH_TREE_NODE_H
#include "List.h"
#include <cstddef>
#include "Node.h"

class Tree_Node: public Node {
private:
    Tree_Node *_parent;
    Tree_Node *_left_child;
    Tree_Node *_right_sibling;
public:
    Tree_Node():
    _parent(NULL),
    _left_child(NULL),
    _right_sibling(NULL){};
    Tree_Node *getParent() const {return _parent;};
    Tree_Node *getLeftChild() const {return _left_child;};
    Tree_Node *getRightSibling() const {return _right_sibling;};
};


#endif //DIRECTEDGRAPH_TREE_NODE_H
