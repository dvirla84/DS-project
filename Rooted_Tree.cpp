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
            if (x->getLeftChild() != nullptr) x = x->getLeftChild();
            else
            {
                if (x->getRightSibling()!= nullptr)
                {
                    y = x;
                    x = x->getRightSibling();
                    delete y;
                }
                else
                {
                    from = CHILD;
                    y = x;
                    x = x->getParent();
                    delete y;
                }
            }
        }
        else if (x->getRightSibling() != nullptr)
        {
            from = PARENT_SIBLING;
            y = x;
            x = x->getRightSibling();
            delete y;
        }
        else
            {
                y = x;
                x = x->getParent();
                delete y;
            }
    }
}
void Rooted_Tree::Print_By_Layer(std::ostream & stream) const
{
   /* List<Tree_Node*> list;
    Tree_Node *x = this->_root;
    list.push();
    while (list.getSize() >0);
    List<int> list1;
    list1.push(reinterpret_cast<const ListItem<int> *>(1));*/
}
void Rooted_Tree::Preorder_Print(std::ostream & stream) const {}
;
