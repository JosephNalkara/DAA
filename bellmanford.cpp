#include <iostream>
#include <vector>
#include <limits>
#include <tuple>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int source, destination, weight;
};

class Graph {
public:
    int V; // Number of vertices
    vector<Edge> edges;

    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int start) {
        vector<int> distance(V, INF);
        distance[start] = 0;

        for (int i = 1; i < V; i++) {
            for (const auto &edge : edges) {
                if (distance[edge.source] != INF && 
                    distance[edge.source] + edge.weight < distance[edge.destination]) {
                    distance[edge.destination] = distance[edge.source] + edge.weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (const auto &edge : edges) {
            if (distance[edge.source] != INF && 
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }

        printSolution(distance);
    }

    void printSolution(const vector<int> &distance) {
        cout << "Vertex Distance from Source:" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INF) {
                cout << i << "\t\t" << "Infinity" << endl;
            } else {
                cout << i << "\t\t" << distance[i] << endl;
            }
        }
    }
};

int main() {
    int floors = 5; // Number of floors
    Graph g(floors * 10); // Assuming 10 rooms per floor

    
    g.addEdge(0, 10, 5); // From room 0 to room 10 (upstairs)
    g.addEdge(1, 11, 5);
    g.addEdge(10, 20, 3); // Room on floor 1 to room on floor 2
    g.addEdge(2, 12, 4);
    g.addEdge(11, 21, 2);
    g.addEdge(20, 30, 1);
    g.addEdge(21, 31, 2);
    g.addEdge(0, 1, 1);   // Moving between rooms on the same floor
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    // More edges can be added based on the building layout

    int startRoom = 0; // Starting room for evacuation
    g.bellmanFord(startRoom);

    return 0;
}

