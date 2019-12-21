//
// Created by dvir on 15/12/2019.
//

#ifndef DIRECTEDGRAPH_ROOTED_TREE_H
#define DIRECTEDGRAPH_ROOTED_TREE_H

#include "List.h"
#include "Tree_Node.h"
#include <cstddef>
#include <ostream>

class Rooted_Tree {
private:
    Tree_Node *root;
public:
    Rooted_Tree();
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;
    Tree_Node *Get_root() const {return root;};



};


#endif //DIRECTEDGRAPH_ROOTED_TREE_H
