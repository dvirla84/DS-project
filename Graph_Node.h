#ifndef DIRECTEDGRAPH_GRAPH_NODE_H
#define DIRECTEDGRAPH_GRAPH_NODE_H

#include "List.h"
#include <cstddef>

class Graph_Node {
private:
    unsigned key;
    List<Graph_Node> Out;
    List<Graph_Node> In;
public:
    bool operator==(Graph_Node t){return (this->key == t.key);}
    unsigned Get_out_Degree() const {return Out.getSize();}
    unsigned Get_in_Degree() const {return In.getSize();}
    unsigned Get_key() const{return key;}

};


#endif //DIRECTEDGRAPH_GRAPH_NODE_H
