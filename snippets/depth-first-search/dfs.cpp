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

int main() {
    // Graph g(4);
    // g.AddEdge(0, 1);
    // g.AddEdge(0, 2);
    // g.AddEdge(1, 2);
    // g.AddEdge(2, 0);
    // g.AddEdge(2, 3);
    // g.AddEdge(3, 3);
    // g.Dfs(2);
    // g.DfsRecur(2);
    Graph g(5);
    g.AddEdge(1, 0);
    g.AddEdge(0, 2);
    g.AddEdge(2, 1);
    g.AddEdge(0, 3);
    g.AddEdge(1, 4);
    return 0;
}
