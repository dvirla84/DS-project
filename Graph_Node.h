#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "List.h"
#include <cstddef>
#include "Node.h"
#include "Graph_Edge.h"
#include "List.h"

class Graph_Node: public Node {
private:
    ListItem<Graph_Node*>* _selfPointer;
    List<Graph_Edge*>* _outList;
    unsigned _inCounter;
public:
    Graph_Node(unsigned key);
    void setSelfPointer(ListItem<Graph_Node*>* selfPointer);
    unsigned Get_out_Degree() const {return _outList->getSize();}
    unsigned Get_in_Degree() const {return _inCounter();}
    ~Graph_Node();
};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
