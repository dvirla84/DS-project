#ifndef DIRECTEDGRAPH_GRAPH_EDGE_H
#define DIRECTEDGRAPH_GRAPH_EDGE_H


class Graph_Edge {
private:
    unsigned key_from;
    unsigned key_to;
public:
    unsigned get_from() const{return key_from;}
    unsigned  get_to() const{return key_to;}
};


#endif //DIRECTEDGRAPH_GRAPH_EDGE_H
