#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "List.h"
#include <cstddef>
#include "Node.h"
class Graph_Node: public Node {
private:
    List<Graph_Node*>* _out;
    List<Graph_Node*>* _in;
    Graph_Node* _next;
    Graph_Node* _previous;
public:
    Graph_Node(unsigned key);
    Graph_Node* getNext() {return _next;}
    Graph_Node* getPrevious() {return _previous;}
    unsigned Get_out_Degree() const {return _out->getSize();}
    unsigned Get_in_Degree() const {return _in->getSize();}
    ~Graph_Node();
};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
