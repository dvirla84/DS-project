#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "List.h"
#include <cstddef>
#include "Node.h"
class Graph_Node: public Node {
private:
    List<Graph_Node*>* _Out;
    List<Graph_Node*>* _In;
public:
    Graph_Node(unsigned key);
    unsigned Get_out_Degree() const {return _Out->getSize();}
    unsigned Get_in_Degree() const {return _In->getSize();}
    ~Graph_Node();
};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
