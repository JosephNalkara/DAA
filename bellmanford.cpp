#include <iostream>
#include <climits> 

using namespace std;


bool bellmanFord(int vertices, int edges, int edgeList[][3], int source) {
    // Step 1: Initialize distances to all vertices as infinite 
    and the source distance to 0
    int distance[vertices];
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;


    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j][0];
            int v = edgeList[j][1];
            int weight = edgeList[j][2];

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
            }
        }
    }

   
    for (int j = 0; j < edges; j++) {
        int u = edgeList[j][0];
        int v = edgeList[j][1];
        int weight = edgeList[j][2];

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            return false;
        }
    }

   
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT_MAX) {
            cout << i << " \t INF" << endl;
        } else {
            cout << i << " \t " << distance[i] << endl;
        }
    }
    return true;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    int edgeList[edges][3];
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    if (bellmanFord(vertices, edges, edgeList, source)) {
        cout << "No negative weight cycle detected." << endl;
    } else {
        cout << "Negative weight cycle detected!" << endl;
    }

    return 0;
}
