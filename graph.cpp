#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"
#include "util.h"
#include <algorithm>

iVertex* createVertex(std::size_t);

class Graph : public iGraph {

    auto findVertex(std::size_t vertexIndex) {
       return std::find_if(std::begin(vertexes), std::end(vertexes), [vertexIndex](auto& vertex) {
            return vertex->getIndex() == vertexIndex;
        });
    }

public:
    void addVertex(std::size_t vertexIndex) {
        if(vertexes.size() == 0) {

            vertexes.push_back(createVertex(vertexIndex));
            return;
        }
       if(findVertex(vertexIndex) == std::end(vertexes)) {

           vertexes.push_back(createVertex(vertexIndex));
       }
       else return;
    }

    void addEdge(std::size_t firstVertex, std::size_t secondVertex) {
        if(firstVertex == secondVertex) {
            isBipartite = false;
            return;
        }

        if(vertexes.size() == 0) {
            addVertex(firstVertex);
        }
       for(int i = 0;i < vertexes.size(); i++ ) {
            addVertex(firstVertex);
            addVertex(secondVertex);

            if(vertexes[i]->getIndex() == firstVertex) {
                    vertexes[i]->addAdjacency(secondVertex);
                    vertexes[this->getVertexIndex(secondVertex)] ->addAdjacency(firstVertex);
                }
        }
    }

     bool checkBipartiteness() {
        std::queue<int> queue;
        vertexes[0] -> setColor(0);
        vertexes[0] -> setVisited();
        queue.push(vertexes[0] -> getIndex());

        while(!queue.empty()) {
            auto& curVertexIndex = queue.front();
            queue.pop();
            int id = getVertexIndex(curVertexIndex);
            auto& adjacencies = vertexes[id] -> getAdjacencies();
            for(int i = 0; i < adjacencies.size(); i++) {
                int adjacentVertex = adjacencies[i];

                int adjId = getVertexIndex(adjacentVertex);
                if(!vertexes[adjId] -> checkVisited()) {
                    vertexes[adjId] -> setVisited();
                    vertexes[adjId] -> setColor(1 - vertexes[getVertexIndex(curVertexIndex)] -> getColor());
                    queue.push(vertexes[adjId] -> getIndex());
                } else if(vertexes[getVertexIndex(curVertexIndex)] -> getColor() == vertexes[adjId] -> getColor()) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() override {
        for(int i = 0; i < vertexes.size(); i++ ) {
            std::cout << vertexes[i]->getIndex()<<std::endl<<"adjastency"<< std::endl;
            vertexes[i]->printAdjacencies();
        }

    }

    int getVertexIndex(int vertexIndex) {
      return  std::distance(std::begin(vertexes),(std::find_if(std::begin(vertexes), std::end(vertexes), [vertexIndex](auto& vertex) {
            return vertexIndex == (vertex -> getIndex());
        })));
    }

    void printVertexes() override {
        for(int i = 0; i < vertexes.size() ; i++) {
            std::cout<< vertexes[i]->getIndex() << std::endl;
        }
    }
    Graph() {}
private:

    std::vector<iVertex*> vertexes;
};

iGraph* createGraph() {
    return new Graph();
}