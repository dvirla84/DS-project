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
    Tree_Node *_root;
public:
    Rooted_Tree():_root(NULL){};
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;
    Tree_Node *getRoot() const {return _root;};
    Tree_Node *setRoot(Tree_Node* newRoot) {_root = newRoot;};



};


#endif //DIRECTEDGRAPH_ROOTED_TREE_H
