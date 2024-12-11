#include <iostream>
#include <climits>
using namespace std;


int extractMin(int key[], bool inMST[], int nodes) {
    int minKey = INT_MAX, minIndex = -1;

    for (int i = 0; i < nodes; i++) {
        if (!inMST[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[100][100], int nodes) {
    int parent[100];  
    int key[100];    
    bool inMST[100];  

   
    for (int i = 0; i < nodes; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

   
    key[0] = 0;      
    parent[0] = -1;  

   
    for (int count = 0; count < nodes - 1; count++) {
        
        int u = extractMin(key, inMST, nodes);

       
        inMST[u] = true;

       
        for (int v = 0; v < nodes; v++) {
          
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

  
    cout << "Edge \tWeight\n";
    for (int i = 1; i < nodes; i++) {
        cout << parent[i] << " - " << i << " \t" 
        << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    int graph[100][100];

    cout << "Enter the adjacency matrix of the graph 
    (use 0 for no edge):\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, nodes);

    return 0;
}
