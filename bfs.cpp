#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void BFS(int startVertex, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int i = 0; i < adjList[vertex].size(); i++) {
            int neighbor = adjList[vertex][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjList(numVertices);
    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph, add the reverse edge
    }

    vector<bool> visited(numVertices, false);

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << " is: ";
    BFS(startVertex, adjList, visited);
    cout << endl;

    return 0;
}

