#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int source, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge edge : graph[u]) {
            int v = edge.to, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);
    
    graph[0] = {{1, 10}, {2, 3}};
    graph[1] = {{3, 2}};
    graph[2] = {{1, 4}, {3, 8}, {4, 2}};
    graph[3] = {{4, 7}};
    graph[4] = {};

    vector<int> dist(V, INT_MAX);
    dijkstra(0, graph, dist);

    for (int i = 0; i < V; i++)
        cout << "Distance from 0 to " << i << ": " << dist[i] << endl;
    return 0;
}
