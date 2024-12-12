#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
#include <queue>    // For priority_queue

using namespace std;

// Dijkstra's Algorithm to find the shortest path
void dijkstra(int nodes, vector<vector<pair<int, int>>>& adj, int start) {
    // Create a priority queue to store the pair (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a vector to store the shortest distance to each node
    vector<int> dist(nodes, INT_MAX);
    
    // Distance to the start node is 0
    dist[start] = 0;
    pq.push({0, start});  // Push the start node with distance 0

    while (!pq.empty()) {
        // Get the node with the smallest distance
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If this distance is already larger than the current known shortest distance, skip it
        if (d > dist[u]) continue;

        // Check all the neighbors of node u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;     // Neighbor node
            int weight = neighbor.second;  // Edge weight

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the start node
    cout << "Shortest distances from node " << start << " are:\n";
    for (int i = 0; i < nodes; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << " is unreachable.\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
}

// Function to print the adjacency list
void printAdjacencyList(int nodes, const vector<vector<pair<int, int>>>& adj) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < nodes; i++) {
        cout << "Node " << i << ": ";
        for (const auto& neighbor : adj[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << "\n";
    }
}

int main() {
    int nodes, edges, start;

    // Input number of nodes and edges
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adj(nodes);

    cout << "Enter edges (u v weight): \n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // For undirected graph
    }

    // Print the adjacency list
    printAdjacencyList(nodes, adj);

    // Input the starting node
    cout << "Enter the start node: ";
    cin >> start;

    // Call Dijkstra's algorithm
    dijkstra(nodes, adj, start);

    return 0;
}
