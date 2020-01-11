#ifndef DIRECTEDGRAPH_DYNAMIC_GRAPH_H
#define DIRECTEDGRAPH_DYNAMIC_GRAPH_H

#include "List.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2


class Dynamic_Graph {
private:
    List<Graph_Edge*> *_edges;
    List<Graph_Node*> *_nodes;
    unsigned _insertTime;

public:
    Dynamic_Graph();
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    void DFS_visit(List<Graph_Node*>* seq,Graph_Node* u, unsigned* colorArr, Tree_Node* root) const;
    void DFS(List<Graph_Node*>* seq, List<Rooted_Tree*>* connectedComponents) const;
    Rooted_Tree* SCC() const;
    Dynamic_Graph* Transpose() const;
    void BFS_init(unsigned* colorArr, Graph_Node* source, List<Graph_Node*> *graphQueue) const;
    Rooted_Tree* BFS(Graph_Node* source) const;



};


#endif //DIRECTEDGRAPH_DYNAMIC_GRAPH_H
