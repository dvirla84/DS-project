#ifndef DIRECTEDGRAPH_DYNAMIC_GRAPH_H
#define DIRECTEDGRAPH_DYNAMIC_GRAPH_H

#include "List.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "BFS_Aux_Info.h"

class Dynamic_Graph {
private:
    List<Graph_Edge*> *_edges;
    List<Graph_Node*> *_nodes;


public:
    Dynamic_Graph();
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    void BFS_init(BFS_Aux_Info** infoArr, Graph_Node* source);
    Rooted_Tree* BFS(Graph_Node* source) const;


};


#endif //DIRECTEDGRAPH_DYNAMIC_GRAPH_H
