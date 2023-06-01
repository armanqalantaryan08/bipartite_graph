#include <iostream>
#include "graph.hpp"
#include "util.h"
#include <fstream>

iGraph* createGraph();

bool file_is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

iGraph* buildGraph(std::ifstream& ifstream) {
    int v, u;
    iGraph* graph = createGraph();
    while(!file_is_empty(ifstream)) {
        ifstream >> v >> u;
        if(v > V || u > V) {
            std::cout << "Wrong input" <<std::endl;
            isBipartite = false;
            return graph;
        }

        if(v <= 0 || u <= 0 ) {
            std::cout << "Wrong input" <<std::endl;
            isBipartite = false;
            return graph;
        }
        graph->addEdge(v,u);

    }
    return graph;

};



int main() {
std::ifstream ifstream("input.txt");
    if (ifstream.is_open()) {
        ifstream >> V;
    }
    else {
        std::cout << "The file could not be opened..." << std::endl;
        return -1;
    }

    auto graph =  buildGraph(ifstream);
    graph -> printVertexes();
    graph -> print();

    std::cout<< std::endl;
    if(graph -> checkBipartiteness()) {
        std::cout << "is bipartite" <<std::endl;
    } else {
        std::cout << "not bipartite" <<std::endl;
    }


    return 0;
}
