class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]

    def add_edge(self, src, dest):
        self.adj[src].append(dest)

    def add_bi_edge(self, u, v):
        self.add_edge(u, v)
        self.add_edge(v, u)

    def dfs(self, src):
        visited = [False for i in range(self.V)]
        dfs = []

        dfs.append(src)

        while len(dfs) > 0:
            v = dfs.pop()

            if not visited[v]:
                visited[v] = True
                print(v, end=' ')  ###

            for u in self.adj[v]:
                if not visited[u]:
                    dfs.append(u)

        print()

    def dfs_recur(self, src):
        visited = [False for i in range(self.V)]
        self.dfs_util(src, visited)
        print()  ###

    def dfs_util(self, v, visited):
        visited[v] = True

        print(v, end=' ')  ###

        for u in self.adj[v]:
            if not visited[u]:
                self.dfs_util(u, visited)
