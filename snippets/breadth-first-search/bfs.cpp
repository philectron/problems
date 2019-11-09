#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void AddEdge(int src, int dest) {
        adj[src].push_back(dest);
    }

    void AddBiEdge(int u, int v) {
        AddEdge(u, v);
        AddEdge(v, u);
    }

    void Bfs(int src) {
        vector<bool> visited(V, false);
        queue<int> bfs;

        visited[src] = true;
        bfs.push(src);

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();

            cout << v << ' ';  ///

            for (const auto& u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    bfs.push(u);
                }
            }
        }

        cout << endl;  ///
    }
};
