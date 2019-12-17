#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "Graph_Edge.h"
#include <cstddef>

class Graph_Node {
private:
    unsigned key;
public:
    void Connect_To(Graph_Node v);
    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const{return key;}

};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
