#include "Dynamic_Graph.h"

Dynamic_Graph::Dynamic_Graph():
        _nodes(new List<Graph_Node*>),
        _nodesSize(0),
        _edgesSize(0),
        _edges(new List<Graph_Edge*>)
{}

Dynamic_Graph:: ~Dynamic_Graph()
{
    delete _nodes;
    delete _edges;
}

Graph_Node* Dynamic_Graph:: Insert_Node(unsigned node_key)
{
    Graph_Node* node = new Graph_Node(node_key);
    node->setSelfPointer(_nodes->pushBack(node));
    _nodesSize++;
    return node;
}

void Dynamic_Graph::  Delete_Node(Graph_Node* node)
{

}

Graph_Edge* Dynamic_Graph:: Insert_Edge(Graph_Node* from, Graph_Node* to)
{
    Graph_Edge* edge = new Graph_Edge(from, to);

}

void Dynamic_Graph:: Delete_Edge(Graph_Edge* edge){}

Rooted_Tree* Dynamic_Graph:: SCC() const {}

Rooted_Tree*  Dynamic_Graph:: BFS(Graph_Node* source) const{}