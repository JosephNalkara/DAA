#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void DFS(int startVertex, vector<vector<int>>& adjList, vector<bool>& visited) {
    stack<int> s;
    s.push(startVertex);
    visited[startVertex] = true;

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        cout << vertex << " ";

        
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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
        adjList[v].push_back(u);  
        
    }

    vector<bool> visited(numVertices, false);

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS Traversal starting from vertex " << startVertex << " is: ";
    DFS(startVertex, adjList, visited);
    cout << endl;

    return 0;
}
