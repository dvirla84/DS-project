//
// Created by EB on 20/12/2019.
//

#ifndef DIRECTEDGRAPH_NODE_H
#define DIRECTEDGRAPH_NODE_H


class Node {
protected:
    unsigned key;
public:
    bool operator == (Node t){return (this->key == t.key);}
    unsigned Get_key() const{return key;}

};


#endif //DIRECTEDGRAPH_NODE_H
