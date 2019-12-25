#ifndef DIRECTEDGRAPH_DYNAMIC_GRAPH_H
#define DIRECTEDGRAPH_DYNAMIC_GRAPH_H

#include "List.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"

class Dynamic_Graph {
private:
    Graph_Node* _firstNode;
    unsigned _nodesSize;
    Graph_Edge* _firstEdge;
    unsigned _edgesSize;

public:
    Dynamic_Graph();
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;
};


#endif //DIRECTEDGRAPH_DYNAMIC_GRAPH_H
