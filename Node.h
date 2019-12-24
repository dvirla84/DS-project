//
// Created by EB on 20/12/2019.
//

#ifndef DIRECTEDGRAPH_NODE_H
#define DIRECTEDGRAPH_NODE_H


class Node {
protected:
    unsigned _key;
public:
    Node (unsigned key):
    _key(key){};
    bool operator == (Node t){return (this->_key == t._key);}
    unsigned Get_key() const{return _key;}
    void setKey(unsigned newKey){_key =newKey;}

};


#endif //DIRECTEDGRAPH_NODE_H
