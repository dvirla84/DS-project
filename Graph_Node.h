#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "List.h"
#include <cstddef>
#include "Node.h"
class Graph_Node: public Node {
private:
    List<Graph_Node> Out;
    List<Graph_Node> In;
public:
    unsigned Get_out_Degree() const {return Out.getSize();}
    unsigned Get_in_Degree() const {return In.getSize();}

};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
