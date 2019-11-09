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

    void Dfs(int src) {
        vector<bool> visited(V, false);
        stack<int> dfs;

        dfs.push(src);

        while (!dfs.empty()) {
            int v = dfs.top();
            dfs.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << ' ';  ///
            }

            for (const auto& u : adj[v])
                if (!visited[u])
                    dfs.push(u);
        }

        cout << endl;  ///
    }

    void DfsRecur(int src) {
        vector<bool> visited(V, false);
        DfsUtil(src, visited);

        cout << endl;  ///
    }

    void DfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        cout << v << ' ';  ///

        for (const auto& u : adj[v])
            if (!visited[u])
                DfsUtil(u, visited);
    }
};
