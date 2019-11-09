#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    struct Edge {
        int dest;
        int weight;
        Edge(int d, int w) : dest{d}, weight{w} {}
    };

    int V;
    vector<list<Edge>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void AddEdge(int src, int dest, int weight) {
        Edge e(dest, weight);
        adj[src].push_back(e);
    }

    void AddBiEdge(int u, int v, int weight) {
        AddEdge(u, v, weight);
        AddEdge(v, u, weight);
    }

    pair<vector<int>, vector<int>> Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<int> pred(V, -1);
        vector<bool> visited(V, false);

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = MinDistance(dist, visited);
            visited[u] = true;

            for (const auto& edge : adj[u]) {
                if (!visited[edge.dest]) {
                    int d = dist[u] + edge.weight;
                    if (d < dist[edge.dest]) {
                        dist[edge.dest] = d;
                        pred[edge.dest] = u;
                    }
                }
            }
        }

        return make_pair(dist, pred);  ///
    }

    int MinDistance(const vector<int>& dist, const vector<bool>& visited) {
        int min_dist = INT_MAX, min_vertex = 0;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_vertex = v;
            }
        }

        return min_vertex;
    }
};
