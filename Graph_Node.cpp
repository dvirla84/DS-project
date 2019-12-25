#include "Graph_Node.h"
Graph_Node::Graph_Node(unsigned key):
        Node(key),
        _Out(new List<Graph_Node*>),
        _In(new List<Graph_Node*>){}

Graph_Node:: ~Graph_Node()
{
    delete _Out;
    delete _In;
}