//
// Created by dvir on 15/12/2019.
//

#include "Rooted_Tree.h"

static const int PARENT_SIBLING = 0;
static const int CHILD = 1;

Rooted_Tree:: Rooted_Tree(){root = nullptr;}
Rooted_Tree:: ~Rooted_Tree()
{
    Tree_Node *x = this->root;
    int from = PARENT_SIBLING;
    while (x != nullptr)
    {
        if (from == PARENT_SIBLING)
        {
            if (x->Get_left_child() != nullptr) x = x->Get_left_child();
            else
            {
                if (x->Get_right_sibling() != nullptr) x = x->Delete_Node_And_Go_To(x->Get_right_sibling());
                else
                {
                    from = CHILD;
                    x = x->Delete_Node_And_Go_To(x->Get_parent());
                }
            }
        }
        else if (x->Get_right_sibling() != nullptr)
        {
            from = PARENT_SIBLING;
            x = x->Delete_Node_And_Go_To(x->Get_right_sibling());
        }
        else x->Delete_Node_And_Go_To(x->Get_parent());
    }
}
void Rooted_Tree::Print_By_Layer(std::ostream & stream) const {}
void Rooted_Tree::Preorder_Print(std::ostream & stream) const {}
;
