#include <iostream>
#include <algorithm>
#include <iterator>
#include "vertex.h"
#include <vector>
#include <list>

struct Vertex : iVertex {

public:
    Vertex(std::size_t vertexIndex) : vertexIndex(vertexIndex), visited(false) {};

    int getColor() override {
        return this->color;
    }

    void setVisited()  override {
        this->visited = true;
    }

    std::size_t getIndex() override {
        return this->vertexIndex;
    }

   /* void setOpositeColor()  override {
        if(this -> color == Color::BLACK) {
            this -> color = Color::WHITE;
        }
        else
            this -> color = Color::BLACK;
    }*/

   virtual int setColor(int color) override {
       this->color = color;
   }

    virtual bool checkVisited() override {
        return visited;
    }

    void addAdjacency(int index) override {
        if(std::find(std::begin(adjacencies), std::end(adjacencies),index) == std::end(adjacencies)) {
            adjacencies.push_back(index);

        }
    }

    std::vector<size_t>& getAdjacencies() {
        return adjacencies;
    }
    void printAdjacencies() override {

        for(int i = 0; i < adjacencies.size(); i++ ) {
            std::cout<<" " << adjacencies[i] ;
        }
        std::cout<<std::endl;
    }

private:
    std::size_t vertexIndex;
    int color;
    bool visited;
    std::vector<std::size_t> adjacencies;
};

iVertex* createVertex(std::size_t vertexIndex) {
    iVertex* vertex  = new Vertex(vertexIndex);
    return vertex;
};
