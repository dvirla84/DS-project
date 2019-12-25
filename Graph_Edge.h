#ifndef DIRECTEDGRAPH_GRAPH_EDGE_H
#define DIRECTEDGRAPH_GRAPH_EDGE_H


class Graph_Edge {
private:
    unsigned _keyFrom;
    unsigned _keyTo;
public:
    Graph_Edge(unsigned from, unsigned to);
    unsigned getFrom() const{return _keyFrom;}
    unsigned  getTo() const{return _keyTo;}
};


#endif //DIRECTEDGRAPH_GRAPH_EDGE_H
