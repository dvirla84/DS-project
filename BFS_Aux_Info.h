//
// Created by EB on 01/01/2020.
//

#ifndef DIRECTEDGRAPH_BFS_AUX_INFO_H
#define DIRECTEDGRAPH_BFS_AUX_INFO_H


#include "Graph_Node.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define UNIT_MAX 0xffffffff


class BFS_Aux_Info{
private:
    Graph_Node* _self;
    int _color;
    Graph_Node* _parent;
    unsigned _d;
public:
    BFS_Aux_Info();
    void setColor(unsigned c){_color = c;}
    void setParent(Graph_Node* p){_parent = p;}
    void setD(unsigned d){_d = d;}
    void setSelf(Graph_Node* s){_self = s;}
    const Graph_Node* getSelf() const{return _self;}
    const unsigned getColor() const{return _color;}
    const unsigned getD() const{return _d;}
    const Graph_Node* getParent() const{return _parent;}
};


#endif //DIRECTEDGRAPH_BFS_AUX_INFO_H
