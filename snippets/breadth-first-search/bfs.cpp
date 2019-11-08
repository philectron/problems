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

    void AddEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void AddBiEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void Bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> bfs;

        visited[start] = true;
        bfs.push(start);

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();

            cout << v << ' ';

            for (const auto& u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    bfs.push(u);
                }
            }
        }

        cout << endl;
    }
};
