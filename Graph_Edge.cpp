#include "Graph_Edge.h"


Graph_Edge::Graph_Edge(Graph_Node *from, Graph_Node *to):
        _from(from),
        _to(to),
        _selfPointer(NULL),
        _outPointer(NULL)
        {
}