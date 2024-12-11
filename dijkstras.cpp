#include <iostream>
#include <climits>
using namespace std;


void initializeGraph(int adj[100][100], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0; // No edge initially
        }
    }
}


void addEdge(int adj[100][100], int u, int v, int w) {
    adj[u][v] = w; // Directed graph
    // Uncomment the next line for an undirected graph:
    // adj[v][u] = w; 
}


int findMinDistance(int distance[], bool visited[], int V) {
    int minDist = INT_MAX, minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && distance[i] < minDist) {
            minDist = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}


void dijkstra(int adj[100][100], int V, int src) {
    int distance[100];    
    bool visited[100];   
    int predecessor[100];
    
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
        predecessor[i] = -1; 
    }

    distance[src] = 0;

   
    for (int count = 0; count < V - 1; count++) {
       
        int u = findMinDistance(distance, visited, V);
        if (u == -1) break;
        visited[u] = true; 

       
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v] && distance[u] + 
            adj[u][v] < distance[v]) {
                distance[v] = distance[u] + adj[u][v];
                predecessor[v] = u;
            }
        }
    }

    
    cout << "Vertex\tDistance from Source\tPredecessor\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << "\t\t\t";
        if (predecessor[i] == -1) {
            cout << "NIL" << endl;
        } else {
            cout << predecessor[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    if (V > 100) {
        cout << "Maximum number of vertices exceeded. Exiting...\n";
        return 1;
    }

    int adj[100][100];
   
    initializeGraph(adj, V);

    cout << "Enter the number of edges: ";
    cin >> E;

   
    cout << "Enter the edges (u v w) where u and v are 
    vertices (0-based) and w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= V) {
        cout << "Invalid starting vertex. Exiting...\n";
        return 1;
    }

    cout << "Dijkstra's Algorithm starting from vertex " << startVertex << ":\n";
    dijkstra(adj, V, startVertex);

    return 0;
}
