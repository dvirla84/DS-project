#include "Graph_Node.h"
Graph_Node::Graph_Node(unsigned key):
    Node(key),
    _out(new List<Graph_Node*>),
    _in(new List<Graph_Node*>),
    _next(NULL),
    _previous(NULL){}

Graph_Node:: ~Graph_Node()
{
    delete _out;
    delete _in;
    if(_next != NULL) _next->_previous = _previous;
    if(_previous != NULL) _previous->_next = _next;
}