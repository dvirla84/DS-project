#include "Dynamic_Graph.h"

Dynamic_Graph::  Dynamic_Graph():
_firstNode (NULL),
_nodesSize(0),
_firstEdge(NULL),
_edgesSize(0)
{}

Dynamic_Graph:: ~Dynamic_Graph()
{
    Graph_Node* x = _firstNode;
    while(x != NULL)
    {
        Graph_Node* temp = x->getNext();
        delete x;
        x = temp;
    }
    Graph_Edge* y = _firstEdge;
    while(y != NULL)
    {
        Graph_Edge* temp = y->getNext();
        delete y;
        y = temp;
    }
}

Graph_Node* Dynamic_Graph::  Insert_Node(unsigned node_key)
{
    Graph_Node* node = new Graph_Node(node_key);
    _nodes->pushBack(node);
    return node;
}

void Dynamic_Graph::  Delete_Node(Graph_Node* node){}

Graph_Edge*  Dynamic_Graph:: Insert_Edge(Graph_Node* from, Graph_Node* to){}

void Dynamic_Graph:: Delete_Edge(Graph_Edge* edge){}

Rooted_Tree* Dynamic_Graph:: SCC() const {}

Rooted_Tree*  Dynamic_Graph:: BFS(Graph_Node* source) const{}
