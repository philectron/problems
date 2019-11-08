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

    void Dfs(int start) {
        vector<bool> visited(V, false);
        stack<int> dfs;

        dfs.push(start);

        while (!dfs.empty()) {
            int v = dfs.top();
            dfs.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << ' ';
            }

            for (const auto& u : adj[v])
                if (!visited[u])
                    dfs.push(u);
        }

        cout << endl;
    }

    void DfsRecur(int start) {
        vector<bool> visited(V, false);
        DfsUtil(start, visited);

        cout << endl;
    }

    void DfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        cout << v << ' ';

        for (const auto& u : adj[v])
            if (!visited[u])
                DfsUtil(u, visited);
    }
};
