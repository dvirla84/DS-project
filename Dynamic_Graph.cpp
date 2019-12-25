#include "Dynamic_Graph.h"

Dynamic_Graph::  Dynamic_Graph():
_nodes (new List<Graph_Node*>),
_nodesSize(0),
_edgesSize(0),
_edges(new List<Graph_Edge*>)
{}
