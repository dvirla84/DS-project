#include "Dynamic_Graph.h"

static unsigned insertTime = 1;

Dynamic_Graph::Dynamic_Graph():
        _edges(new List<Graph_Edge*>),
        _nodes(new List<Graph_Node*>)

{}

Dynamic_Graph:: ~Dynamic_Graph()
{
    while(_edges->getSize() > 0)
    {
        Graph_Edge* temp = _edges->top();
        this->Delete_Edge(temp);
    }
    while(_nodes->getSize() > 0)
    {
        Graph_Node* temp = _nodes->top();
        this->Delete_Node(temp);
    }
    delete _nodes;
    delete _edges;
}

Graph_Node* Dynamic_Graph:: Insert_Node(unsigned node_key)
{
    Graph_Node* node = new Graph_Node(node_key);
    node->setSelfPointer(_nodes->pushFront(node));
    node->setInsertionTime(insertTime);
    insertTime++;
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
    edge->setSelfPointer(_edges->pushFront(edge));
    edge->setOutPointer(from->insertOutEdge(edge));
    edge->getTo()->increaseInDegree();
}

void Dynamic_Graph:: Delete_Edge(Graph_Edge* edge)
{
    ListItem<Graph_Edge*>* temp = edge->getSelfPointer();
    _edges->erase(temp);
    edge->getFrom()->eraseOutEdge(edge->getOutPointer());
    edge->getTo()->decreaseInDegree();
    delete edge;
}


Rooted_Tree* Dynamic_Graph:: SCC() const {}


//void Dynamic_Graph::BFS_init(List<BFS_Aux_Info*> *BFS_nodes, List<BFS_DFS_Edge*> *BFS_edges)
//{
//    int nodesSize = _nodes->getSize();
//    Graph_Node* toCopyNode = _nodes->top();
//    for (int i = 0; i < nodesSize; ++i)
//    {
//        BFS_Aux_Info* copied = new BFS_DFS_Node(toCopyNode->Get_key());
//        copied->setSelfPointer(BFS_nodes->pushBack(copied));
//        toCopyNode = toCopyNode->getSelfPointer()->_next->_item;
//    }
//
//    int edgesSize = _edges->getSize();
//    Graph_Edge* toCopyEdge = _edges->top();
//    for (int j = 0; j < edgesSize; ++j)
//    {
//        BFS_DFS_Edge* copied = new BFS_DFS_Edge(toCopyEdge->getFrom(), toCopyEdge->getTo());
//
//    }
//}

void Dynamic_Graph::BFS_init(BFS_Aux_Info** infoArr, Graph_Node* source) const
{
    int nodesSize = _nodes->getSize();
    Graph_Node* node = _nodes->top();
    for (int i = 0; i < nodesSize; ++i)
    {
        infoArr[node->getInsertionTime()] = new BFS_Aux_Info();
        infoArr[node->getInsertionTime()]->setSelf(node);
        node = node->getSelfPointer()->getNext()->getItem();
    }

    infoArr[source->getInsertionTime()]->setColor(GREY);
    infoArr[source->getInsertionTime()]->setD(0);

}

Rooted_Tree*  Dynamic_Graph:: BFS(Graph_Node* source) const
{
    BFS_Aux_Info** infoArr = new BFS_Aux_Info*[insertTime];
    BFS_init(infoArr,source);

    for (int i = 0; i < insertTime; ++i) {
        delete infoArr[i];
    }
    delete[] infoArr;
}