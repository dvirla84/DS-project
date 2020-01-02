#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned key):
        Node(key),
        _insertionTime(0),
        _selfPointer(NULL),
        _outList(new List<Graph_Edge*>),
        _inCounter(0){}


Graph_Node:: ~Graph_Node()
{
    delete _outList;
}

void Graph_Node:: setSelfPointer(ListItem<Graph_Node*>* selfPointer)
{
    _selfPointer = selfPointer;
}

