#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int>> adj;
    vector<int> pred;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
        pred.resize(V);
    }

    void AddBiEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void Bfs(int src, int dest) {
        vector<bool> visited(V, false);
        queue<int> bfs;

        visited[src] = true;
        bfs.push(src);

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();

            for (const int& u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    bfs.push(u);
                    pred[u] = v;
                    if (u == dest) return;
                }
            }
        }
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;

    Graph g(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g.AddBiEdge(a, b);
    }

    g.Bfs(1, n);

    int count = 0, v = n;
    while (v != 1 && g.pred[v] != 0) {
        count++;
        v = g.pred[v];
    }

    cout << count - 1 << endl;

    return 0;
}
