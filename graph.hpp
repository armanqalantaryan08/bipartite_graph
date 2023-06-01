#ifndef UNTITLED3_GRAPH_HPP
#define UNTITLED3_GRAPH_HPP
#include "vertex.h"

class iGraph {
public:
virtual void addEdge(std::size_t, std::size_t) = 0;
virtual void print() = 0;
virtual bool checkBipartiteness() = 0;
virtual void printVertexes() = 0;

};
#endif //UNTITLED3_GRAPH_HPP
