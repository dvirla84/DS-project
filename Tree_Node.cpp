//
// Created by EB on 20/12/2019.
//

#include "Tree_Node.h"

Tree_Node:: Tree_Node() : Node()
{
    parent = nullptr;
    left_child = nullptr;
    right_sibling = nullptr;
}

Tree_Node *Tree_Node:: Delete_Node_And_Go_To(Tree_Node *go_to)
{
    this->~Tree_Node();
    return go_to;
}