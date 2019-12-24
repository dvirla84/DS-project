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
    while (x != NULL)
    {
        if (from == PARENT_SIBLING)
        {
            if (x->getLeftChild() != NULL) x = x->getLeftChild();
            else
            {
                if (x->getRightSibling()!= NULL)
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
        else if (x->getRightSibling() != NULL)
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
    List<Tree_Node*> *leftChildren = new List<Tree_Node*>;
    Tree_Node *x = this->_root;
    leftChildren->pushFront(x);
    while (leftChildren->getSize() > 0)
    {
        Tree_Node *temp = leftChildren->popBack();
        stream << temp->Get_key();
        if (temp->getLeftChild() != NULL) leftChildren->pushFront(temp->getLeftChild());
        while (temp->getRightSibling()!=NULL)
        {
            stream << ",";
            if (temp->getLeftChild() != NULL) leftChildren->pushFront(temp->getLeftChild());
            temp = temp->getRightSibling();
            stream << temp->Get_key();
        }
        stream << "\n";
    }
}
void Rooted_Tree::Preorder_Print(std::ostream & stream) const {}
;
