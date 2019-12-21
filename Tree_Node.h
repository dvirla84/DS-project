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
    Tree_Node *parent;
    Tree_Node *left_child;
    Tree_Node *right_sibling;
public:
    Tree_Node();
    Tree_Node *Delete_Node_And_Go_To(Tree_Node *go_to);
    Tree_Node *Get_parent() const {return parent;};
    Tree_Node *Get_left_child() const {return left_child;};
    Tree_Node *Get_right_sibling() const {return right_sibling;};
};


#endif //DIRECTEDGRAPH_TREE_NODE_H
