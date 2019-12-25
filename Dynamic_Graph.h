#ifndef DIRECTEDGRAPH_DYNAMIC_GRAPH_H
#define DIRECTEDGRAPH_DYNAMIC_GRAPH_H

#include "List.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"

class Dynamic_Graph {
private:
    List<Graph_Node*> *_nodes;
    unsigned _nodesSize;
    List<Graph_Edge*> *_edges;
    unsigned _edgesSize;

public:
    Dynamic_Graph();
};


#endif //DIRECTEDGRAPH_DYNAMIC_GRAPH_H
