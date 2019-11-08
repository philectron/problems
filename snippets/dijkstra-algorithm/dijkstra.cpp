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

    void AddBiEdge(int src, int dest, int weight) {
        AddEdge(src, dest, weight);
        AddEdge(dest, src, weight);
    }

    pair<vector<int>, vector<int>> Dijkstra(int source) {
        vector<int> dist(V, INT_MAX);
        vector<int> prev(V, -1);
        set<int> q;

        for (int v = 0; v < V; v++)
            q.insert(v);

        dist[source] = 0;

        while (!q.empty()) {
            int u = ExtractMin(q, dist);
            q.erase(u);

            for (const auto& edge : adj[u]) {
                if (q.find(edge.dest) != q.end()) {
                    int d = dist[u] + edge.weight;
                    if (d < dist[edge.dest]) {
                        dist[edge.dest] = d;
                        prev[edge.dest] = u;
                    }
                }
            }
        }

        return make_pair(dist, prev);
    }

    int ExtractMin(const set<int>& q, const vector<int>& dist) {
        int min_dist = INT_MAX, min_vertex;

        for (const auto& v : q) {
            if (dist[v] < min_dist) {
                min_dist = dist[v];
                min_vertex = v;
            }
        }

        return min_vertex;
    }
};

// int main() {
//     Graph g(9);
//     g.AddBiEdge(0, 1, 4);
//     g.AddBiEdge(0, 7, 8);
//     g.AddBiEdge(1, 2, 8);
//     g.AddBiEdge(1, 7, 11);
//     g.AddBiEdge(2, 3, 7);
//     g.AddBiEdge(2, 8, 2);
//     g.AddBiEdge(3, 4, 9);
//     g.AddBiEdge(3, 5, 14);
//     g.AddBiEdge(4, 5, 10);
//     g.AddBiEdge(5, 6, 2);
//     g.AddBiEdge(6, 7, 1);
//     g.AddBiEdge(6, 8, 6);
//     g.AddBiEdge(7, 8, 7);
//
//     pair<vector<int>, vector<int>> p = g.Dijkstra(0);
//
//     cout << "dist =";
//     for (const auto& d : p.first) cout << ' ' << d;
//     cout << endl << "prev =";
//     for (const auto& v : p.second) cout << ' ' << v;
//     cout << endl;
// }
