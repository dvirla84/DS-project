//
// Created by dvir on 15/12/2019.
//

#include "Rooted_Tree.h"

static const int PARENT_SIBLING = 0;
static const int CHILD = 1;

Rooted_Tree:: ~Rooted_Tree()
{
    Tree_Node *y;
    Tree_Node *x = this->_root;
    int from = PARENT_SIBLING;
    while (x != nullptr)
    {
        if (from == PARENT_SIBLING)
        {
            if (x->Get_left_child() != nullptr) x = x->Get_left_child();
            else
            {
                if (x->Get_right_sibling() != nullptr)
                {
                    y = x;
                    x = x->Get_right_sibling();
                    delete y;
                }
                else
                {
                    from = CHILD;
                    y = x;
                    x = x->Get_parent();
                    delete y;
                }
            }
        }
        else if (x->Get_right_sibling() != nullptr)
        {
            from = PARENT_SIBLING;
            y = x;
            x = x->Get_right_sibling();
            delete y;
        }
        else
            {
                y = x;
                x = x->Get_parent();
                delete y;
            }
    }
}
void Rooted_Tree::Print_By_Layer(std::ostream & stream) const {}
void Rooted_Tree::Preorder_Print(std::ostream & stream) const {}
;
