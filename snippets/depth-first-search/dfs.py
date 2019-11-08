class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]

    def add_edge(self, v, w):
        self.adj[v].append(w)

    def add_bi_edge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

    def dfs(self, start):
        visited = [False for i in range(self.V)]
        dfs = []

        dfs.append(start)

        while len(dfs) > 0:
            v = dfs.pop()

            if not visited[v]:
                visited[v] = True
                print(v, end=' ')

            for u in self.adj[v]:
                if not visited[u]:
                    dfs.append(u)

        print()

    def dfs_recur(self, start):
        visited = [False for i in range(self.V)]
        self.dfs_util(start, visited)
        print()

    def dfs_util(self, v, visited):
        visited[v] = True

        print(v, end=' ')

        for u in self.adj[v]:
            if not visited[u]:
                self.dfs_util(u, visited)
