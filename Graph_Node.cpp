#include "Graph_Node.h"
Graph_Node::Graph_Node(unsigned key):
        Node(key),
        _out(new List<Graph_Node*>),
        _in(new List<Graph_Node*>){}

Graph_Node:: ~Graph_Node()
{
    delete _out;
    delete _in;

}