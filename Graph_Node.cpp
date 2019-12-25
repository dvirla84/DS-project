#include "Graph_Node.h"
Graph_Node:: ~Graph_Node()
{
    delete _Out;
    delete _In;
}