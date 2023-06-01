#include <vector>
#ifndef UNTITLED3_VERTEX_H
#define UNTITLED3_VERTEX_H

enum class Color {WHITE, BLACK };

struct iVertex {
 virtual int getColor() = 0;
 //virtual void setOpositeColor() = 0;
 virtual void addAdjacency(int) = 0;
 virtual std::size_t getIndex() = 0;
 virtual void printAdjacencies() = 0;
 virtual std::vector<size_t>& getAdjacencies() = 0;
 virtual void setVisited() = 0;
 virtual bool checkVisited() = 0;
 virtual int setColor(int ) = 0;
};
#endif //UNTITLED3_VERTEX_H
