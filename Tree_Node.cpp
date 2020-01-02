//
// Created by EB on 20/12/2019.
//

#include "Tree_Node.h"

void Tree_Node:: setParent(Tree_Node *newParent ){this->_parent = newParent;}
void Tree_Node:: setLeftChild(Tree_Node *newChild){this->_left_child = newChild;}
void Tree_Node:: setRightSibling(Tree_Node *newSibling){this->_right_sibling = newSibling;}
Tree_Node:: ~Tree_Node()
{
    _parent = NULL;
    _right_sibling = NULL;
    _left_child = NULL;
}
