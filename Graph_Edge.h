#ifndef DIRECTEDGRAPH_GRAPH_EDGE_H
#define DIRECTEDGRAPH_GRAPH_EDGE_H

class Graph_Node;
#include "List.h"

class Graph_Edge {
private:
    Graph_Node *_from;
    Graph_Node *_to;
    ListItem<Graph_Edge*>* _selfPointer;
    ListItem<Graph_Edge*>* _outPointer;

public:
    Graph_Edge(Graph_Node* from, Graph_Node* to);
    Graph_Node *getFrom() const{return _from;}
    Graph_Node *getTo() const{return _to;}
};


#endif //DIRECTEDGRAPH_GRAPH_EDGE_H
