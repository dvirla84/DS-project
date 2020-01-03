#include "Dynamic_Graph.h"


Dynamic_Graph::Dynamic_Graph():
        _edges(new List<Graph_Edge*>),
        _nodes(new List<Graph_Node*>),
        _insertTime(1)
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
    node->setInsertionTime(_insertTime);
    _insertTime++;
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
    return edge;
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


void Dynamic_Graph::BFS_init(unsigned* colorArr, Graph_Node* source, List<Graph_Node*> *graphQueue) const
{
    int nodesSize = _nodes->getSize();
    Graph_Node* node = _nodes->top();
    for (int i = 0; i < nodesSize; ++i)
    {
        colorArr[node->getInsertionTime()] = WHITE;
        if (node->getSelfPointer()->getPrevious() != NULL)
            node = node->getSelfPointer()->getPrevious()->getItem();
    }

    colorArr[source->getInsertionTime()] = GRAY;
    graphQueue->pushFront(source);
}

Rooted_Tree*  Dynamic_Graph:: BFS(Graph_Node* source) const
{
    unsigned* colorArr = new unsigned[_insertTime];
    List<Graph_Node*>* graphQueue = new List<Graph_Node*>;
    List<Tree_Node*>* treeQueue = new List<Tree_Node*>;
    BFS_init(colorArr,source, graphQueue);
    Tree_Node* root = new Tree_Node(source->Get_key());
    Rooted_Tree* rootedTree = new Rooted_Tree();
    rootedTree->setRoot(root);
    treeQueue->pushFront(root);

    while(graphQueue->getSize() > 0)
    {
        Graph_Node* u = graphQueue->popBack();
        Tree_Node* parent = treeQueue->popBack();
        unsigned outSize = u->Get_out_Degree();
        if(outSize == 0) continue;
        Graph_Edge* u_v = u->getOutList()->top();
        Graph_Node* v = u_v->getTo();
        int counter = 0;
//        while(colorArr[v->getInsertionTime()] != WHITE)
//        {
//            if(u_v->getOutPointer()->getPrevious() != NULL)
//            {
//                u_v = u_v->getOutPointer()->getPrevious()->getItem();
//                v = u_v->getTo();
//                counter++;
//            }
//            else break;
//        }
        Tree_Node* rightestSibling = new Tree_Node(v->Get_key());
//        if(counter == outSize)
//            delete rightestSibling;

        for (unsigned i = counter; i < outSize ; i++)
        {
            if(colorArr[v->getInsertionTime()] == WHITE)
            {
                if(parent->getLeftChild() != NULL) {
                    colorArr[v->getInsertionTime()] = GRAY;
                    graphQueue->pushFront(v);
                    Tree_Node *brother = new Tree_Node(v->Get_key());
                    brother->setParent(parent);
                    rightestSibling->setRightSibling(brother);
                    rightestSibling = brother;
                    treeQueue->pushFront(rightestSibling);
                }
                else
                    parent->setLeftChild(rightestSibling);
            }
            if(u_v->getOutPointer()->getPrevious() != NULL)
            {
                u_v = u_v->getOutPointer()->getPrevious()->getItem();
                v = u_v->getTo();
            }
        }
        colorArr[u->getInsertionTime()] = BLACK;
    }
    delete treeQueue;
    delete graphQueue;
    delete[] colorArr;
    return rootedTree;
}