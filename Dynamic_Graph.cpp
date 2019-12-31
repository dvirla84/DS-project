#include "Dynamic_Graph.h"

Dynamic_Graph::Dynamic_Graph():
        _nodes(new List<Graph_Node*>),
        _edges(new List<Graph_Edge*>)
{}

Dynamic_Graph:: ~Dynamic_Graph()
{
    while(_edges->getSize() > 0)
    {
        Graph_Edge* temp = _edges->popFront();
        this->Delete_Edge(temp);
    }
    while(_nodes->getSize() > 0)
    {
        Graph_Node* temp = _nodes->popFront();
        this->Delete_Node(temp);
    }
    delete _nodes;
    delete _edges;
}

Graph_Node* Dynamic_Graph:: Insert_Node(unsigned node_key)
{
    Graph_Node* node = new Graph_Node(node_key);
    node->setSelfPointer(_nodes->pushBack(node));
    return node;
}

void Dynamic_Graph::  Delete_Node(Graph_Node* node)
{
    _nodes->erase(node->getSelfPointer());
    delete node;
}

Graph_Edge* Dynamic_Graph:: Insert_Edge(Graph_Node* from, Graph_Node* to)
{
    Graph_Edge* edge = new Graph_Edge(from, to);
    edge->setSelfPointer(_edges->pushBack(edge));
    edge->setOutPointer(from->insertOutEdge(edge));
}

void Dynamic_Graph:: Delete_Edge(Graph_Edge* edge)
{
    _edges->erase(edge->getSelfPointer());
    edge->getFrom()->eraseOutEdge(edge->getOutPointer());
    delete edge;
}

Rooted_Tree* Dynamic_Graph:: SCC() const {}

Rooted_Tree*  Dynamic_Graph:: BFS(Graph_Node* source) const{}