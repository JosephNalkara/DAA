#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility> 

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};


void printPriorityQueue(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq) {
    cout << "Priority Queue State: ";
    vector<pair<int, int>> elements;
    while (!pq.empty()) {
        elements.push_back(pq.top());
        pq.pop();
    }
    for (const auto& elem : elements) {
        cout << "[" << elem.second << ", " << elem.first << "] ";
    }
    cout << endl;
}


void printDistances(const vector<int>& dist) {
    cout << "Current distances: ";
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    cout << "Initial Priority Queue State: ";
    printPriorityQueue(pq);

    cout << "Initial Distances: ";
    printDistances(dist);

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        cout << "Processing node " << u << " with distance " << d << endl;

        if (d > dist[u]) continue;

     
        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});

                
                cout << "Updated Priority Queue State after adding node " << v << " with distance " << dist[v] << ": ";
                printPriorityQueue(pq);

                
                cout << "Distances after update: ";
                printDistances(dist);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<Edge>> graph(n);

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (from, to, weight) for each edge:\n";
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = dijkstra(start, graph);

    cout << "Final shortest distances from node " << start << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] == INF)
            cout << "Distance to node " << i << " is INF (unreachable)\n";
        else
            cout << "Distance to node " << i << " is " << distances[i] << endl;
    }

    return 0;
}

