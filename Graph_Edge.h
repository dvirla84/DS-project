#ifndef DIRECTEDGRAPH_GRAPH_EDGE_H
#define DIRECTEDGRAPH_GRAPH_EDGE_H

#include "Graph_Node.h"
class Graph_Edge {
private:
    Graph_Node *_from;
    Graph_Node *_to;
    Graph_Edge *_next;
    Graph_Edge *_previous;
public:
    Graph_Edge(Graph_Node *from, Graph_Node *to);
    Graph_Edge* getNext() {return _next;}
    Graph_Edge* getPrevious() {return _previous;}
    Graph_Node *getFrom() const{return _from;}
    Graph_Node *getTo() const{return _to;}
};


#endif //DIRECTEDGRAPH_GRAPH_EDGE_H
