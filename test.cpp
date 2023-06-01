#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    class Vertex {
    public:
        int id;
        std::vector<int> adjacencies;
        bool visited;
        int color;

        Vertex(int vertexId) : id(vertexId), visited(false), color(-1) {}
    };

    std::vector<Vertex> vertices;

public:
    void addVertex(int vertexId) {
        vertices.emplace_back(vertexId);
    }

    void addEdge(int source, int destination) {
        vertices[source].adjacencies.push_back(destination);
        vertices[destination].adjacencies.push_back(source);
    }

    bool bfs(int startVertex) {
        for (auto& vertex : vertices) {
            vertex.visited = false;
            vertex.color = -1;
        }

        std::queue<int> queue;
        vertices[startVertex].visited = true;
        vertices[startVertex].color = 0;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();

            const std::vector<int>& adjacencies = vertices[currentVertex].adjacencies;
            for (int i = 0; i < adjacencies.size(); ++i) {
                int adjacentVertex = adjacencies[i];

                if (!vertices[adjacentVertex].visited) {
                    vertices[adjacentVertex].visited = true;
                    vertices[adjacentVertex].color = 1 - vertices[currentVertex].color;
                    queue.push(adjacentVertex);
                } else if (vertices[adjacentVertex].color == vertices[currentVertex].color) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Graph graph;

    // Adding vertices
    for (int i = 0; i < 6; ++i) {
        graph.addVertex(i);
    }

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    std::cout << "BFS traversal starting from vertex 0: ";
    graph.bfs(0);
    std::cout << std::endl;

    bool isBipartite = graph.bfs(0);
    if (isBipartite) {
        std::cout << "The graph is bipartite." << std::endl;
    } else {
        std::cout << "The graph is not bipartite." << std::endl;
    }

    return 0;
}
